#include "mesinkarakter.h"
#include <stdio.h>
#include "boolean.h"

char CC;
int ERROR_MESINKAR;

/* definisi pita */
static char Pita_karakter[63] = FILENAME;
static FILE * FILEKU;
int retval;
boolean EOP;
void START() {
	/*I.S. sembarang */
	/*F.S. CC adalah karakter pertama pita */
	/*Jika CC==MARK, EOP menyala (true) */
	/*Jika CC != MARK, EOP padam (false) */
		
	FILEKU = fopen(Pita_karakter,"r" );
	if (FILEKU == 0)
	{
		ERROR_MESINKAR = 404;
	} else {
		retval = fscanf(FILEKU,"%c",&CC) ;
		ERROR_MESINKAR = 0;
		if (retval == EOF)
		{
			fclose(FILEKU);
			EOP = true;
		} else {
			EOP = false;
		}
	}
}

void ADV() {
	/*I.S. CC != MARK */
	/*F.S. CC adalah karakter berikutnya dari CC pada I.S. */
	/*Jika CC==MARK, EOP menyala (true) */
	
	if (!ERROR_MESINKAR){
		retval = fscanf(FILEKU,"%c",&CC) ;
		if (retval == EOF) {
			CloseFile();
		}
	}
}

void CloseFile()
/* I.S.	:FILEKU Masih terbuka
 * F.S. :FILEKU tertutp, EOP = TRUE
 */
{
	fclose(FILEKU);
	EOP = true;
}
