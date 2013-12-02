#include "../boolean.h"
#include <stdio.h>
#include <time.h>
#include "adt-deck.h"
#include "../mystring/mystring.h"
// Bentuk susunan kartu dalam bentuk implementasi Deck

#define Nil 0
#define MaxEl 70
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
			Guna((*D).T[i])=26;
	}
	for(i=13;i<=16;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=4;
			Guna((*D).T[i])=28;
	}
	for(i=17;i<=21;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=5;
			Guna((*D).T[i])=25;
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
			Guna((*D).T[i])=4;
	}
	for(i=33;i<=33;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=9;
			Guna((*D).T[i])=8;
	}
	for(i=34;i<=34;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=10;
			Guna((*D).T[i])=5;
	}
	for(i=35;i<=35;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=11;
			Guna((*D).T[i])=10;
	}
	for(i=36;i<=37;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=12;
			Guna((*D).T[i])=9;
	}
	for(i=38;i<=38;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=13;
			Guna((*D).T[i])=12;
	}
	for(i=39;i<=39;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=14;
			Guna((*D).T[i])=13;
	}
	for(i=40;i<=40;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=15;
			Guna((*D).T[i])=11;
	}
	for(i=41;i<=41;i++){
			Jenis((*D).T[i])='P';
			ID((*D).T[i])=16;
			Guna((*D).T[i])=15;
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
	for(i=69;i<=70;i++){
			Jenis((*D).T[i])='A';
			ID((*D).T[i])=25;
			Guna((*D).T[i])=41; //RockFall
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


void DrawGold (DeckGold *D, Kartu *K1, Kartu *K2){
//Memberikan gold nugget kepada para pemenang
	(*K1)=(*D).T[TOP(*D)];	
	TOP(*D)=TOP(*D)-1;

	(*K2)=(*D).T[TOP(*D)];	
	TOP(*D)=TOP(*D)-1;
}

void NamaKartu(Kartu K,String Nama){
//Menampilkan kartu di tangan user
	switch(ID(K)){
		case 1 :
		CopyStr("Path 1",Nama);
		break;
		case 2 :
		CopyStr("Path 2",Nama);
		break;
		case 3 :
		CopyStr("Path 3",Nama);
		break;
		case 4 :
		CopyStr("Path 4",Nama);
		break;
		case 5 :
		CopyStr("Path 5",Nama);
		break;
		case 6 :
		CopyStr("Path 6",Nama);
		break;
		case 7 :
		CopyStr("Path 7",Nama);
		break;
		case 8 :
		CopyStr("Path 8",Nama);
		break;
		case 9 :
		CopyStr("Path 9",Nama);
		break;
		case 10 :
		CopyStr("Path 10",Nama);
		break;
		case 11 :
		CopyStr("Path 11",Nama);
		break;
		case 12 :
		CopyStr("Path 12",Nama);
		break;
		case 13 :
		CopyStr("Path 13",Nama);
		break;
		case 14 :
		CopyStr("Path 14",Nama);
		break;
		case 15 :
		CopyStr("Path 15",Nama);
		break;
		case 16 :
		CopyStr("Path 16",Nama);
		break;
		case 17 :
		CopyStr("Action 1",Nama);
		break;
		case 18 :
		CopyStr("Action 2",Nama);
		break;
		case 19 :
		CopyStr("Action 3",Nama);
		break;
		case 20 :
		CopyStr("Char 1",Nama);
		break;
		case 21 :
		CopyStr("Char 2",Nama);
		break;
		case 22 :
		CopyStr("Gold 1",Nama);
		break;
		case 23 :
		CopyStr("Gold 2",Nama);
		break;
		case 24 :
		CopyStr("Gold 3",Nama);
		break;
		case 25 :
		CopyStr("Action 4",Nama);
		break;
	}
}

void GambarKartu(Kartu K,int x,int y){
//Menampilkan ilustrasi kartu yang ada di tangan.
	String P[6];
	int i;
	switch(ID(K)){
		case 1 :
		CopyStr(" _______",P[0]);
		CopyStr("|  | |  |",P[1]);
		CopyStr("|__| |__|",P[2]);
		CopyStr("|__   __|",P[3]);
		CopyStr("|  | |  |",P[4]); 
		CopyStr("|__|_|__|",P[5]);
		break;
		case 2 :
		CopyStr(" _______",P[0]);
		CopyStr("|  | |  |",P[1]);
		CopyStr("|  | |  |",P[2]);
		CopyStr("|  | |  |",P[3]);
		CopyStr("|  | |  |",P[4]); 
		CopyStr("|__|_|__|",P[5]);
		break;
		case 3 :
		CopyStr(" _______",P[0]);
		CopyStr("|       |",P[1]);
		CopyStr("|_______|",P[2]);
		CopyStr("|_______|",P[3]);
		CopyStr("|       |",P[4]); 
		CopyStr("|_______|",P[5]);
		break;
		case 4 :
		CopyStr(" _______",P[0]);
		CopyStr("|       |",P[1]);
		CopyStr("|  _____|",P[2]);
		CopyStr("|  |  __|",P[3]);
		CopyStr("|  | |  |",P[4]); 
		CopyStr("|__|_|__|",P[5]);
		
		break;
		case 5 :	
		CopyStr(" _______",P[0]);
		CopyStr("|  | |  |",P[1]);
		CopyStr("|  | |__|",P[2]);
		CopyStr("|  |____|",P[3]);
		CopyStr("|       |",P[4]); 
		CopyStr("|_______|",P[5]);
		break;
		case 6 :
		
		CopyStr(" _______",P[0]);
		CopyStr("|  | |  |",P[1]);
		CopyStr("|  | |__|",P[2]);
		CopyStr("|  |  __|",P[3]);
		CopyStr("|  | |  |",P[4]);
		CopyStr("|__|_|__|",P[5]);
		break;
		case 7 :
		
		CopyStr(" _______",P[0]);
		CopyStr("|  | |  |",P[1]);
		CopyStr("|__| |__|",P[2]);
		CopyStr("|_______|",P[3]);
		CopyStr("|       |",P[4]);
		CopyStr("|_______|",P[5]);
		break;
		case 8 :
		CopyStr(" _______",P[0]);
		CopyStr("|       |",P[1]);
		CopyStr("|   _   |",P[2]);
		CopyStr("|  | |  |",P[3]);
		CopyStr("|  | |  |",P[4]);
		CopyStr("|__|_|__|",P[5]);
		break;
		case 9 :
		CopyStr(" _______",P[0]);
		CopyStr("|       |",P[1]);
		CopyStr("|   ____|",P[2]);
		CopyStr("|  |____|",P[3]);
		CopyStr("|       |",P[4]);
		CopyStr("|_______|",P[5]);
		break;
		case 10 :
		CopyStr(" _______",P[0]);
		CopyStr("|  | |  |",P[1]);
		CopyStr("|  |_|  |",P[2]);
		CopyStr("|   _   |",P[3]);
		CopyStr("|  | |  |",P[4]);
		CopyStr("|__|_|__|",P[5]);
		break;
		case 11 :
		CopyStr(" _______",P[0]);
		CopyStr("|       |",P[1]);
		CopyStr("|__   __|",P[2]);
		CopyStr("|__| |__|",P[3]);
		CopyStr("|       |",P[4]);
		CopyStr("|_______|",P[5]);
		break;
		case 12 :
		CopyStr(" _______",P[0]);
		CopyStr("|  | |  |",P[1]);
		CopyStr("|  |_|__|",P[2]);
		CopyStr("|    |__|",P[3]);
		CopyStr("|       |",P[4]);
		CopyStr("|_______|",P[5]);
		break;
		case 13 :
		CopyStr(" _______",P[0]);
		CopyStr("|       |",P[1]);
		CopyStr("|     __|",P[2]);
		CopyStr("|   _|__|",P[3]);
		CopyStr("|  | |  |",P[4]);
		CopyStr("|__|_|__|",P[5]);
		break;
		case 14 :
	
		CopyStr(" _______",P[0]);
		CopyStr("|  | |  |",P[1]);
		CopyStr("|  |_|__|",P[2]);
		CopyStr("|   _|__|",P[3]);
		CopyStr("|  | |  |",P[4]);
		CopyStr("|__|_|__|",P[5]);
		
		break;
		case 15 :
		CopyStr(" _______",P[0]);
		CopyStr("|  | |  |",P[1]);
		CopyStr("|__|_|__|",P[2]);
		CopyStr("|__| |__|",P[3]);
		CopyStr("|       |",P[4]);
		CopyStr("|_______|",P[5]);
		break;
		case 16 :
		CopyStr(" _______",P[0]);
		CopyStr("|  | |  |",P[1]);
		CopyStr("|__|_|__|",P[2]);
		CopyStr("|__|_|__|",P[3]);
		CopyStr("|  | |  |",P[4]);
		CopyStr("|__|_|__|",P[5]);
		break;
		case 17 :
		CopyStr(" _______",P[0]);
		CopyStr("|_______|",P[1]);
		CopyStr("|       |",P[2]);
		CopyStr("|!BREAK!|",P[3]);
		CopyStr("|_______|",P[4]);
		CopyStr("|_______|",P[5]);
		break;
		case 18 :
		CopyStr(" _______",P[0]);
		CopyStr("|_______|",P[1]);
		CopyStr("|       |",P[2]);
		CopyStr("|!REPAIR|",P[3]);
		CopyStr("|_______|",P[4]);
		CopyStr("|_______|",P[5]);
		break;
		case 19 :
		CopyStr(" _______",P[0]);
		CopyStr("|_______|",P[1]);
		CopyStr("|       |",P[2]);
		CopyStr("|ViewMap|",P[3]);
		CopyStr("|_______|",P[4]);
		CopyStr("|_______|",P[5]);
		break;
		case 20 :
		CopyStr(" _______",P[0]);
		CopyStr("|_______|",P[1]);
		CopyStr("|       |",P[2]);
		CopyStr("|  Gold |",P[3]);
		CopyStr("|_______|",P[4]);
		CopyStr("|_______|",P[5]);
		break;
		case 21 :
		CopyStr(" _______",P[0]);
		CopyStr("|_______|",P[1]);
		CopyStr("|       |",P[2]);
		CopyStr("| Sabot |",P[3]);
		CopyStr("|_______|",P[4]);
		CopyStr("|_______|",P[5]);
		break;
		case 22 :
		CopyStr(" _______",P[0]);
		CopyStr("|_______|",P[1]);
		CopyStr("|       |",P[2]);
		CopyStr("|   0   |",P[3]);
		CopyStr("|_______|",P[4]);
		CopyStr("|_______|",P[5]);
		break;
		case 23 :
		CopyStr(" _______",P[0]);
		CopyStr("|_______|",P[1]);
		CopyStr("|       |",P[2]);
		CopyStr("|  0 0  |",P[3]);
		CopyStr("|_______|",P[4]);
		CopyStr("|_______|",P[5]);
	
		break;
		case 24 :
		CopyStr(" _______",P[0]);
		CopyStr("|_______|",P[1]);
		CopyStr("|       |",P[2]);
		CopyStr("| 0 0 0 |",P[3]);
		CopyStr("|_______|",P[4]);
		CopyStr("|_______|",P[5]);
		break;
		case 25 :
		CopyStr(" _______",P[0]);
		CopyStr("|_______|",P[1]);
		CopyStr("|xxxxxxx|",P[2]);
		CopyStr("|  ROCK |",P[3]);
		CopyStr("|_______|",P[4]);
		CopyStr("|_______|",P[5]);
		break;
	}
	for (i = 0;i < 6;i++){
		gotoxy(x,y+i);
		printf("%s\n",P[i]);
	}
}
