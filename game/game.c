#include <stdio.h>
#include <stdlib.h>
#include "game.h"
void StartGame(ArrayofPlayer *T)
{
	do {
		clrscr();
		Board_Init(2,10);
		Board_Print()
	} (getchar() != '\n')
}