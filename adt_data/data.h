//Header Data.h
#include "../boolean.h"
#include "../mystring/mystring.h"
#include <time.h>
#ifndef DATA_H
#define DATA_H

//Konstanta
#define MaxUser 1000


/* ****** Definisi Tipe Data **********
 * Peringatan: Nama pengguna harus unik!!!! Setiap melakukan add user cek terlebih dahulu
 * apakah sudah ada pengguna dengan nama yang sama
 * 
 * Indeks pertama tabel dimulai dari 1
*/

typedef struct {
	String nama; //nama pengguna
	int score; //highscore
	time_t time; //last played
}Data;

typedef struct{
	Data TI[MaxUser + 1];
	int jumlahPemain;
}tabData;

//Konstruktor
void CreateEmptyData(tabData *T);
//Menghasilkan T yang kosong

// ******** Load dan Save Data ***********
int loadData(tabData *T);
/* Meload data ke tabel. Menghasilkan 0 jika berhasil. Lokasi file didefinisikan di MesinKarakter
 * Pesan error:	* 422: Invalid Format
 * 				* 404: File Not Found atau Access denied
 */
 
void saveData(tabData T);
/* Mensave tabel ke file. Return 0 jika berhasil, 403 jika gagal Lokasi file didefinisikan di MesinKarakter
 */

//****** Pengecekan terhadap kondisi tabel **********/
boolean IsTableEmpty(tabData T);
//Menghasilkan true jika tabel kosong

boolean IsTabFull(tabData T);
//Menghasilkan true jika tabel penuh

boolean IsMemberData(tabData T, String nama);
//Menghasilkan true jika pengguna dengan nama tersebut sudah ada di tabel

//***** Penambahan, penghapusan, edit data pengguna *******/
boolean addPengguna(tabData *T, String nama, int score, time_t time);
/* Menambahkan data pengguna ke dalam tabel. Tabel mungkin penuh. Jika 
 * data berhasil ditambahkan ke tabel menghasilkan true. Nama harus dicek terlebih dahulu keunikannya
 */

boolean delPengguna(tabData *T, String nama);
/* Menghapus pengguna dengan nama pengguna dari tabel.
 * Return false jika penghapusan pengguna gagal
 */

void editData(tabData *T, String nama, int newScore, time_t newTime);
/* I.S :nama ada di tabel T
 * F.S :score dan time milik nama diupdate menjadi newScore dan newTime
 */
 
// ***** Pencetakan pengguna ke layar *****sea
void PrintPengguna(tabData T);
//Menampilkan nama pengguna ke layar

void PrintHighScore(tabData T);
//Menampilkan 10 pengguna dengan skor tertinggi

//Procedure Sort
void sortScoreDesc(tabData *T);
/* I.S.	:Tab T terdefinisi
 * F.S	:Data pada tabel terurut menurun berdasarkana score
 */

//****** Fungsi-Fungsi lainnya *****/
void intToWaktu(time_t waktu, String output);
/* I.S.: variable waktu merepresentasikan waktu sekarang
 * F.S.: Output berisi konversi variabel waktu ke string 
 * dengan format yyyy-mm-dd<spasi>hh:mm
 */
#endif
