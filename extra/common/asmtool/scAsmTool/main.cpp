#include "common.h"

int main(int argc, char *argv[])
{
	printf("  scAsmTool ����/���� SCE �����/��๤�� by ZBY (%s)\n\n", built_on);

	scAsmTool::cmdline.clear();
	for (int i = 0; i < argc; i++) {
		if (i > 0) scAsmTool::cmdline += " ";
		scAsmTool::cmdline += argv[i];
	}

	if (argc < 5) goto usage;

	if (argc >= 6 && stricmp(argv[5], "/DBG") == 0) {
		scAsmTool::dbgflag = true;
	}

	if (stricmp(argv[1], "/3") == 0) {
		InitCmdDef_PAL3();
	} else if (stricmp(argv[1], "/3A") == 0) {
		InitCmdDef_PAL3A();
	} else {
		goto usage;
	}

	if (stricmp(argv[2], "/D") == 0) {
		scAsmDisassembler::Instance()->DisassembleSCE(argv[3], argv[4]);
	} else if (stricmp(argv[2], "/A") == 0) {
		scAsmAssembler::Instance()->AssembleSCE(argv[3], argv[4]);
	} else if (stricmp(argv[2], "/T") == 0) {
		scAsmAssembler::Instance()->AssembleSCETest(argv[3], argv[4]);
	} else {
		goto usage;
	}

	scAsmTool::die(0);

usage:
	printf(" �����и�ʽ��\n");
	printf("  scAsmTool [/3|/3A] [/D|/A] [�ļ�X] [�ļ�Y] [/DBG]\n");
	printf("\n");
	printf(" �汾ѡ�\n");
	printf("  /3     ʹ������ָ���\n");
	printf("  /3A    ʹ������ָ���\n");
	printf("\n");
	printf(" ����ѡ�\n");
	printf("  /D     �����ģʽ���� X �����Ϊ Y��\n");
	printf("  /A     ���ģʽ���� X ���Ϊ Y��\n");
	printf("  /T     ����ģʽ������ Y ������Ƿ� X ��ͬ�����Ḳ���ļ���\n");
	printf("\n");
	printf(" ����ѡ�\n");
	printf("  /DBG   ���������Ϣ\n");
	printf("\n");
	
	printf(" ����ʵ�����˵�������� C ���Ե�Ԥ����ָ�\n");
	printf("    ע�⣺ֻ���ڽű��飨�� #begin �� #end Χ�ɵ���������ʹ�ã�\n");
	printf("    #include \"foobar.asm\"   ������һ�ļ�\n");
	printf("    #define X Y             ����� X �滻Ϊ Y\n");

	printf("\n");
	scAsmTool::die(1);
}