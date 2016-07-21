#include <windows.h>
#include <stdio.h>
#include <assert.h>
#include "common.h"

const char build_info[] =
    "  built on: " __DATE__ ", " __TIME__ "\n"
    "  compiler: "
#if defined(__GNUC__) && defined(__VERSION__)
        "gcc " __VERSION__
#else
        "unknown C compiler"
#endif
    "\n";


static void show_about()
{
    int flag = get_int_from_configfile("showabout");
    if (flag) {
        char cfgbuf[MAXLINE];
        get_all_config(cfgbuf, sizeof(cfgbuf));
        wchar_t buf[MAXLINE];
        snwprintf(buf, sizeof(buf) / sizeof(wchar_t), 
            L"��ӭʹ�á��ɽ�������������ǿ����\n"
            L"\n"
            L"�����������޸�һЩ��Ϸ�����д������ĵط�\n"
            L"���������һЩʵ�õ�С����\n" 
            L"��ϸ��Ϣ��ʹ�÷�����μ� PAL3patch_README.txt\n" 
            L"\n"
            L"\n"
            L"����ѡ��:\n%hs" 
            L"Դ����:\n"
            L"  https://github.com/zhangboyang/PAL3patch\n"
            L"������Ϣ:\n%hs"
            L"\n"
            L"\n"
            L"���������ÿ������ʱ��������Ϣ\n"
            L"�뽫�����ļ� %hs �е�\n"
            L"  showabout=%d\n"
            L"�޸�Ϊ\n"
            L"  showabout=0\n"
            L"\n"
            , cfgbuf, build_info, CONFIG_FILE, flag); 
            
            
        MessageBoxW(NULL, buf, L"����", MB_ICONINFORMATION); 
    }
}

static void init_patch()
{
    read_config_file();
    
    show_about();
    
    INIT_PATCHSET(cdpatch);
    INIT_PATCHSET(regredirect);
    INIT_PATCHSET(disablekbdhook);
    
    if (!INIT_PATCHSET(testcombat)) {
        // here are some patches not compatiable with 'testcombat'
    }
}






// patch unpacker code, let it call init_patch() after unpacking
static void patch_unpacker(unsigned unpacker_base)
{
    // there is a RETN and many NOPs at end of unpacking code
    // so replace this RETN with a JMP to our init_patch()
    // p.s. since the unpacker destoryed the register values PUSHADed
    //      we doesn't care about it, either
    unsigned jmpaddr = unpacker_base + 0x57d1;
    check_code(jmpaddr, "\xC3\x90\x90\x90\x90", 5);
    make_jmp(jmpaddr, init_patch);
}


// this function will be called immediately after DLL is injected by launcher
void launcher_entry(unsigned oep_addr)
{
    unsigned unpacker_base = (unsigned) GetModuleHandle("PAL3.DLL");
    if (unpacker_base) {
        // unpacker exists and not executed
        // we should call init_patch() when after unpacking
        patch_unpacker(unpacker_base);
    } else {
        // no unpacker exists
        init_patch();
    }
}

// fix unpacker entry for Windows 98
// see notes20160721.txt for details
static int try_fix_unpacker()
{
    const unsigned fileoffset = 0x2c6;
    const unsigned char oldcode[] = "\x83\x7C\x24\x08\x01\x75\x10\x8B\x44\x24\x04";
    const unsigned char newcode[] = "\x59\x58\x5A\x83\xFA\x01\x5A\x51\x75\x0D\x90";
    unsigned char buf[sizeof(oldcode) - 1];
    if (!CopyFile(EXTERNAL_UNPACKER, EXTERNAL_UNPACKER_FIXED, FALSE)) return 0;
    FILE *fp = fopen(EXTERNAL_UNPACKER_FIXED, "r+b");
    if (!fp) return 0;
    if (fseek(fp, fileoffset, SEEK_SET) != 0) goto fail;
    if (fread(buf, 1, sizeof(buf), fp) != sizeof(buf)) goto fail;
    if (memcmp(buf, oldcode, sizeof(oldcode) - 1) != 0) goto fail;
    if (fseek(fp, fileoffset, SEEK_SET) != 0) goto fail;
    if (fwrite(newcode, 1, sizeof(newcode) - 1, fp) != sizeof(newcode) - 1) goto fail;
    fclose(fp);
    return 1;
fail:
    fclose(fp);
    return 0;
}

unsigned sforce_unpacker_init()
{
    // our DLL is loaded as fake unpacker
    // we should load the real unpack, patch it, and execute it
    HMODULE unpacker = LoadLibrary(EXTERNAL_UNPACKER);
    if (!unpacker && try_fix_unpacker()) unpacker = LoadLibrary(EXTERNAL_UNPACKER_FIXED);
    if (!unpacker) fail("Can't load unpacker.");
    patch_unpacker((unsigned) unpacker);
    
    // we should return unpacker entry address to out asm code
    return (unsigned) GetProcAddress(unpacker, (LPCSTR) 1);
}
