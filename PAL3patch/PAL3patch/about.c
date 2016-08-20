#include <stdio.h>
#include <windows.h>
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

void show_about()
{
    int flag = get_int_from_configfile("showabout");
    if (flag) {
        wchar_t buf[MAXLINE];
        snwprintf(buf, sizeof(buf) / sizeof(wchar_t), 
            L"��ӭʹ�á��ɽ�������������ǿ���� %hs\n" 
            L"\n"
            L"�����������޸�һЩ��Ϸ�����С����\n"
            L"���������һЩʵ�õ�С����\n" 
            L"��ϸ��Ϣ��ʹ�÷�����μ� PAL3patch_README.txt\n" 
            L"\n"
            L"\n"
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
            , PAL3PATCH_VERSION, build_info, CONFIG_FILE, flag); 
            
            
        MessageBoxW(NULL, buf, L"����", MB_ICONINFORMATION | MB_SETFOREGROUND); 
    }
}

