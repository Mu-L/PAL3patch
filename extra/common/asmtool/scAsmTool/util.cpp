#include "common.h"

const char built_on[] = __DATE__ " " __TIME__;

size_t _safe_fread(void *ptr, size_t size, size_t nmemb, FILE *stream, const char *msg)
{
	size_t r = fread(ptr, size, nmemb, stream);
	if (r != nmemb) {
		scAsmTool::ReportError(LVL_FATAL, "�������� %s ʧ�ܣ�����ֵ %lu��", msg, (unsigned long)r);
	}
	return r;
}

int _safe_fseek(FILE *stream, long offset, int whence, const char *msg)
{
	int r = fseek(stream, offset, whence);
	if (r != 0) {
		scAsmTool::ReportError(LVL_FATAL, "�������� %s ʧ�ܣ�����ֵ %d��", msg, r);
	}
	return r;
}

FILE *safe_fopen(const char *path, const char *mode)
{
	FILE *r = fopen(path, mode);
	if (!r) {
		scAsmTool::ReportError(LVL_FATAL, "�޷���ģʽ '%s' ���ļ� '%s'", mode, path);
	}
	return r;
}

std::string escape_string(const std::string &str)
{
	std::string ret(str);
	assert(strchr(str.c_str(), quote_escape) == NULL);
	std::replace(ret.begin(), ret.end(), '\"', quote_escape);;
	return ret;
}



const char *getpathfilepart(const char *path)
{
	if (strrchr(path, '\\')) path = strrchr(path, '\\') + 1;
	if (strrchr(path, '/')) path = strrchr(path, '/') + 1;
	return path;
}