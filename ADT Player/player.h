#ifndef player_h
#define player_h

/* ----- File Include ----- */
#include <stdlib.h>
#include "kartu.h"
#include "boolean.h"

/* ----- Konstanta ----- */
/* -- Karakter Pemain -- */
#define Saboteur 'S'
#define GoldMiner 'G'

/* --- Kondisi Pemain -- */
#define Enabled 'E'
#define Disabled 'D'

/* -- Jumlah Maksimum -- */
#define MaxCard 5
#define MaxPlayer 10
#define MaxLength 22

/* --- Jumlah minimum -- */
#define MinCard 0
#define MinPlayer 3

/* Nilai Takterdefinisi */
#define Absent 'A' /* Nilai ini digunakan untuk mendefinisikan indeks yang empty*/

/* ---- Tipe Bentukan ----- */
typedef int index; /* jika sudah ada di adt data, hapus aja */
typedef struct {
	string Name;
	card onHand[MaxCard];
	int Score;
	char Character;
	char Condition;
} Dataplayer; /* Data player yang disimpan saat bermain */
typedef struct {
	Dataplayer Player[MaxPlayer]; /* Array dari data player */
	int Nb; /* Menyimpan jumlah player */
} ArrayofPlayer;

/* 	----- Selektor ----- */
#define NbPlayer(T) (T).Nb
string NamePlayer(ArrayofPlayer T, index i);
/*	Mengambil nama player ke-index dari tabel */
char CharacterofPlayer(ArrayofPlayer T, index i);
/*	Mengambil karakter player ke-index dari tabel */
char ConditionofPlayer(ArrayofPlayer T, index i);
/*	Mengambil kondisi player ke-index dari tabel */
int ScorePlayer(ArrayofPlayer T, index i);
/*	Mengambil score player ke-index dari tabel */
card CardonIndex(ArrayofPlayer T, index user, index cards);
/*	Mengambil card player ke-index dari tabel */

/* 	Definisi dari array player yang kosong adalah apabila condition berisi 
	Absent */
/*	Array merupakan array yang rata kiri serta kontigu */

/* 	----- Pembuatan Array Kosong ----- */
void MakeEmpty (ArrayofPlayer *T);
/* 	I.S.	: Sembarang
	F.S.	: Array terdefinisi kosong
	Proses	: Mengset semua Condition menjadi Absent */

/*	----- Predikat ----- */
boolean IsMemberofArrayPlayer (ArrayofPlayer T, string Name);
/*	Mengembalikan nilai true apabila player yang diinput sudah ada di array
	player */
boolean IsFullofArrayPlayer (ArrayofPlayer T);
/*	Mengembalikan nilai true apabila NbPlayer mencapai maksimum */
boolean IsLessMinofArrayPlayer (ArrayofPlayer T);
/*	Mengembalikan nilai true apabila NbPlayer tidak mencapai minimum */
boolean IsMemberofCardonHand (ArrayofPlayer T, index i, card ID);
/*	Mengecek apakah ada kartu

/*	----- Pengolahan Elemen Array ----- */
void InsertPlayer (ArrayofPlayer *T, string Name);
/*	I.S.	: T terdefinisi boleh kosong, Name terdefinisi
	F.S.	: Array terisi player
	Proses	: Memasukkan name ke indeks yang masih kosong, diset value
			  Condition menjadi enabled, kartu berisi semua dummy, 
			  dan score menjadi 0. NbPlayer ditambah. */
void UpdateScoreonPlayer (ArrayofPlayer *T, index i, int Score);
/*	I.S.	: T terdefinisi tidak kosong, game selesai, score dan i terdefinisi
	F.S.	: Score player yang berada di indeks ke-i terupdate
	Proses	: Score di-update dengan cara ditambahkan dengan score lama
			  yang bisa saja 0 */
void UpdateConditiononPlayer (ArrayofPlayer *T, index i, char Condition);
/*	I.S.	: T terdefinisi tidak kosong, game sedang dijalankan, i dan Condition terdefinisi
	F.S.	: Condition dari player yang berada di indeks ke-i terupdate
	Proses	: Mengganti Condition di array sesuai dengan input */
void UpdateCharacterofPlayer (ArrayofPlayer *T, index i, char Character);
/*	I.S.	: T terdefinisi tidak kosong, game tahap inisialisasi
	F.S.	: Character dari player yang berada di indeks ke-i terupdate
	Proses	: Mengisi Character di array sesuai dengan input */
void FillCardonPlayer (ArrayofPlayer *T, index i, card ID);
/* 	I.S.	: T terdefinisi tidak kosong, game tahap bermain (turn)
	F.S.	: Kartu tangan player indeks ke-i terupdate
	Proses	: Dummy pada kartu tangan diganti dengan input */
void TakeCardfromPlayer (ArrayofPlayer *T, index i, card ID);
/*	I.S.	: T terdefinisi tidak kosong, game tahap bermain (turn)
	F.S.	: Kartu tangan player indeks ke-i terupdate tanpa ID
	Proses	: ID di kartu tangan diganti dengan Dummy */
	
/*	----- Penghitungan Character ----- */
int NbSaboteur (ArrayofPlayer T);
/*	Mengembalikan jumlah saboteur sesuai jumlah player yang bermain 
	yaitu (n-1) div 2 */
int NbGoldMiner (ArrayofPlayer T);
/* 	Mengembalikan jumlah gold miner sesuai jumlah player dan saboteur
	yang bermain yaitu n-n(saboteur) */

/*	----- Penghitungan Kartu ----- */
int CardOnHand (ArrayofPlayer T, index user);
/*	Menghitung jumlah kartu yang ada di tangan */

#endif