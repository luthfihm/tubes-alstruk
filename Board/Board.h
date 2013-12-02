/* * * * * * * * * * * * * * * * * * * * * * * * */
/* ADT Board v1.5 			 					 */
/* By Muntaha Ilmi 13512048  					 */
/* Header 					 					 */
/* Mengatur Board. Melingkupi pencetakan Board,  */
/* Taruh kartu, viewmap, dan pengecekan kondisi  */
/* deadlock/win	untuk Saboteur/Goldminer		 */
/* * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef BOARD_H
#define BOARD_H

int Board_Card_Open[10][15]; /* Kode isi dari kartu yang ditaruh */
int Board_Card_Around[10][15]; /* kartu sebelah kosong/tdk */
int Board_Card_Able[10][15]; /* Jalan mana aja yang kebuka */
int Board_Card_Flag[10][15]; /* Posisi yang bisa ditaruh, 0 = Tidak bisa ditaruh, 1 = bisa ditaruh */
int Board_Win; /* Menandakan status game. 0 = Belum ada yang menang, 1 = Goldminer menang, -1 = Saboteur menang*/
static int Board_MoveY[]={1,0,-1,0}; /* Array pergerakan. Mempermudah loop ke kartu sekeliling */
static int Board_MoveX[]={0,1,0,-1}; /* Array pergerakan. Mempermudah loop ke kartu sekeliling */
int Board_PosX,Board_PosY;

/* Penjelasan kode isi kartu :
		memakai bitmask.
			Bit 1 = Berhubungan dengan kartu atas
			Bit 2 = Berhubungan dengan kartu kiri
			Bit 3 = Berhubungan dengan kartu bawah
			Bit 4 = Berhubungan dengan kartu kanan
			Bit 5 = Khusus untuk kartu path. Menandakan apakah buntu/tidak
	Untuk isi Card_Open, Bit aktif artinya kartu itu memiliki jalan ke arah itu.
	Untuk isi Card_Around, Bit aktif artinya ada kartu di arah tersebut.
	Untuk isi Card_Able, Bit aktif maksudya ada kartu jalan terbuka di arah tersebut. */
/* Penjelasan Goalcard:
	Goalcard memakai kode khusus. Jika Card_Open < 0 artinya goalcard 
   Arti kode Goalcard :
	-1 = Batu Kebuka
	-2 = Emas Kebuka
	-3 = Batu (tutup)
	-4 = Emas (tutup) */

void Board_Init(int PosX,int PosY);
	/* Inisialisasi Board */
	/* PosX dan PosY untuk posisi kiri atas Board */

int Board_CekPut(int PosY, int PosX, int Stat);
	/* Mengecek apakah kartu bisa ditaruh pada posisi tertentu */
	/* Kode output :
		1 = bisa ditaruh
		0 = Posisi di luar Board
		-1 = Posisi sudah ada kartu
		-2 = Tidak terhubung dengan Startcard
		-3 = Bentuk salah */

int Board_CekRock(int PosY, int PosX);
	/* Mengecek apakah Rockfall bisa dilakukan pada posisi tertentu */
	/* Rockfall tidak bisa dilakukan pada kartu Start, Goalcard, dan tempat kosong */
	/* Kode output :
		1 = bisa di-rockfall
		0 = Posisi di luar Board
		-1 = Posisi rockfall adalah Startcard
		-2 = Posisi rockfall adalah Goalcard
		-3 = Tidak ada kartu di posisi tertentu */

void Board_Print(void);
	/* Cetak Board. Ukuran 5x9 kartu. Mencetak bantuan posisi juga. */

void Board_PrintCard(int PosY, int PosX, int Stat);
	/* Cetak satu kartu, sesuai kode Stat. Lihat penjelasan diatas untuk kode Stat. */
	/* PosX dan PosY untuk posisi kartu di Board (5x9) */

int Board_CekGoal(void);
	/* Mengecek apakah deadlock karena Goalcard tidak bisa dicapai 
	   lagi sudah terjadi/belum */
	/* Tidak mengecek apakah kartu Rockfall sudah habis/belum */
	/*	1 = Deadlock terjadi
		0 = Belum Deadlock */

int Board_Refresh(void);
	/* Mengecek kartu mana saja yang terhubung langsung (satu komponen)
	   dengan kartu start */
	/* Memakai algoritma flood fill. */

void Board_Reload(void);
	/* Mengatur ulang keadaan Board setelah load game */
	/* Board_Card_Open harus sudah terisi dengan benar (sudah di-load ulang) */

void Board_PutCard(int PosY, int PosX, int Stat);
	/* Menaruh kartu di Board. Stat berisi kode kartu yang akan ditaruh */
	/* Tidak mengecek PosY, PosX, dan Stat */
	/* Parameter harus memenuhi Board_CekPut dahulu agar tidak error */

int Board_Viewmap(int pos);
	/* Mengirimkan kode isi kartu Goalcard. Memakai rumus */
	/* Penjelasan pos : 
		0 = Goalcard paling atas
		1 = Goalcard tengah
		2 = Goalcard paling bawah */
	/* Penjelasan output :
		0 = Yang dilihat kartu Gold
		1 = Yang dilihat kartu Batu */

void Board_Rockfall(int PosY, int PosX);
	/* Menghancurkan satu kartu di Board, lalu mengatur ulang status Board */
	/* Tidak mengecek PosY dan PosX */
	/* Parameter harus memenuhi Board_CekRock dahulu agar tidak error */

#endif
