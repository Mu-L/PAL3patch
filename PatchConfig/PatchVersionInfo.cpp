#include "stdafx.h"
#include "PatchVersionInfo.h"


#define PATCH_VERSION "v1.0 alpha"
#define PATCH_VERSION_WSTR _T(PATCH_VERSION)


const TCHAR pWelcomeMessage_CHS[] = 
	_T("��ӭʹ�á��ɽ�������������ǿ���� ") PATCH_VERSION_WSTR _T("\r\n")
	_T("�����������޸�һЩ��Ϸ�����С���⣬\r\n")
	_T("���������һЩʵ�õ�С���ܡ�\r\n")
	_T("��ϸ��Ϣ��ʹ�÷�����μ�����˵���ļ���")
;

LPCTSTR pWelcomeMessage = pWelcomeMessage_CHS;

const char pBuildDate[] = __DATE__ ", " __TIME__;
const char pVersionStr[] = PATCH_VERSION;

const char *pFileHash[] = {
	// filename, sha1 hash,
	"PAL3.EXE",     "05e1cbd148957dfb635d291c13f19105133ba875",
	"GBENGINE.DLL", "ead9bba8ce18fb68f111c1cb1edbf30ddb78b367",
	// EOF
	NULL,
};
