//Header Data.h
#include "boolean.h"
#include "mystring.h"
#ifndef DATA_H
#define DATA_H

//Konstanta
#define MaxPlayer 1000


/* ****** Definisi Tipe Data **********
 * Peringatan: Nama pengguna harus unik!!!!
 * Indeks pertama dimulai dari 1
*/
typedef struct {
	String nama;
	int score;
	int time;
}Data;

typedef struct{
	Data TI[MaxPlayer + 1];
	int jumlahPemain;
}tabData;

//Konstruktor
void CreateEmptyData(tabData *T);
//Menghasilkan T yang kosong

// ******** Load dan Save Data ***********
int loadData(tabData *T, String lokasi);
/* Meload data ke tabel. Menghasilkan 0 jika berhasil.
 * Pesan error:	* 422: Invalid Format
 * 				* 404: File Not Found atau Access denied
 */
 
int saveData(tabData T, String lokasi);
/* Mensave tabel ke file. Return 0 jika berhasil, 1 jika gagal
 */

//****** Pengecekan terhadap kondisi tabel **********/
boolean IsTableEmpty(tabData T);
//Menghasilkan true jika tabel kosong

boolean IsTabFull(tabData T);
//Menghasilkan true jika tabel penuh

boolean IsMemberData(tabData T, String nama);
//Menghasilkan true jika pengguna dengan nama tersebut sudah ada di tabel

//***** Penambahan dan penghapusan pengguna *******/
boolean addPengguna(tabData *T, String nama, int score, int time);
/* Menambahkan data pengguna ke dalam tabel. Tabel mungkin penuh. Jika 
 * data berhasil ditambahkan ke tabel menghasilkan true. Nama harus dicek terlebih dahulu keunikannya
 */

boolean delPengguna(tabData *T, String nama);
/* Menghapus pengguna dengan nama pengguna dari tabel.
 */

//Procedure Sort
void sortScoreDesc(tabData *T);
/* I.S.	:Tab T terdefinisi
 * F.S	:Data pada tabel terurut menurun berdasarkana score
 */

//****** Fungsi-Fungsi lainnya *****/
char* intToWaktu(int waktu);
//Mengkonversi waktu menjadi string dengan format yyyy-mm-dd<spasi>hh:mm
#endif
