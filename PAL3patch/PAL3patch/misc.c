// misc functions
#include <stdio.h>
#include <string.h>
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

void __fail(const char *file, int line, const char *func, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    char buf[MAXLINE];
    int len;
    snprintf(buf, sizeof(buf), "  file: %s\n  line: %d\n  func: %s\nmessage:\n  ", file, line, func);
    len = strlen(buf);
    vsnprintf(buf + len, sizeof(buf) - len, fmt, ap);
    OutputDebugString(buf);
    FILE *fp = fopen(ERROR_FILE, "w");
    if (fp) {
        fputs("build information:\n", fp);
        fputs(build_info, fp);
        fputs("error details:\n", fp);
        fputs(buf, fp);
        fputc('\n', fp);
        fclose(fp);
    }
    MessageBoxA(NULL, buf + len, NULL, MB_ICONERROR);
    TerminateProcess(GetCurrentProcess(), 1);
    va_end(ap);
}
