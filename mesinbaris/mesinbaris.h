#ifndef MESINBARIS_H
#define MESINBARIS_H

#include "mystring.h"
#include "mesinkarakter.h"
#include <stdio.h>

/* ******* KONSTANTA ********* */
#define STARTMARK "@players"
#define ENDMARK "@end"

/* ******* MESIN BARIS ******* */
extern String BARIS;
extern int ERROR_MESINBARIS;
/* Variable penampung error
 * 0: tidak ada error
 * 404 : tidak bisa akses file / file tidak ditemukan
 * 422 : invalid format
 */

/* ******* Fugsi dan Prosedur ****** */

void STARTBARIS();
/*I.S. sembarang */
/*F.S. BARIS adalah baris pertama file */
/*Jika BARIS==ENDMARK, EOP menyala (true) */
/*Jika BARIS != MARK, EOP padam (false) */
/*Jika tidak error, error == 0 */

void ADVBARIS();
/*I.S. BARIS != ENDMARK */
/*F.S. BARIS adalah  berikutnya dari CC pada I.S. */
/*Jika BARIS==ENDMARK, EOD menyala (true) */

boolean EOD();
/* Menghasilkan true jika BARIS = ENDMARK
 */
#endif
