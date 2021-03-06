#ifndef HELPER_H
#define HELPER_H

#include "myReadKey.h"

int changeSizeTerm();
void load();
int printMemory();
int printAccumalte();
int printInstCounter();
int printOperation();
int printFlags();
int printBoxBC();
int printHelpBox();
int teminalInterface(int size, int mem, int acc, int insCoun, int oper, int fl, int bc, int h);

enum way {
	way_UP, way_DOWN, way_LEFT, way_RIGHT, way_DEFAULT
};

int cell;

int intToHex(int number, char *str);
void initNumberCell();
void printCell();
int printBigCharInBox();
void selectCellMemory(enum way w);

#endif