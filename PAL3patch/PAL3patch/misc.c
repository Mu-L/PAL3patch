// misc functions
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "common.h"




int str2int(const char *valstr)
{
    int result, ret;
    ret = sscanf(valstr, "%d", &result);
    if (ret != 1) fail("can't parse '%s' to integer.", valstr);
    return result;
}

double str2double(const char *valstr)
{
    int ret;
    double result;
    ret = sscanf(valstr, "%lf", &result);
    if (ret != 1) fail("can't parse '%s' to double.", valstr);
    return result;
}



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
            L"��ӭʹ�á��ɽ�������������ǿ����\n"
            L"\n"
            L"�����������޸�һЩ��Ϸ�����д������ĵط�\n"
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
            , build_info, CONFIG_FILE, flag); 
            
            
        MessageBoxW(NULL, buf, L"����", MB_ICONINFORMATION); 
    }
}

void __attribute__((noreturn)) __fail(const char *file, int line, const char *func, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    char buf[MAXLINE];
    char msgbuf[MAXLINE];
    int len;
    snprintf(msgbuf, sizeof(msgbuf), "  file: %s\n  line: %d\n  func: %s\nmessage:\n  ", file, line, func);
    len = strlen(msgbuf);
    vsnprintf(msgbuf + len, sizeof(msgbuf) - len, fmt, ap);
    OutputDebugString(msgbuf);
    FILE *fp = fopen(ERROR_FILE, "w");
    if (fp) {
        fputs("build information:\n", fp);
        fputs(build_info, fp);
        
        get_all_config(buf, sizeof(buf));
        fputs("patch configuration:\n", fp);
        fputs(buf, fp);
        
        SYSTEMTIME SystemTime;
        GetLocalTime(&SystemTime);
        snprintf(buf, sizeof(buf), "  %04hd-%02hd-%02hd %02hd:%02hd:%02hd.%03hd\n", SystemTime.wYear, SystemTime.wMonth, SystemTime.wDay, SystemTime.wHour, SystemTime.wMinute, SystemTime.wSecond, SystemTime.wMilliseconds);
        fputs("timestamp:\n", fp);
        fputs(buf, fp);
        
        fputs("error details:\n", fp);
        fputs(msgbuf, fp);
        fputc('\n', fp);
        fclose(fp);
    }
    MessageBoxA(NULL, msgbuf + len, "PAL3patch", MB_ICONERROR);
    TerminateProcess(GetCurrentProcess(), 1);
    while (1);
    va_end(ap);
}

void __warning(const char *file, int line, const char *func, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    char buf[MAXLINE];
    char msgbuf[MAXLINE];
    int len;
    snprintf(msgbuf, sizeof(msgbuf), "  file: %s\n  line: %d\n  func: %s\nmessage:\n  ", file, line, func);
    len = strlen(msgbuf);
    vsnprintf(msgbuf + len, sizeof(msgbuf) - len, fmt, ap);
    OutputDebugString(msgbuf);
    FILE *fp = fopen(WARNING_FILE, "a");
    if (fp) {
        fputs("build information:\n", fp);
        fputs(build_info, fp);
        
        get_all_config(buf, sizeof(buf));
        fputs("patch configuration:\n", fp);
        fputs(buf, fp);
        
        SYSTEMTIME SystemTime;
        GetLocalTime(&SystemTime);
        snprintf(buf, sizeof(buf), "  %04hd-%02hd-%02hd %02hd:%02hd:%02hd.%03hd\n", SystemTime.wYear, SystemTime.wMonth, SystemTime.wDay, SystemTime.wHour, SystemTime.wMinute, SystemTime.wSecond, SystemTime.wMilliseconds);
        fputs("timestamp:\n", fp);
        fputs(buf, fp);
        
        fputs("warning details:\n", fp);
        fputs(msgbuf, fp);
        fputs("\n\n\n", fp);
        fclose(fp);
    }
    MessageBoxA(NULL, msgbuf + len, "PAL3patch", MB_ICONWARNING);
    va_end(ap);
}
