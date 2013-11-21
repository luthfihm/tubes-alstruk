/* ******** Mesin Karakter ******* */

#include "boolean.h"
#include <stdio.h>
#ifndef mesinkarakter
#define mesinkarakter
#define FILENAME "players.in"

extern char CC;
extern int ERROR_MESINKAR;
extern boolean EOP;
extern int retval;


void START();
/*I.S. sembarang */
/*F.S. CC adalah karakter pertama pita */
/*Jika CC==MARK, EOP menyala (true) */
/*Jika CC != MARK, EOP padam (false) */

void ADV();
/*I.S. CC != MARK */
/*F.S. CC adalah karakter berikutnya dari CC pada I.S. */
/*Jika CC==MARK, EOP menyala (true) */

void CloseFile();
/* I.S.	:FILEKU Masih terbuka
 * F.S. :FILEKU tertutp, EOP = TRUE
 */


#endif
