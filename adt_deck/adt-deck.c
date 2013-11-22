#include "boolean.h"
#include <stdio.h>
#include <time.h>
#include "adt-deck.h"
// Bentuk susunan kartu dalam bentuk implementasi Deck

#define Nil 0
#define MaxEl 68
#define TOP(S) (S).TOP
#define Jenis(K) (K).Jenis
#define ID(K) (K).ID
#define Guna(K) (K).Guna


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
	for(i=1;i<=68;i++){
		j=(rand()%68)+1;
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
	TOP(*D)=68;
	}
