#include "common.h"

// language, see patch_setlocale.c for details
UINT system_codepage;
UINT target_codepage;


static const wchar_t wstr_about_title_CHS[] = L"����";
static const wchar_t wstr_about_text_CHS[] = 
    L"��ӭʹ�á��ɽ������������ֱ��ʲ��� %hs\n" 
    L"\n"
    L"����������������Ϸ�ķֱ���\n"
    L"ͬʱ�޸�һЩ��Ϸ�����С����\n"
    L"���������һЩʵ�õ�С����\n" 
    L"��ϸ��Ϣ��ʹ�÷�����μ�����˵���ļ�\n"
    L"\n"
    L"\n"
    L"���������ÿ������ʱ��������Ϣ\n"
    L"��ʹ�ò������ù��ߣ�������ʾ���ڡ���Ϊ�����á�\n" 
    L"\n"
    L"\n"
    L"������վ:\n"
    L"  https://pal3.zbyzbyzby.com\n"
    L"\n"
    L"������Ϣ:\n%hs"
;

static const wchar_t wstr_confirmquit_text_CHS[] = L"��ȷ��Ҫ�˳���Ϸ��\nδ�������Ϸ���Ƚ��ᶪʧ��";
static const wchar_t wstr_confirmquit_title_CHS[] = L"�˳�";

static const wchar_t wstr_defaultfont_CHS[] = L"����";
static const wchar_t wstr_gameloading_CHS[] = L"��Ϸ�����У����Ժ򡭡�";

const wchar_t *wstr_about_title;
const wchar_t *wstr_about_text;
const wchar_t *wstr_confirmquit_text;
const wchar_t *wstr_confirmquit_title;
const wchar_t *wstr_defaultfont;
const wchar_t *wstr_gameloading;



void init_locale()
{
    // no translations yet
    wstr_about_title = wstr_about_title_CHS;
    wstr_about_text = wstr_about_text_CHS;
    wstr_confirmquit_text = wstr_confirmquit_text_CHS;
    wstr_confirmquit_title = wstr_confirmquit_title_CHS;
    wstr_defaultfont = wstr_defaultfont_CHS;
    wstr_gameloading = wstr_gameloading_CHS;
}
