#include <stdio.h>
#include <stdlib.h>
#include "game.h"
void StartGame(ArrayofPlayer *T)
{
	do {
		clrscr();
		canvas();	
		Board_Init(5,5);
		Board_Print();
		gotoxy(5,34);
		printf(">> ");	
	} while (getchar() != '\n');
}