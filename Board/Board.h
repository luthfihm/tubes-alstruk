/* * * * * * * * * * * * * * * * * * * * * * * * */
/* ADT Board v0.6 			 					 */
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
	
/* Things to do : 
	port ke linux.
		buat print board hanya pada init, 2 parameter, Posisi kiri atas board.
		ganti semua printf("\n") jadi goto.
	Buat setiap kali putcard, hanya printcard, tambah 2 parameter, posisi kartu print
*/

void Board_Init();
	/* Inisialisasi Board */
	/* Things todo :
		Cetak board jika sudah memakai goto. Tambah 2 parameter (?) */

void Board_Print(void);
	/* Cetak Board. Ukuran 9x7. Mencetak bantuan posisi juga. */
	/* Things todo:
		Tambah 2 Parameter untuk posisi kiri atas Board.
		Memakai goto. */

void Board_PrintCard(int Stat);
	/* Cetak satu kartu, sesuai kode Stat. Lihat penjelasan diatas untuk kode Stat. */
	/* Things todo:
		Menambah 2 Parameter, posisi kartu dalam Board (5x9)
		Memakai goto, jadi langsung 'mencetak' kartu di board. */

int Board_Refresh(int PosY, int PosX);
	/* Fungsi rekursif untuk mengecek kartu mana saja yang 
	   terhubung langsung (satu komponen) dengan kartu start */
	/* Memakai algoritma flood fill. Flag-nya Card_Able */
	/* Untuk mengantisipasi Rockfall, sebelum dipanggil, 
	   Card_Able, Card_Around, dan Card_Flag dikosongkan dulu. */

void Board_PutCard(int PosY, int PosX, int Stat);
	/* Menaruh kartu di Board. Stat berisi kode kartu yang akan ditaruh */
	/* Things todo:
		Langsung memanggil Printcard */

int Board_Viewmap(int pos);
	/* Mengirimkan kode isi kartu Goalcard. Memakai rumus */
	/* Penjelasan pos : 
		0 = Goalcard paling atas
		1 = Goalcard tengah
		2 = Goalcard paling bawah */
	/* Penjelasan output :
		0 = Yang dilihat kartu Batu
		1 = Yang dilihat kartu Gold */
#endif
