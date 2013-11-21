#include "mesinbaris.h"

String BARIS;
int ERROR_MESINBARIS;
static FILE *file;

void STARTBARIS()
/*I.S. sembarang */
/*F.S. BARIS adalah baris pertama file */
/*Jika BARIS==ENDMARK, EOP menyala (true) */
/*Jika BARIS != MARK, EOP padam (false) */
/*Jika tidak error, error == 0 */
{
	//Kamus
	char c;
	int i;
	
	//Program
	START();
	
	if(!ERROR_MESINKAR )
	{
		i = 0;
		while((CC != '\n') && (!EOP) && (!ERROR_MESINBARIS))
		{
			BARIS[i] = CC;
			i++;
			ADV();
			ERROR_MESINBARIS = ERROR_MESINKAR;
		}
		
		BARIS[i] = '\0';
		
		//Cek apakah berupa start mark
		if (!StrEq(BARIS, STARTMARK))
		{
			ERROR_MESINBARIS = 422;
			CloseFile();
		}
		
	}
}

void ADVBARIS()
/*I.S. BARIS != ENDMARK */
/*F.S. BARIS adalah  berikutnya dari CC pada I.S. */
/*Jika BARIS==ENDMARK, EOD menyala (true) */
{
	//Kamus 
	int i;
	
	//Program
	if (!EOD())
	{
		i = 0;
		//Hilangkan \n
		ADV();
		
		//Ambil karakter di sepanjang baris, abaikan karakter \n
		while ((CC != '\n') && (!ERROR_MESINBARIS))
		{
			BARIS[i] = CC;
			i++;
			ADV();
			ERROR_MESINBARIS = ERROR_MESINKAR;
		}
		
		//Penutup dari string
		BARIS[i] = '\0';
		
		//Jika CC = EOP sedangkan EOD == false berarti format file tidak valid
		if ((EOP) && !(EOD()))
		{
			ERROR_MESINBARIS = 422;
		}
		
	}
	
}

boolean EOD()
/* Menghasilkan true jika BARIS = ENDMARK
 */
{
	//Kamus
	
	
	//Program
	
	return StrEq(BARIS, ENDMARK);
}


