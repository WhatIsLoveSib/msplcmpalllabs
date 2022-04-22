#ifndef HELPER_H
#define HELPER_H

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

int cell;

int intToHex(int number, char *str);
void initNumberCell();
void printCell();
int printBigCharInBox();

#endif