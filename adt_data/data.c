#include "data.h"
#include "mesinbaris.h"


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

boolean addPengguna(tabData *T, String nama, int score, int time)
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
