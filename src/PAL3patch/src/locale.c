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

static const char ftfont_filename_CHS[] = "simsun.ttc";
static const int ftfont_index_CHS = 0;
static const int defaultfont_bold_CHS = 48;

static const wchar_t wstr_defaultfont_CHS[] = L"����";
static const wchar_t wstr_gameloading_CHS[] = L"��Ϸ�����У����Ժ򡭡�";

static const wchar_t wstr_cantsavereg_text_CHS[] = L"�޷�����ע������ݵ��浵�ļ��У����ִ浵���ݿ��ܻᶪʧ��\n��ȷ����Ϸ�Դ浵�ļ����п�дȨ�ޡ�";
static const wchar_t wstr_cantsavereg_title_CHS[] = L"ע����ض���";

static const wchar_t wstr_nocfgfile_text_CHS[] = L"�޷���ȡ���������ļ��������С��������ù��ߡ�������Ĭ�������ļ���";
static const wchar_t wstr_nocfgfile_title_CHS[] = L"�޷���������";

static const wchar_t wstr_badcfgfile_text_CHS[] = L"���������ļ��𻵡������С��������ù��ߡ���ʹ�á��ָ�Ĭ�����á���������д�����ļ���";
static const wchar_t wstr_badcfgfile_title_CHS[] = L"�޷���������";



// CHT
static const char ftfont_filename_CHT[] = "mingliu.ttc";
static const int ftfont_index_CHT = 0;
static const int defaultfont_bold_CHT = 32;

static const wchar_t wstr_defaultfont_CHT[] = L"�����w";

// FIXME: add more translate




// string pointers

const wchar_t *wstr_about_title;
const wchar_t *wstr_about_text;
const wchar_t *wstr_confirmquit_text;
const wchar_t *wstr_confirmquit_title;
const char *ftfont_filename;
int ftfont_index;
const wchar_t *wstr_defaultfont;
DWORD defaultfont_charset;
int defaultfont_bold;
const wchar_t *wstr_gameloading;
const wchar_t *wstr_cantsavereg_text;
const wchar_t *wstr_cantsavereg_title;
const wchar_t *wstr_nocfgfile_text;
const wchar_t *wstr_nocfgfile_title;
const wchar_t *wstr_badcfgfile_text;
const wchar_t *wstr_badcfgfile_title;




void init_locale_early()
{
    // init codepage
    // PATCHSET 'setlocale' may overwrite target_codepage
    target_codepage = system_codepage = GetACP();
    
    // init early strings
    wstr_nocfgfile_text = wstr_nocfgfile_text_CHS;
    wstr_nocfgfile_title = wstr_nocfgfile_title_CHS;
    wstr_badcfgfile_text = wstr_badcfgfile_text_CHS;
    wstr_badcfgfile_title = wstr_badcfgfile_title_CHS;
        
    if (target_codepage == 950) { // CHT
    }
}

void init_locale()
{
    // no translations yet
    wstr_about_title = wstr_about_title_CHS;
    wstr_about_text = wstr_about_text_CHS;
    wstr_confirmquit_text = wstr_confirmquit_text_CHS;
    wstr_confirmquit_title = wstr_confirmquit_title_CHS;
    ftfont_filename = ftfont_filename_CHS;
    ftfont_index = ftfont_index_CHS;
    wstr_defaultfont = wstr_defaultfont_CHS;
    defaultfont_charset = GB2312_CHARSET;
    defaultfont_bold = defaultfont_bold_CHS;
    wstr_gameloading = wstr_gameloading_CHS;
    wstr_cantsavereg_text = wstr_cantsavereg_text_CHS;
    wstr_cantsavereg_title = wstr_cantsavereg_title_CHS;

    if (target_codepage == 950) { // CHT
        ftfont_filename = ftfont_filename_CHT;
        ftfont_index = ftfont_index_CHT;
        wstr_defaultfont = wstr_defaultfont_CHT;
        defaultfont_charset = CHINESEBIG5_CHARSET;
        defaultfont_bold = defaultfont_bold_CHT;
    }
}
