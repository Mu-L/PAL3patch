#include "common.h"

// language, see patch_setlocale.c for details
unsigned system_codepage;
unsigned target_codepage;



// CHS
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

static const wchar_t wstr_cantsavereg_text_CHS[] = L"�޷�����ע������ݵ��浵�ļ��У����ִ浵���ݿ��ܻᶪʧ��\n��ȷ����Ϸ�Դ浵�ļ����п�дȨ�ޡ�";
static const wchar_t wstr_cantsavereg_title_CHS[] = L"ע����ض���";

static const wchar_t wstr_nocfgfile_text_CHS[] = L"�޷���ȡ���������ļ��������С��������ù��ߡ�������Ĭ�������ļ���";
static const wchar_t wstr_nocfgfile_title_CHS[] = L"�޷���������";



// CHT

static const wchar_t wstr_defaultfont_CHT[] = L"�����w";




// string pointers

const wchar_t *wstr_about_title;
const wchar_t *wstr_about_text;
const wchar_t *wstr_confirmquit_text;
const wchar_t *wstr_confirmquit_title;
const wchar_t *wstr_defaultfont;
const wchar_t *wstr_gameloading;
const wchar_t *wstr_cantsavereg_text;
const wchar_t *wstr_cantsavereg_title;
const wchar_t *wstr_nocfgfile_text;
const wchar_t *wstr_nocfgfile_title;





void init_locale_early()
{
    // init codepage
    // PATCHSET 'setlocale' may overwrite target_codepage
    target_codepage = system_codepage = GetACP();
    
    // init early strings
    wstr_nocfgfile_text = wstr_nocfgfile_text_CHS;
    wstr_nocfgfile_title = wstr_nocfgfile_title_CHS;
}

void init_locale()
{
    // no translations yet
    wstr_about_title = wstr_about_title_CHS;
    wstr_about_text = wstr_about_text_CHS;
    wstr_confirmquit_text = wstr_confirmquit_text_CHS;
    wstr_confirmquit_title = wstr_confirmquit_title_CHS;
    wstr_defaultfont = wstr_defaultfont_CHS;
    wstr_gameloading = wstr_gameloading_CHS;
    wstr_cantsavereg_text = wstr_cantsavereg_text_CHS;
    wstr_cantsavereg_title = wstr_cantsavereg_title_CHS;

    if (target_codepage == 950) { // CHT
        wstr_defaultfont = wstr_defaultfont_CHT;
    }
}
