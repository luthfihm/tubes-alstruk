#include "data.h"
#include "mesinbaris.h"
#include "boolean.h"

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
	return (*T).jumlahPemain == 0;
}


