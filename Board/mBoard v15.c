/* * * * * * * * * * * * * * * * * * * * * * * * */
/* ADT Board v1.5 			 					 */
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
	int a,b,c,d,ax,ay,as;
	int lastmov;
	int posx,posy;
	posx=3;posy=4;
	#ifndef _WIN32
	clrscr();
	#else
	system("cls");
	#endif
	Board_Init(posx,posy);
	Board_Print();
	lastmov=0;
	//while(1){
	while(!Board_Win){
		#ifndef _WIN32
		gotoxy(1,2);
		#endif
		scanf("%d",&d);
		switch(d){
			case 1: //putonboard
					scanf("%d %d %d",&a,&b,&c);
					break;
			case 2: //viewmap
					scanf("%d %d",&a,&b);
					break;
			case 3: //rockfall
					scanf("%d %d",&a,&b);
					break;
		}
		#ifndef _WIN32
		clrscr();
		gotoxy(1,1);
		#else
		system("cls");
		#endif
		switch(d){
			case 0: //finish turn
					if (lastmov==1){
						Board_PutCard(ay,ax,as);
					} else if (lastmov==2){
						Board_Rockfall(ay,ax);
					} else if (lastmov==3){
						if (Board_Viewmap((ay-1)/2)){
							printf("Goalcard (%d,1) adalah Gold\n",ay);
						} else {
							printf("Goalcard (%d,1) bukan Gold\n",ay);
						}
					}
					lastmov=0;
					break;
			case 1: //putonboard
					if (Board_CekPut(a,b,c)>0){
						ay=a;ax=b;as=c;
						lastmov=1;
					}
					break;
			case 2: //viewmap
					if ((b==1)&&((a==1)||(a==3)||(a==5))){
						ay=a;
						ax=b;
						lastmov=3;
					} else {
						printf("Posisi tidak pada Goalcard\n");
					}
					break;
			case 3: //rockfall
					if (Board_CekRock(a,b)>0){
						ay=a;ax=b;
						lastmov=2;
					}
					break;
			case 4: //undo
					lastmov=0;
					break;
		}
		Board_Print();
		if (lastmov==1){
			Board_PrintCard(ay,ax,as);
		} else if (lastmov==2){
			Board_PrintCard(ay,ax,0);
		}
	}
	return 0;
}
