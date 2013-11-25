/* * * * * * * * * * * * * * * * * * * * * * * * */
/* ADT Board v0.6 			 					 */
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
	Board_Init();
	Board_Print();
	//while(1){
	while(!Board_Win){
		if (Board_Viewmap(2)){
			printf("Tengah Gold\n");
		}
		scanf("%d %d %d",&a,&b,&c);
		Board_PrintCard(c);
		Board_PutCard(a,b,c);
		Board_Print();
	}
	return 0;
}
