#ifndef TERMINAL_H
#define TERMINAL_H

#define _GNU_SOURCE
#define D_DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

enum colors {
	black = 0,
	red = 1,
	green = 2,
	yellow = 3,
	blue = 4,
	purple = 5,
	cyan = 6,
	white = 7
};

int mt_clrscr();
int mt_gotoXY(int y, int x);
int mt_getscreensize(int *rows, int *cols);
int mt_ssetfgcolor(enum colors color);
int mt_ssetbgcolor(enum colors color);
int mt_stopcolor();

#endif
