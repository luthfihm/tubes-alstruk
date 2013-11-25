/* * * * * * * * * * * * * * * * * * * * * * * * */
/* ADT Board v1.0 			 					 */
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
	clrscr();
	Board_Init(3,4);
	Board_Print();
	//while(1){
	while(!Board_Win){
		gotoxy(1,2);
		if (Board_Viewmap(2)){
			printf("Tengah Gold\n");
		}
		gotoxy(1,1);
		scanf("%d %d %d",&a,&b,&c);
		//Board_PrintCard(c);
		clrscr();
		gotoxy(1,3);
		Board_PutCard(a,b,c);
		Board_Print();
	}
	return 0;
}
