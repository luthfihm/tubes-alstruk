/* Driver ADT Player */
#include "player.h"
#include "../tools/tools.h"

int main() {
	/* Kamus Lokal */
	ArrayofPlayer T;
	String name,Card;
	int number,i=0,score,ns=0,nKartu;
	char Co,Char;
	Deck D;
	infotype X;
	boolean as;
	Kartu Car;

	/* Algoritma */
	MakeEmptyAP(&T);
	do {
		scanf("%s",name);
		if (!IsMemberofArrayPlayer(T,name) && (!StrEq(name,"cek"))) {
			InsertPlayer(&T,name);
		}
	} while (!IsFullofArrayPlayer(T) && (!StrEq(name,"cek")));
	if (!IsLessMinofArrayPlayer(T)) {
		i = 0;
		while (i<NbPlayer(T)) {
			printf("%s\n",T.Player[i].Name);
			i++;
		}
		i = 0;
		printf("cekpoin 1\n");
		do {
			scanf("%d",&score);
			UpdateScoreonPlayer(&T,i,score);
			i++;
		} while (i < NbPlayer(T));
		i=0;
		printf("cekpoin 2\n");
		do {
			scanf("%s",&Co);
			UpdateConditiononPlayer(&T,i,Co);
			i++;
		} while (i < NbPlayer(T));
		i=0;
		printf("cekpoin 3\n");
		do {
			if (NbSaboteur-ns!=0) {
				UpdateCharacterofPlayer(&T,i,Saboteur);
				ns++;
			} else {
				UpdateCharacterofPlayer(&T,i,GoldMiner);
			}
			i++;
		} while (i < NbPlayer(T));
		DefaultDeck(&D);
		ShuffleDeck(&D);
		i=0;
		printf("cekpoin 4\n");
		do {
			nKartu = 0;
			do {
				Draw(&D,&X);
				FillKartuonPlayer(&T,i,X);
				nKartu++;
			} while (nKartu != 5);
			i++;
		} while (i < NbPlayer(T));
		i=0;
		do {
			printf("%d\n",KartuOnHand(T,i));
			i++;
		} while (i < NbPlayer(T));
		printf("%d\n",TotalKartuPlayer(T));
		printf("cekpoin 5\n");
		i = 0;
	} else {
		printf("isi tidak mencukupi\n");
	}
	return 0;
}