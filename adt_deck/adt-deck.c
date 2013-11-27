#include "boolean.h"
#include <stdio.h>
#include <time.h>
#include "adt-deck.h"
// Bentuk susunan kartu dalam bentuk implementasi Deck

#define Nil 0
#define MaxEl 68
#define MaxChar 10
#define TOP(S) (S).TOP
#define Jenis(K) (K).Jenis
#define ID(K) (K).ID
#define Guna(K) (K).Guna
#define NKartu(D) (D).NKartu

/*
typedef struct {
	int ID;
	char Jenis;
	char Guna;
	}Kartu;
	
typedef Kartu infotype;
typedef int address;
/* Contoh deklarasi variabel bertype Deck dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
/*typedef struct {
	infotype T[MaxEl+1];
	address TOP;
	} Deck; 
	*/ 
/* Definisi Deck S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Deck T[1]..T[MaxEl] */
/* Jika S adalah Deck maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */
/* Definisi akses dengan Selektor : Isilah dengan selektor yang tepat */
/* ********* Prototype ********* */
/* *** Konstruktor/Kreator *** */
void CreateEmpty (Deck *S){
/* I.S. Sembarang */
/* F.S. Membuat sebuah Deck S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1..MaxEl */
/* Ciri Deck kosong : TOP bernilai Nil */
	TOP(*S)=Nil;

}	

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty (Deck S){
/* Mengirim true jika Deck kosong: lihat definisi di atas */
	return (S.TOP==Nil);
}

boolean IsFull (Deck S){
/* Mengirim true jika tabel penampung nilai elemen Deck penuh */
	return (S.TOP==MaxEl);
}

/* ********** Operator Dasar Deck ********* */
void Undo (Deck *S,infotype X){
/* Menambahkan X sebagai elemen Deck S. */
/* I.S. S mungkin kosong, tabel penampung elemen Deck TIDAK penuh */
/* F.S. X menjadi TOP yang baru, TOP bertambah 1 */
	if(!(IsFull(*S))){
	TOP(*S)=TOP(*S)+1;
	(*S).T[TOP(*S)]=X;
	}
}

void Draw (Deck *S,infotype *X){
/* Menghapus X dari Deck S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
	if(!IsEmpty(*S)){
	(*X)=(*S).T[TOP(*S)];	
	TOP(*S)=TOP(*S)-1;
	
	}
}

 
void DefaultDeck (Deck *D){
//Mengembalikan kartu ke bentuk awal permainan
	int i;
	for(i=1;i<=5;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=1;
			Guna((*D).T[i])=31;
	}
	for(i=6;i<=9;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=2;
			Guna((*D).T[i])=21;
	}
	for(i=10;i<=12;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=3;
			Guna((*D).T[i])=11;
	}
	for(i=13;i<=16;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=4;
			Guna((*D).T[i])=13;
	}
	for(i=17;i<=21;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=5;
			Guna((*D).T[i])=7;
	}
	for(i=22;i<=26;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=6;
			Guna((*D).T[i])=29;
	}
	for(i=27;i<=31;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=7;
			Guna((*D).T[i])=27;
	}
	for(i=32;i<=32;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=8;
			Guna((*D).T[i])=5;
	}
	for(i=33;i<=33;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=9;
			Guna((*D).T[i])=5;
	}
	for(i=34;i<=34;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=10;
			Guna((*D).T[i])=20;
	}
	for(i=35;i<=35;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=11;
			Guna((*D).T[i])=10;
	}
	for(i=36;i<=37;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=12;
			Guna((*D).T[i])=24;
	}
	for(i=38;i<=38;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=13;
			Guna((*D).T[i])=12;
	}
	for(i=39;i<=39;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=14;
			Guna((*D).T[i])=21;
	}
	for(i=40;i<=40;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=15;
			Guna((*D).T[i])=26;
	}
	for(i=41;i<=41;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=16;
			Guna((*D).T[i])=30;
	}
	for(i=42;i<=50;i++){
			Jenis((*D).T[i])='A';
			ID((*D).T[i])=17;
			Guna((*D).T[i])=1;//Break 
	}
	for(i=51;i<=62;i++){
			Jenis((*D).T[i])='A';
			ID((*D).T[i])=18;
			Guna((*D).T[i])=21;//Repair
	}
	for(i=63;i<=68;i++){
			Jenis((*D).T[i])='A';
			ID((*D).T[i])=19;
			Guna((*D).T[i])=31; //ViewMap
	}
	
}


void ShuffleDeck (Deck *D){
//Mengacak tumpukan kartu sebelum dipakai dalam permainan
	int i,j;
	srand(time(NULL));
	for(i=1;i<=MaxEl;i++){
		j=(rand()%MaxEl)+1;
		TukarKartu(D,i,j);
	}
}

void TukarKartu(Deck *D, int i, int j){
//Menukar dua buah kartu yang urutannya ke-i dan ke-j	
		(*D).T[0].ID=(*D).T[i].ID;
		(*D).T[0].Jenis=(*D).T[i].Jenis;
		(*D).T[0].Guna=(*D).T[i].Guna;
		(*D).T[i].ID=(*D).T[j].ID;
		(*D).T[i].Jenis=(*D).T[j].Jenis;
		(*D).T[i].Guna=(*D).T[j].Guna;
		(*D).T[j].ID=(*D).T[0].ID;
		(*D).T[j].Jenis=(*D).T[0].Jenis;
		(*D).T[j].Guna=(*D).T[0].Guna;
}

void DeckReady (Deck *D){
	//Menyiapkan dek yang sudah diacak. Dalam hal ini, membuat deck menjadi sesuai dengan pengertian stack
	TOP(*D)=MaxEl;
	}

void DefaultChar(DeckChar *D, int NPemain){
//Menyiapkan deck untuk pembagian character masing-masing pemain
//Sudah Langsung DiShuffle
	int JSabot; //Jumlah Saboteur dalam Permainan
	int i;
	int j;
	if (NPemain>10){
		printf("Permainan tidak bisa dilanjutkan. Pemain berlebih. \n");
	}
	else{
		JSabot=(NPemain-1)/2;
		TOP(*D)=NPemain;
		for(i=1;i<=JSabot;i++){
			Jenis((*D).T[i])='C';
			ID((*D).T[i])=20;
			Guna((*D).T[i])=-99; //Saboteur
		}
		for(i;i<=NPemain;i++){
			Jenis((*D).T[i])='C';
			ID((*D).T[i])=21;
			Guna((*D).T[i])=-99; //GoldMiner
		}
		srand(time(NULL));
		for(i=1;i<=MaxChar;i++){
		j=(rand()%MaxChar)+1;
				(*D).T[0].ID=(*D).T[i].ID;
		(*D).T[0].Jenis=(*D).T[i].Jenis;
		(*D).T[0].Guna=(*D).T[i].Guna;
		(*D).T[i].ID=(*D).T[j].ID;
		(*D).T[i].Jenis=(*D).T[j].Jenis;
		(*D).T[i].Guna=(*D).T[j].Guna;
		(*D).T[j].ID=(*D).T[0].ID;
		(*D).T[j].Jenis=(*D).T[0].Jenis;
		(*D).T[j].Guna=(*D).T[0].Guna;
		}
		
	}
}

void DrawChar(DeckChar *D, Kartu *K){
//Memilihkan peran untuk pemain dengan cara men-draw kartu
	
	(*K)=(*D).T[TOP(*D)];	
	TOP(*D)=TOP(*D)-1;

}

void DefaultGold (DeckGold *D){
//Menyiapkan untuk pembagian gold nugget kepada para pemenang.
		TOP(*D)=MaxGold;
		int i,j;
		for(i=1;i<=16;i++){
			Jenis((*D).T[i])='G';
			ID((*D).T[i])=22;
			Guna((*D).T[i])=1; //GOLD 1
		}
		for(i;i<=19;i++){
			Jenis((*D).T[i])='G';
			ID((*D).T[i])=23;
			Guna((*D).T[i])=2; //GOLD 2
		}
		for(i;i<=28;i++){
			Jenis((*D).T[i])='G';
			ID((*D).T[i])=24;
			Guna((*D).T[i])=3; //GOLD 3
		}
		srand(time(NULL));
		for(i=1;i<=MaxGold;i++){
		j=(rand()%MaxGold)+1;
		(*D).T[0].Jenis=(*D).T[i].Jenis;
		(*D).T[0].Guna=(*D).T[i].Guna;
		(*D).T[i].ID=(*D).T[j].ID;
		(*D).T[i].Jenis=(*D).T[j].Jenis;
		(*D).T[i].Guna=(*D).T[j].Guna;
		(*D).T[j].ID=(*D).T[0].ID;
		(*D).T[j].Jenis=(*D).T[0].Jenis;
		(*D).T[j].Guna=(*D).T[0].Guna;
		}
	}


void DrawGold (DeckGold *D, Kartu *K1, Kartu *K2){
//Memberikan gold nugget kepada para pemenang
	
	(*K1)=(*D).T[TOP(*D)];	
	TOP(*D)=TOP(*D)-1;
	
	(*K2)=(*D).T[TOP(*D)];	
	TOP(*D)=TOP(*D)-1;
	
	
}

void NamaKartu(Kartu K){
//Menampilkan kartu di tangan user
	switch(ID(K)){
		case 1 :
		printf("Path 1 ");
		break;
		case 2 :
		printf("Path 2 ");
		break;
		case 3 :
		printf("Path 3 ");
		break;
		case 4 :
		printf("Path 4 ");
		break;
		case 5 :
		printf("Path 5 ");
		break;
		case 6 :
		printf("Path 6 ");
		break;
		case 7 :
		printf("Path 7 ");
		break;
		case 8 :
		printf("Path 8 ");
		break;
		case 9 :
		printf("Path 9 ");
		break;
		case 10 :
		printf("Path 10 ");
		break;
		case 11 :
		printf("Path 11 ");
		break;
		case 12 :
		printf("Path 12 ");
		break;
		case 13 :
		printf("Path 13 ");
		break;
		case 14 :
		printf("Path 14 ");
		break;
		case 15 :
		printf("Path 15 ");
		break;
		case 16 :
		printf("Path 16 ");
		break;
		case 17 :
		printf("Action 1");
		break;
		case 18 :
		printf("Action 2 ");
		break;
		case 19 :
		printf("Action 3 ");
		break;
		case 20 :
		printf("Char 1 ");
		break;
		case 21 :
		printf("Char 2 ");
		break;
		case 22 :
		printf("Gold 1 ");
		break;
		case 23 :
		printf("Gold 2 ");
		break;
		case 24 :
		printf("Gold 3 ");
		break;
	}
}

void GambarKartu(Kartu K){
//Menampilkan ilustrasi kartu yang ada di tangan.
	switch(ID(K)){
		case 1 :
		printf(" _______\n";
		printf("|  | |  |\n");
		printf("|__| |__|\n");
		printf("|__   __|\n");
		printf("|  | |  |\n"); 
		printf("|__|_|__|\n");
		break;
		case 2 :
		printf(" _______\n");
		printf("|  | |  |\n");
		printf("|  | |  |\n");
		printf("|  | |  |\n");
		printf("|  | |  |\n"); 
		printf("|__|_|__|\n");
		break;
		case 3 :
		printf(" _______\n");
		printf("|       |\n");
		printf("|_______|\n");
		printf("|_______|\n");
		printf("|       |\n"); 
		printf("|_______|\n");
		break;
		case 4 :
		printf(" _______\n");
		printf("|       |\n");
		printf("|  _____|\n");
		printf("|  |  __|\n");
		printf("|  | |  |\n"); 
		printf("|__|_|__|\n");
		
		break;
		case 5 :	
		printf(" _______\n");
		printf("|  | |  |\n");
		printf("|  | |__|\n");
		printf("|  |____|\n");
		printf("|       |\n"); 
		printf("|_______|\n");
		break;
		case 6 :
		
		printf(" _______\n");
		printf("|  | |  |\n");
		printf("|  | |__|\n");
		printf("|  |  __|\n");
		printf("|  | |  |\n");
		printf("|__|_|__|\n");
		break;
		case 7 :
		
		printf(" _______\n");
		printf("|  | |  |\n");
		printf("|__| |__|\n");
		printf("|_______|\n");
		printf("|       |\n");
		printf("|_______|\n");
		break;
		case 8 :
		printf(" _______\n");
		printf("|       |\n");
		printf("|   _   |\n");
		printf("|  | |  |\n");
		printf("|  | |  |\n");
		printf("|__|_|__|\n");
		break;
		case 9 :
		printf(" _______\n");
		printf("|       |\n");
		printf("|   ____|\n");
		printf("|  |____|\n");
		printf("|       |\n");
		printf("|_______|\n");
		break;
		case 10 :
		printf(" _______\n");
		printf("|  | |  |\n");
		printf("|  |_|  |\n");
		printf("|   _   |\n");
		printf("|  | |  |\n");
		printf("|__|_|__|\n");
		break;
		case 11 :
		printf(" _______\n");
		printf("|       |\n");
		printf("|__   __|\n");
		printf("|__| |__|\n");
		printf("|       |\n");
		printf("|_______|\n");
		break;
		case 12 :
		printf(" _______\n");
		printf("|  | |  |\n");
		printf("|  |_|__|\n");
		printf("|    |__|\n");
		printf("|       |\n");
		printf("|_______|\n");
		break;
		case 13 :
		printf(" _______\n");
		printf("|       |\n");
		printf("|     __|\n");
		printf("|   _|__|\n");
		printf("|  | |  |\n");
		printf("|__|_|__|\n");
		break;
		case 14 :
	
		printf(" _______\n");
		printf("|  | |  |\n");
		printf("|  |_|__|\n");
		printf("|   _|__|\n");
		printf("|  | |  |\n");
		printf("|__|_|__|\n");
		
		break;
		case 15 :
		printf(" _______\n");
		printf("|  | |  |\n");
		printf("|__|_|__|\n");
		printf("|__| |__|\n");
		printf("|       |\n");
		printf("|_______|\n");
		break;
		case 16 :
		printf(" _______\n");
		printf("|  | |  |\n");
		printf("|__|_|__|\n");
		printf("|__|_|__|\n");
		printf("|  | |  |\n");
		printf("|__|_|__|\n");
		break;
		case 17 :
		printf(" _______\n");
		printf("|_______|\n");
		printf("|       |\n");
		printf("|!BREAK!|\n");
		printf("|_______|\n");
		printf("|_______|\n");
		break;
		case 18 :
		printf(" _______\n");
		printf("|_______|\n");
		printf("|       |\n");
		printf("|!REPAIR|\n");
		printf("|_______|\n");
		printf("|_______|\n");
		break;
		case 19 :
		printf(" _______\n");
		printf("|_______|\n");
		printf("|       |\n");
		printf("|ViewMap|\n");
		printf("|_______|\n");
		printf("|_______|\n");
		break;
		case 20 :
		printf(" _______\n");
		printf("|_______|\n");
		printf("|       |\n");
		printf("| \Gold |n");
		printf("|_______|\n");
		printf("|_______|\n");
		break;
		case 21 :
		printf(" _______\n");
		printf("|_______|\n");
		printf("|       |\n");
		printf("| Sabot |\n");
		printf("|_______|\n");
		printf("|_______|\n");
		break;
		case 22 :
		printf(" _______\n");
		printf("|_______|\n");
		printf("|       |\n");
		printf("|   0   |\n");
		printf("|_______|\n");
		printf("|_______|\n");
		break;
		case 23 :
		printf(" _______\n");
		printf("|_______|\n");
		printf("|       |\n");
		printf("|  0 0  |\n");
		printf("|_______|\n");
		printf("|_______|\n");
	
		break;
		case 24 :
		printf(" _______\n");
		printf("|_______|\n");
		printf("|       |\n");
		printf("| 0 0 0 |\n");
		printf("|_______|\n");
		printf("|_______|\n");
		break;
	}
}
