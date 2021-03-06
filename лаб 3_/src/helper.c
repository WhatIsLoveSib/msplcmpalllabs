#include "helper.h"
#include "terminal.h"
#include "bigchars.h"


int changeSizeTerm()
{
	int size_console_x;
	int size_console_y;

	if (mt_getscreensize(&size_console_y, &size_console_x) != 0) {
		printf("Error\n");
		return -1;
	}

	if (size_console_x < 85 || size_console_y < 46) {
		printf("\033[8;45;84t");
	}

	mt_clrscr(); 
	mt_gotoXY(1, 1);

	return 0;
}

int printMemory()
{
	if (bc_box(1, 1, 63, 13) != 0) {
		return -1;
	}

	mt_gotoXY(1, 28);
	printf("Memory");
	sm_printMemory(2, 2);


	return 0;
}

int printAccumalte()
{
	if (bc_box(63, 1, 84, 4) != 0) {
		return -1;
	}

	mt_gotoXY(1, 68);
	printf("Accumulator");
	mt_gotoXY(2, 70);
	printf("+0000");

	return 0;
}

int printInstCounter()
{
	if (bc_box(63, 4, 84, 7) != 0) {
		return -1;
	}

	mt_gotoXY(4, 64);
	printf("InstructionCounter");
	mt_gotoXY(5, 70);
	printf("+0000");

	return 0;
}

int printOperation()
{
	if (bc_box(63, 7, 84, 10) != 0) {
		return -1;
	}

	mt_gotoXY(7, 69);
	printf("Operation");
	mt_gotoXY(8, 69);
	printf("+00 : 00");

	return 0;
}

int printFlags()
{
	if (bc_box(63, 10, 84, 13) != 0) {
		return -1;
	}

	mt_gotoXY(10, 71);
	printf("Flags");
	mt_gotoXY(11, 64);
	int _OD;
	sc_regGet(OD, &_OD);
	int _DE;
	sc_regGet(OD, &_DE);
	int _EG;
	sc_regGet(OD, &_EG);
	int _CI;
	sc_regGet(OD, &_CI);
	int _IC;
	sc_regGet(OD, &_IC);
	printf("D-%d E-%d G-%d I-%d C-%d", _OD, _DE >> 1, _EG >> 2, _CI >> 3, _IC >> 4);

	return 0;
}

int printBoxBC()
{
	if (bc_box(1, 13, 63, 23) != 0) {
		return -1;
	}

	int chr[2];
	chr[0] = bc_Plus(0);
	chr[1] = bc_Plus(1);
	bc_printbigchar(chr, 4, 14, 2, 0);

	chr[0] = bc_Null(0);
	chr[1] = bc_Null(1);
	bc_printbigchar(chr, 19, 14, 2, 0);

	chr[0] = bc_Null(0);
	chr[1] = bc_Null(1);
	bc_printbigchar(chr, 30, 14, 2, 0);

	chr[0] = bc_Null(0);
	chr[1] = bc_Null(1);
	bc_printbigchar(chr, 41, 14, 2, 0);

	chr[0] = bc_Null(0);
	chr[1] = bc_Null(1);
	bc_printbigchar(chr, 52, 14, 2, 0);


	return 0;
}

int printHelpBox()
{
	if (bc_box(63, 13, 84, 23) != 0) {
		return -1;
	}

	mt_gotoXY(13, 64);
	printf("Keys:");
	mt_gotoXY(14, 64);
	printf("l - load");
	mt_gotoXY(14, 64);
	printf("s - save");
	mt_gotoXY(15, 64);
	printf("r - run");
	mt_gotoXY(16, 64);
	printf("t - step");
	mt_gotoXY(17, 64);
	printf("i - reset");
	mt_gotoXY(18, 64);
	printf("F5 - accumulator");
	mt_gotoXY(19, 64);
	printf("F6 - instrCounter");

	return 0;
}

int teminalInterface(int size, int mem, int acc, int insCoun, int oper, int fl, int bc, int h)
{
	if (size) {
		changeSizeTerm();
	}

	if (mem) {
		if (printMemory()) {
			return -1;
		}
	}
	
	if (acc) {
		if (printAccumalte()) {
			return -1;
		}
	}
	
	if (insCoun) {
		if (printInstCounter()) {
			return -1;
		}
	}
	
	if (oper) {
		if (printOperation()) {
			return -1;
		}
	}
	
	if (fl) {
		if (printFlags()) {
			return -1;
		}
	}
	
	if (bc) {
		if (printBoxBC()) {
			return -1;
		}
	}
	
	if (h) {
		if (printHelpBox()) {
			return -1;
		}
	}

	mt_gotoXY(26, 1);

	return 0;
}

