#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "../adt_deck/adt-deck.h"
void StartGame(ArrayofPlayer *T)
{
	String opt,pesan;
	Dataplayer Player;
	Deck D;
	int i,id,x,y,stat;
	boolean End,alert;
	i = 0;
	AcakKarakterPlayer(T);
	End = false;
	alert = false;
	Board_Init(5,5);
	do {
		clrscr();
		canvas();	
		Board_Print();
		id = i % NbPlayer(*T);
		Player = NamePlayer(*T,id);
		if (alert){
			gotoxy(5,35);
			printf("%s",pesan);
			alert = false;
		}
		gotoxy(5,34);
		printf("%s >> ",Player.Name);
		EmptyStr(opt);
		scanf("%s",opt);
		if (StrEq(opt,"putonboard")){
			scanf("%d %d %d",&x,&y,&stat);
			Board_PutCard(x-1,y-1,stat);
		}else if (StrEq(opt,"viewmap")){

		}else if (StrEq(opt,"putonplayer")){
			
		}else if (StrEq(opt,"discard")){

		}else if (StrEq(opt,"draw")){

		}else if (StrEq(opt,"viewchar")){
			alert = true;
			EmptyStr(pesan);
			if (Player.Character == Saboteur){
				CopyStr("Anda sebagai Saboteur",pesan);
			}else if (Player.Character == GoldMiner){
				CopyStr("Anda sebagai GoldMiner",pesan);
			}
		}else if (StrEq(opt,"finish")){
			i++;
		}else if (StrEq(opt,"cancel")){
			End = true;
		}else {

		}
	} while ((!End)&&(!Board_Win));
}

void AcakKarakterPlayer (ArrayofPlayer *T)
{
	int id,nS,nG,i;
	nS = 0;
	nG = 0;
	for (i = 0;i < NbPlayer(*T);i++){
		if (nS == NbSaboteur(*T)){
			UpdateCharacterofPlayer(T,i,GoldMiner);
			nG++;
		}else if (nG == NbGoldMiner(*T)){
			UpdateCharacterofPlayer(T,i,Saboteur);
			nS++;
		}else{
			srand(time(NULL));
			id = rand() % 2;
			if (id == 0){
				UpdateCharacterofPlayer(T,i,Saboteur);
				nS++;
			}else{
				UpdateCharacterofPlayer(T,i,GoldMiner);
				nG++;
			}
		}
	}
}