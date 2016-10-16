#include "common.h"

// language, see patch_setlocale.c for details
UINT system_codepage;
UINT target_codepage;


static const wchar_t wstr_about_title_CHS[] = L"����";
static const wchar_t wstr_about_text_CHS[] = 
    L"��ӭʹ�á��ɽ�������������ǿ���� %hs\n" 
    L"\n"
    L"�����������޸�һЩ��Ϸ�����С����\n"
    L"���������һЩʵ�õ�С����\n" 
    L"��ϸ��Ϣ��ʹ�÷�����μ�����˵���ļ�\n"
    L"\n"
    L"\n"
    L"���������ÿ������ʱ��������Ϣ\n"
    L"��ʹ�ò������ù��ߣ�������ʾ���ڡ���Ϊ�����á�\n" 
    L"\n"
    L"\n"
    L"Դ����:\n"
    L"  https://github.com/zhangboyang/PAL3patch\n"
    L"������Ϣ:\n%hs"
;
static const wchar_t wstr_confirmquit_text_CHS[] = L"��ȷ��Ҫ�˳���Ϸ��\nδ�������Ϸ���Ƚ��ᶪʧ��";
static const wchar_t wstr_confirmquit_title_CHS[] = L"�˳�";


const wchar_t *wstr_about_title = wstr_about_title_CHS;
const wchar_t *wstr_about_text = wstr_about_text_CHS;
const wchar_t *wstr_confirmquit_text = wstr_confirmquit_text_CHS;
const wchar_t *wstr_confirmquit_title = wstr_confirmquit_title_CHS;


void init_locale()
{
    // no translations yet
}
