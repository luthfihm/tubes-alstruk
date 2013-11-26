#include "../boolean.h"
#include <stdio.h>
#include <time.h>

// Bentuk susunan kartu dalam bentuk implementasi Deck

#define Nil 0
#define MaxEl 68
#define TOP(S) (S).TOP
#define Jenis(K) (K).Jenis
#define ID(K) (K).ID
#define Guna(K) (K).Guna

typedef struct {
	int ID;
	char Jenis;
	char Guna;
	}Kartu;
	
typedef Kartu infotype;
typedef int address;
/* Contoh deklarasi variabel bertype Deck dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
	infotype T[MaxEl+1];
	address TOP;
	} Deck;
/* Definisi Deck S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Deck T[1]..T[MaxEl] */
/* Jika S adalah Deck maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */
/* Definisi akses dengan Selektor : Isilah dengan selektor yang tepat */
/* ********* Prototype ********* */
/* *** Konstruktor/Kreator *** */
void CreateEmpty (Deck *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Deck S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1..MaxEl */
/* Ciri Deck kosong : TOP bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty (Deck S);
/* Mengirim true jika Deck kosong: lihat definisi di atas */

boolean IsFull (Deck S);
/* Mengirim true jika tabel penampung nilai elemen Deck penuh */

/* ********** Operator Dasar Deck ********* */
void Undo (Deck *S,infotype X);
/* Menambahkan X sebagai elemen Deck S. */
/* I.S. S mungkin kosong, tabel penampung elemen Deck TIDAK penuh */
/* F.S. X menjadi TOP yang baru, TOP bertambah 1 */


void Draw (Deck *S,infotype *X);
/* Menghapus X dari Deck S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
 
void DefaultDeck (Deck *D);
//Mengembalikan kartu ke bentuk awal permainan

void ShuffleDeck (Deck *D);
//Mengacak tumpukan kartu sebelum dipakai dalam permainan


void TukarKartu(Deck *D, int i, int j);
//Menukar dua buah kartu yang urutannya ke-i dan ke-j	


