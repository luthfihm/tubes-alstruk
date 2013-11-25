#include "data.h"
#include "../mesinbaris/mesinbaris.h"
#include "../tools/tools.h"

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

void PrintPengguna(tabData T)
{
	int i,x,y;
	String waktu;
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
