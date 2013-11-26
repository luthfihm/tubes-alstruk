#include "data.h"
#include "../mesinbaris/mesinbaris.h"
#include "../tools/tools.h"

/* ******* Deklarasi Fungsi-Fungsi yang dibutuhkan loadData() ****** */
void extractName(char * baris, int * i, char * name, int * err);
/* baris berisi sebuah baris yang akan diekstrak namanya,
 * i berisi 0
 * Fungsi ini mengembalikan 0 jika nama berhasil diekstrak dari baris.
 */
 
void extractScore(char * baris, int * i, int * score, int *err);
//i : posisi  score di baris

void extractDate(char * baris, int i, time_t * t, int *err);


//Konstruktor
void CreateEmptyData(tabData *T)
//Menghasilkan T yang kosong
{
	(*T).jumlahPemain = 0;
}

//****** Pengecekan terhadap kondisi tabel **********/
boolean IsTableEmpty(tabData T)
//Menghasilkan true jika tabel kosong
{
	return (T).jumlahPemain == 0;
}
boolean IsTabFull(tabData T)
//Menghasilkan true jika tabel penuh
{
	return (T).jumlahPemain == MaxPlayer;
}

boolean IsMemberData(tabData T, String nama)
//Menghasilkan true jika pengguna dengan nama tersebut sudah ada di tabel
{
	//Kamus
	int i;
	boolean found;
	
	//Progrma
	if (IsTableEmpty(T))
	{
		return false;
	} else {
		i = 1;
		found = false;
		while ((i <= T.jumlahPemain) && (!found))
		{
			if (StrEq(T.TI[i].nama, nama))
			{
				found = true;
			} else {
				i++;
			}
		}
		
		return found;
	}
}

boolean addPengguna(tabData *T, String nama, int score, time_t time)
/* Menambahkan data pengguna ke dalam tabel. Tabel mungkin penuh. Jika 
 * data berhasil ditambahkan ke tabel menghasilkan true. Nama harus dicek terlebih dahulu keunikannya
 */
{
	//Kamus
	
	//Program
	if (IsTabFull(*T))
	{
		return false;
	} else {
		(*T).jumlahPemain++;
		CopyStr(nama, (*T).TI[(*T).jumlahPemain].nama);
		(*T).TI[(*T).jumlahPemain].score = score;
		(*T).TI[(*T).jumlahPemain].time = time;
		return true;
	}
		
}

boolean delPengguna(tabData *T, String nama)
/* Menghapus pengguna dengan nama pengguna dari tabel.
 */
{
	//Kamus
	int i;
	//Program
	i = 1;
	
	
	while (!StrEq(nama, T->TI[i].nama) && (i <= T->jumlahPemain))
	{
		i++;
	}
	
	if (!StrEq(T->TI[i].nama, nama))
	{
		return false;
	} else {
		if (i != T->jumlahPemain)
		{
			while (i < T->jumlahPemain)
			{
				CopyStr(T->TI[i+1].nama, T->TI[i].nama);
				T->TI[i].score = T->TI[i+1].score;
				T->TI[i].time = T->TI[i+1].time;
				i++;
			}
		}
		
		T->jumlahPemain = T->jumlahPemain - 1;
		
		return true;
	}
}


void PrintPengguna(tabData T)
{
	/* I.S.	:T terdefinisi
	 * F.S.	:Pengguna tercetak di layar
	 */
	
	//Kamus
	int i,x,y;
	String waktu;
	
	//Program
	i = 1;
	x = 20;
	y = 10;
	gotoxy(x,y);
	printf("Rank");
	gotoxy(x+8,y);
	printf("Name");
	gotoxy(x+35,y);
	printf("Score");
	gotoxy(x+45,y);
	printf("Time");
	while (i <= T.jumlahPemain){
		gotoxy(x,y+i);
		printf("%d.",i);
		gotoxy(x+8,y+i);
		printf("%s", T.TI[i].nama);
		gotoxy(x+37,y+i);
		printf("%3d",T.TI[i].score);
		intToWaktu(T.TI[i].time,waktu);
		gotoxy(x+45,y+i);
		printf("%s",waktu);
		i++;
	}
}

//Procedure Sort
void sortScoreDesc(tabData *T)
/* I.S.	:Tab T terdefinisi
 * F.S	:Data pada tabel terurut menurun berdasarkana score
 */
{
	//Kamus
	int i, j, max;
	Data temp;
	
	//Program
	if (!IsTableEmpty(*T))
	{
		for (i = 1; i <= (*T).jumlahPemain; i++)
		{
			max = i;
			for(j = i +1; j <= (*T).jumlahPemain; j++)
			{
				if ((*T).TI[j].score > (*T).TI[max].score)
				{
					max = j;
				}
			}
			
			//tukar posisi pemain
			CopyStr((*T).TI[max].nama, temp.nama);
			temp.score = (*T).TI[max].score;
			temp.time = (*T).TI[max].time;
			
			CopyStr((*T).TI[i].nama, (*T).TI[max].nama);
			(*T).TI[max].time = (*T).TI[i].time;
			(*T).TI[max].score = (*T).TI[i].score;
			
			CopyStr(temp.nama, (*T).TI[i].nama);
			(*T).TI[i].time = temp.time;
			(*T).TI[i].score = temp.score;
			
		}
	}	
}

void intToWaktu(time_t waktu, String output)
//Mengkonversi waktu menjadi string dengan format yyyy-mm-dd<spasi>hh:mm
{
	//Kamus
	struct tm * decodedTime;

	
	//Program
	decodedTime = localtime(&waktu);
	strftime(output, MaxLength, "%F %R", decodedTime);
	
	
}


int loadData(tabData *T)
/* Meload data dari file ke tabel. Menghasilkan 0 jika berhasil.
 * Pesan error:	* 422: Invalid Format
 * 				* 404: File Not Found atau Access denied
 */
{
	//Kamus
	int i, score;
	String nama;
	time_t waktu;
	
	//Algoritma
	STARTBARIS();
	CreateEmptyData(T);
			
	while ((!ERROR_MESINBARIS) && (!EOD()))
	{
		
		ADVBARIS();		
		if (!EOD())
		{
			i = 0;
			extractName(BARIS, &i, nama, &ERROR_MESINBARIS);
		
			if (!ERROR_MESINBARIS)
			{
				i = i +2;
			
				extractScore(BARIS, &i, &score, &ERROR_MESINBARIS);
			
				if (!ERROR_MESINBARIS)
				{	
					i = i + 1;
				
					extractDate(BARIS, i, &waktu, &ERROR_MESINBARIS);
								
					if(!ERROR_MESINBARIS)
					{
						addPengguna(T, nama, score, waktu);
									
					}	
				}
			} 
		} 
	}
	
	return ERROR_MESINBARIS;
}

int saveData(tabData T)
/* Mensave tabel T ke file sesuai dengan definisi di mesinkarakter.h. Return 0 jika berhasil, 403 jika gagal
 */
{
	//Kamus
	FILE * F;
	int i;
	String baris, lastPlay, score;
	
	//Program
	F = fopen(FILENAME, "w");
	
	if (F == NULL)
	{
		return 403;
	} else {
		fprintf(F, "%s\n", "@players");
		
		for (i = 1; i <= T.jumlahPemain; i++)
		{
			//Konversi time dan score ke bentuk string sesuai dgn spek
			intToWaktu(T.TI[i].time, lastPlay);
			itoa(T.TI[i].score, score);
			
			//Isi baris dengan data pengguna
			CopyStr("\"", baris);
			strConcate(baris, T.TI[i].nama, baris);
			strConcate(baris, "\" ", baris);
			strConcate(baris, score, baris);
			strConcate(baris, " ", baris);
			strConcate(baris, lastPlay, baris);
			printf("%s\n", baris);
			
			//Tuliskan isi baris ke file
			fprintf(F, "%s\n", baris);
		}
		
		fprintf(F, "%s\n", "@end");
		fclose(F);
	}
}

// *********** Fungsi-Fungsi yang dibutuhkan loadData() **************
void extractName(char * baris, int * i, char * name, int * err)
/* baris berisi sebuah baris yang akan diekstrak namanya,
 * i berisi 0
 * Fungsi ini mengembalikan 0 jika nama berhasil diekstrak dari baris.
 */
{
	if (baris[0] != '"')
	{
		*err = 422;
	} else {
		*i = 1;
		
		while ((baris[*i] != '"') && (baris[*i] != '\0') && (*i < MaxLength))
		{
			name[(*i)-1] = baris[*i];
			(*i)++;
		}
		
		name[(*i)-1] = '\0';
		if (baris[*i] == '"')
		{
			*err = 0;
		} else {
			*err = 422;
		}
	}
}

void extractScore(char * baris, int * i, int * score, int *err)
//i : posisi  score di baris
{
	char scoreChar [MaxLength];
	int j;
	
	j = 0;
	while ((baris[*i] != ' ') && (*i < MaxLength))
	{
		scoreChar[j] = baris[*i];
		(*i)++;
		j++;
	}
	scoreChar[j] = '\0';
	
	*score = atoi(scoreChar);
	
	if (baris[*i] != ' ')
	{
		*err = 422;
	} else {
	
		*err = 0;
	}
	
}
		
void extractDate(char * baris, int i, time_t * t, int *err)
{
	//Kamus
	struct tm * decoded;
	int yyyy, mm, dd, hh, MM, ss;
	char temp[MaxLength];
	time_t tempTime;
	
	//Program
	
	tempTime = time(NULL);
	decoded = localtime(&tempTime);
	
	//extract tahun dari string
	temp[0] = baris[i];
	temp[1] = baris[i + 1];
	temp[2] = baris[i + 2];
	temp[3] = baris[i + 3];
	temp[4] = '\0';
	
	
	yyyy = atoi(temp) - 1900;
	
	//deteksi tanggal yang tidak valid
	if(yyyy <= 0)
	{
		*err = 422;
	} else {
		
		decoded->tm_year = yyyy;
		
		
		//extract bulan dari string
		temp[0] = baris[i + 5];
		temp[1] = baris[i + 6];
		temp[2] = '\0';
		
		mm = atoi(temp) - 1;
				
		if ((mm < 0) || (mm > 11))
		{
			*err = 422;
		} else {
			(*decoded).tm_mon = mm;
			
			
			//extract hari dari string
			
			temp[0] = baris[i+8];
			temp[1] = baris[i+9];
			temp[2] = '\0';
			
			dd = atoi(temp);
			
			if ((dd < 0) || (dd > 31))
			{
				*err = 422;
			} else {
				(*decoded).tm_mday = dd;
								
				//extract jam dari baris
				
				temp[0] = baris[i+11];
				temp[1] = baris[i+12];
				temp[2] = '\0';
				
				hh = atoi(temp);
				
				if ((hh < 0) || (hh > 23))
				{
					*err = 422;
				} else {
					
					decoded->tm_hour = hh;
					
					
					//extract menit dari string
					
					temp[0] = baris[i+14];
					temp[1] = baris[i+15];
					temp[2] = '\0';
					
					MM = atoi(temp);
					
					if ((MM < 0) || (MM > 59))
					{
						*err = 422;
					} else {
						decoded->tm_min = MM;
						
						temp[0] = baris[i+17];
						temp[1] = baris[i+18];
						temp[2] = '\0';
						
						ss = atoi(temp);
						
						if((ss < 0) || (ss > 61))
						{
							*err = 422;
						} else {
							decoded->tm_sec = ss;
							*t = mktime(decoded);
							*err = 0;
						}
					}
				}
			}
		}
	}
}
