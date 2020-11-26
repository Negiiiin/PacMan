
// Negin Baghbanzadeh
//810196599

#include"pacman.h"

int main()
{
	initScreen();
	draw_Table();
	Print_Cookie();
	char x = 's';
	char *d = &x;
	drawOpeningMouthPacman(2, 1, d, 97, 10, 97, 37);
}