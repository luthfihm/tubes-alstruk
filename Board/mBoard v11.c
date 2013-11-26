/* * * * * * * * * * * * * * * * * * * * * * * * */
/* ADT Board v1.1 			 					 */
/* By Muntaha Ilmi 13512048  					 */
/* Driver 					 					 */
/* Mengatur Board. Melingkupi pencetakan Board,  */
/* Taruh kartu, viewmap, dan pengecekan kondisi  */
/* deadlock/win	untuk Saboteur/Goldminer		 */
/* * * * * * * * * * * * * * * * * * * * * * * * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Board.h"

int main(){
	int a,b,c;
	#ifndef _WIN32
	clrscr();
	#else
	system("cls");
	#endif
	Board_Init(3,4);
	Board_Print();
	//while(1){
	while(!Board_Win){
		#ifndef _WIN32
		gotoxy(1,2);
		#endif
		if (Board_Viewmap(2)){
			printf("Tengah Gold\n");
		}
		#ifndef _WIN32
		gotoxy(1,1);
		#endif
		scanf("%d %d %d",&a,&b,&c);
		//Board_PrintCard(c);
		#ifndef _WIN32
		clrscr();
		gotoxy(1,3);
		#else
		system("cls");
		#endif
		Board_PutCard(a,b,c);
		Board_Print();
	}
	return 0;
}
