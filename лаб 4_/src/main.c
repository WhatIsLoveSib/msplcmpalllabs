// #include "bigchars.h"
// #include "myReadKey.h"
#include "helper.h"

int main()
{
	sc_memoryInit();
	sc_memorySet(5, 44);
	sc_memorySet(6, 785);
	initNumberCell();
	teminalInterface(1, 1, 1, 1, 1, 1, 1, 1);

	enum keys key;
	enum way w;
	w = way_DEFAULT;
	selectCellMemory(w);

	while (1) {
		rk_readKey(&key);
		if (key == UP) {
			w = way_UP;
			selectCellMemory(w);
		}
		if (key == LEFT) {
			w = way_LEFT;
			selectCellMemory(w);
		}
		if (key == DOWN) {
			w = way_DOWN;
			selectCellMemory(w);
		}
		if (key == RIGHT) {
			w = way_RIGHT;
			selectCellMemory(w);
		}
		if (key == 'q') {
			break;
		}

		if (key >= 0 && key < 10) {
			ptr_str[cell] += key;
			w = way_DEFAULT;
			selectCellMemory(w);
		}
		if (key == 'a') {
			ptr_str[cell] += 10;
			w = way_DEFAULT;
			selectCellMemory(w);
		}
		if (key == 'b') {
			ptr_str[cell] += 11;
			w = way_DEFAULT;
			selectCellMemory(w);
		}
		if (key == 'c') {
			ptr_str[cell] += 12;
			w = way_DEFAULT;
			selectCellMemory(w);
		}
		if (key == 'd') {
			ptr_str[cell] += 13;
			w = way_DEFAULT;
			selectCellMemory(w);
		}
		if (key == 'e') {
			ptr_str[cell] += 14;
			w = way_DEFAULT;
			selectCellMemory(w);
		}
		if (key == 'f') {
			ptr_str[cell] += 15;
			w = way_DEFAULT;
			selectCellMemory(w);
		}
	}

	mt_gotoXY(26, 1);

	return 0;
}