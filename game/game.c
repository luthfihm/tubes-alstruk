#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
void StartGame(ArrayofPlayer *T)
{
	String opt,pesan,Card,nama;
	char c;
	Dataplayer Player;
	Deck D;
	Kartu C;
	int i,j,id,x,y,stat,g,ids;
	boolean End,alert,Sudah_Ambil,Keluar_Kartu;
	i = 0;
	AcakKarakterPlayer(T);
	End = false;
	alert = false;
	Sudah_Ambil = false;
	Keluar_Kartu = false;
	CreateEmpty(&D);
	DefaultDeck(&D);
	ShuffleDeck(&D);
	DeckReady(&D);
	BagiKartu(T,&D);
	Board_Init(5,5);
	do {
		clrscr();
		canvas();	
		Board_Print();
		id = i % NbPlayer(*T);
		Player = NamePlayer(*T,id);
		ShowKartuPlayer ((*T).Player[id]);
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
			do {
				scanf("%c",&c);
			} while(c == ' ');
			EmptyStr(Card);
			if (c != '\n'){
				scanf("%[^\"]s",Card);
				scanf("%c",&c);
			}
			scanf("%d %d",&x,&y);
			scanf("%d",&stat);
			if ((*T).Player[id].Condition == Disabled){
				alert = true;
				EmptyStr(pesan);
				CopyStr("Anda dalam kondisi Disabled",pesan);
			}else if (Keluar_Kartu){
					alert = true;
					EmptyStr(pesan);
					CopyStr("Anda sudah mengeluarkan kartu",pesan);
			}else{
				if (TakeKartufromPlayer(T,id,Card,&C)){
					if (C.ID <= 16){
						if (stat == 180){
							g = (((C.Guna>>2)&3)+((C.Guna&3)<<2) & 15) + (C.Guna & 16);
						}else{
							g = C.Guna;
						}
						if (Board_PutCard(x-1,y-1,g)){
							Keluar_Kartu = true;
						}else{
							FillKartuonPlayer(T,id,C);
							alert = true;
							EmptyStr(pesan);
							CopyStr("Posisi atau kartu path tidak valid",pesan);
						}
					}else{
						FillKartuonPlayer(T,id,C);
						alert = true;
						EmptyStr(pesan);
						CopyStr("Bukan kartu path",pesan);
					}
				}else{
					alert = true;
					EmptyStr(pesan);
					CopyStr("Kartu tidak ada",pesan);
				}
			}
		}else if (StrEq(opt,"viewmap")){
			scanf("%d %d",&x,&y);
			if (Keluar_Kartu){
				alert = true;
				EmptyStr(pesan);
				CopyStr("Anda sudah mengeluarkan kartu",pesan);
			}else if (TakeKartufromPlayer(T,id,"Action 3",&C)){
				if ((y == 1)&&((x == 1)||(x == 3)||(x == 5))){
					stat = Board_Viewmap(x/2);
					if (stat == 0){
						alert = true;
						CopyStr("Kartu berisi 'Gold'",pesan);
					}else if (stat == 1){
						alert = true;
						CopyStr("Kartu berisi 'Rocks'",pesan);
					}
					Keluar_Kartu = true;
				}else{
					FillKartuonPlayer(T,id,C);
					alert = true;
					CopyStr("Koordinat tidak valid",pesan);
				}
			}else{
				alert = true;
				EmptyStr(pesan);
				CopyStr("Anda tidak mempunyai Kartu View Map",pesan);
			}
		}else if (StrEq(opt,"putonplayer")){
			do {
				scanf("%c",&c);
			} while(c == ' ');
			if (c != '\n'){
				EmptyStr(Card);
				j = 0;
				do {
					scanf("%c",&c);
					if ((c != '"')&&(c != '\n')){
						Card[j] = c;
						j++;
					}
				} while ((c != '"')&&(c != '\n'));
				do {
					scanf("%c",&c);
				} while(c == ' ');
				if (c != '\n'){
					EmptyStr(nama);
					scanf("%[^\"]s",nama);
					scanf("%c",&c);
					do {
						scanf("%c",&c);
					} while ((c == ' ')&&(c != '\n'));
					alert = true;
					EmptyStr(pesan);
					if (StrEq(Card,"Action 1")){
						if (TakeKartufromPlayer(T,id,Card,&C)){
							if (StrEq(nama,"me")){
								if (ConditionofPlayer(*T,id) == Enabled){
									UpdateConditiononPlayer(T,id,Disabled);
									alert = true;
									EmptyStr(pesan);
									CopyStr("Anda sekarang dalam kondisi Disabled",pesan);
									Keluar_Kartu = true;
								}else{
									alert = true;
									EmptyStr(pesan);
									CopyStr("Break tool tidak bisa. Target sudah dalam kondisi Disabled",pesan);
									FillKartuonPlayer(T,id,C);
								}
							}else if (IsMemberofArrayPlayer(*T,nama)){
								ids = GetPlayerIdx(*T,nama);
								if (ConditionofPlayer(*T,ids) == Enabled){
									UpdateConditiononPlayer(T,ids,Disabled);
									alert = true;
									EmptyStr(pesan);
									strConcate((*T).Player[ids].Name," sekarang sudah dalam kondisi Disabled",pesan);
									Keluar_Kartu = true;
								}else{
									alert = true;
									EmptyStr(pesan);
									CopyStr("Break tool tidak bisa. Target sudah dalam kondisi Disabled",pesan);
									FillKartuonPlayer(T,id,C);
								}
							}else{
								FillKartuonPlayer(T,id,C);
							}
						}else{
							alert = true;
							EmptyStr(pesan);
							CopyStr("Anda tidak mempunya kartu 'Break'",pesan);
						}
					}else if (StrEq(Card,"Action 2")){
						if (TakeKartufromPlayer(T,id,Card,&C)){
							if (StrEq(nama,"me")){
								if (ConditionofPlayer(*T,id) == Disabled){
									UpdateConditiononPlayer(T,id,Enabled);
									alert = true;
									EmptyStr(pesan);
									CopyStr("Anda sekarang dalam kondisi Enabled",pesan);
									Keluar_Kartu = true;
								}else{
									alert = true;
									EmptyStr(pesan);
									CopyStr("Break tool tidak bisa. Target sudah dalam kondisi Enabled",pesan);
									FillKartuonPlayer(T,id,C);
								}
							}else if (IsMemberofArrayPlayer(*T,nama)){
								ids = GetPlayerIdx(*T,nama);
								if (ConditionofPlayer(*T,ids) == Disabled){
									UpdateConditiononPlayer(T,ids,Enabled);
									alert = true;
									EmptyStr(pesan);
									strConcate(nama," sekarang sudah dalam kondisi Enabled",pesan);
									Keluar_Kartu = true;
								}else{
									alert = true;
									EmptyStr(pesan);
									CopyStr("Break tool tidak bisa. Target sudah dalam kondisi Enabled",pesan);
									FillKartuonPlayer(T,id,C);
								}
							}else{
								FillKartuonPlayer(T,id,C);
							}
						}else{
							alert = true;
							EmptyStr(pesan);
							CopyStr("Anda tidak mempunya kartu 'Break'",pesan);
						}
					}else{
						alert = true;
						EmptyStr(pesan);
						CopyStr("Bukan Kartu Break atau Repair",pesan);
					}
				}

			}
		}else if (StrEq(opt,"discard")){
			do {
				scanf("%c",&c);
			} while(c == ' ');
			if (c != '\n'){
				EmptyStr(Card);
				scanf("%[^\"]s",Card);
				scanf("%c",&c);
				if (Keluar_Kartu){
					alert = true;
					EmptyStr(pesan);
					CopyStr("Anda sudah mengeluarkan kartu",pesan);
				}else{
					if (TakeKartufromPlayer(T,id,Card,&C)){
						Keluar_Kartu = true;
					}else{
						alert = true;
						EmptyStr(pesan);
						CopyStr("Kartu tidak ada",pesan);
					}
				}
			}
			if (Keluar_Kartu){

			}
		}else if (StrEq(opt,"draw")){
			if (IsEmpty(D)){
				alert = true;
				EmptyStr(pesan);
				CopyStr("Draw pile kosong",pesan);
			}else if(Sudah_Ambil){
				alert = true;
				EmptyStr(pesan);
				CopyStr("Anda sudah mengambil kartu",pesan);
			}else if(!Keluar_Kartu){
				alert = true;
				EmptyStr(pesan);
				CopyStr("Anda belum mengeluarkan kartu",pesan);
			}else{
				Draw(&D,&C);
				FillKartuonPlayer(T,id,C);
				Sudah_Ambil = true;
			}
		}else if (StrEq(opt,"viewchar")){
			alert = true;
			EmptyStr(pesan);
			if (Player.Character == Saboteur){
				CopyStr("Anda sebagai Saboteur",pesan);
			}else if (Player.Character == GoldMiner){
				CopyStr("Anda sebagai GoldMiner",pesan);
			}
		}else if (StrEq(opt,"finish")){
			if (!Sudah_Ambil){
				alert = true;
				EmptyStr(pesan);
				CopyStr("Anda belum mengambil kartu",pesan);
			}else if (!Keluar_Kartu){
				alert = true;
				EmptyStr(pesan);
				CopyStr("Anda belum mengeluarkan kartu",pesan);
			}else{
				Sudah_Ambil = false;
				Keluar_Kartu = false;
				i++;
			}
		}else if (StrEq(opt,"cancel")){
			End = true;
		}else {
			alert = true;
			EmptyStr(pesan);
			CopyStr("Perintah tidak valid",pesan);
		}
	} while ((!End)&&(!Board_Win));
	if (Board_Win != 0){
		do {
			clrscr();
			canvas();
			Board_Print();
			gotoxy(5,34);
			if (Board_Win == -1){
				printf("'Saboteur' WIN!!! Press enter to continue... ");
			}else if(Board_Win == 1){
				printf("'GoldMiner' WIN!!! Press enter to continue... ");
			}
		} while (getchar() != '\n');
		do {
			clrscr();
			canvas();
			Board_Print();
			gotoxy(5,34);
			if (Board_Win == -1){
				printf("'Saboteur' WIN!!! Press enter to continue... ");
			}else if(Board_Win == 1){
				printf("'GoldMiner' WIN!!! Press enter to continue... ");
			}
		} while (getchar() != '\n');
		if (Board_Win == -1){
			BagiGold (T,Saboteur);
		}else if (Board_Win == 1){
			BagiGold (T,GoldMiner);
		}
		do {
			clrscr();
			canvas();
			if (Board_Win == -1){
				ScoreBoard(*T,Saboteur);
			}else if (Board_Win == 1){
				ScoreBoard(*T,GoldMiner);
			}
			gotoxy(5,34);
			printf("Press Enter to continue... ");
		} while (getchar() != '\n');
	}
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

void BagiKartu (ArrayofPlayer *T,Deck *D)

{
	int i,j;
	Kartu C;
	for (i = 0;i < NbPlayer(*T);i++){
		for (j = 0;j < 5;j++){
			Draw(D,&C);
			FillKartuonPlayer(T,i,C);
		}
	}	
}

void BagiGold (ArrayofPlayer *T,char Winner)

{
	/* Kamus Lokal */
	index i,Score;
	Kartu K1,K2;
	DeckGold D;
	/* Algoritma */
	DefaultGold(&D);
	i = 0;
	while (i < NbPlayer(*T)){
		(*T).Player[i].NKartu = 0;
		UpdateScoreonPlayer (T,i,0);
		Score = 0;
		if (CharacterofPlayer(*T,i) == Winner){
			DrawGold(&D,&K1,&K2);
			FillKartuonPlayer(T,i,K1);
			FillKartuonPlayer(T,i,K2);
			Score += (K1.ID - 21);
			Score += (K2.ID - 21);
			UpdateScoreonPlayer(T,i,Score);
		}
		i++;
	}
}

void ShowKartuPlayer (Dataplayer P)

{
	int i,x,y;
	String Nama;
	i = 0;
	x = 86;
	y = 3;
	while (i < P.NKartu){
		if ((i % 2) == 1){
			GambarKartu(P.OnHand[i],x+12,y);
			EmptyStr(Nama);
			NamaKartu(P.OnHand[i],Nama);
			gotoxy(x+12,y+6);
			printf("%s\n",Nama);
		}else{
			y += 7;
			GambarKartu(P.OnHand[i],x,y);
			EmptyStr(Nama);
			NamaKartu(P.OnHand[i],Nama);
			gotoxy(x,y+6);
			printf("%s\n",Nama);
		}
		i++;
	}
}

void ScoreBoard (ArrayofPlayer T,char Winner)

{
	int i,x,y,id;
	char *Head[] = {
	 "  _____                      ____                      _ ",
	 " / ____|                    |  _ \\                    | |",
	 "| (___   ___ ___  _ __ ___  | |_) | ___   __ _ _ __ __| |",
	 " \\___ \\ / __/ _ \\| '__/ _ \\ |  _ < / _ \\ / _` | '__/ _` |",
	 " ____) | (_| (_) | | |  __/ | |_) | (_) | (_| | | | (_| |",
	 "|_____/ \\___\\___/|_|  \\___| |____/ \\___/ \\__,_|_|  \\__,_|",
	 ""
	};
	i = 0;
	x = 29;
	y = 2;
	while (!StrEq(Head[i],"")){
		gotoxy(x,y+i);
		printf("%s\n",Head[i]);
		i++;
	}
	gotoxy(3,9);
	printf("=============================================================================================================");
	x = 75;
	y = 10;
	for (i=0;i<23;i++){
		gotoxy(x,y+i);
		printf("||");
	}
	gotoxy(25,11);
	if (Winner == Saboteur){
		printf("KARTU GOLD UNTUK SABOTEUR");
	}else{
		printf("KARTU GOLD UNTUK GOLDMINER");
	}
	x = 5;
	y = 13;
	i = 0;
	id = 0;
	while (i < NbPlayer(T)){
		if (CharacterofPlayer(T,i)==Winner){
			if (id == 3){
				y = 22;
				x = 5;
			}
			gotoxy(x+3,y+7);
			printf("%s",T.Player[i].Name);
			GambarKartu(T.Player[i].OnHand[0],x,y);
			x += 11;
			GambarKartu(T.Player[i].OnHand[1],x,y);
			x += 13;
			id++;
		}
		i++;
	}
	i = 0;
	x = 78;
	y = 12;
	while (i < NbPlayer(T)){
		gotoxy(x,y+(2*i));
		printf("#  %s",T.Player[i].Name);
		gotoxy(x+3,y+1+(2*i));
		if (CharacterofPlayer(T,i)==Saboteur){
			printf("=> Saboteur ; Score = %d",ScorePlayer(T,i));
		}else if (CharacterofPlayer(T,i)==GoldMiner){
			printf("=> GoldMiner ; Score = %d",ScorePlayer(T,i));
		}
		i++;
	}
}