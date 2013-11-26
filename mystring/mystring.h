#ifndef MYSTRING_H
#define MYSTRING_H

#include "../boolean.h"

/* Konstanta */
#define Nil 0
#define MaxLength 255

/* Tipe Data String */
typedef char String[MaxLength];
/*	Saat kita mendeklarasikan tipe data String yang tidak lain
	adalah array of char, di dalam bahasa C setiap elemen nilai
	ASCII akan otomatis bernilai 0 (Nil)
*/

/* PRIMITIF TIPE STRING */
void EmptyStr (String S);
/*	I.S. S sembarang
	F.s. setiap elemen S bernilai Nil
*/

int StrLength (String S);
/* Menghasilkan panjang dari string S */

void CopyStr (String Str_in,String Str_out);
/*	I.S. Str_in mungkin kosong, Str_out Sebarang
	F.s. Str_out berisi salinan elemen dari Str_in
*/

boolean StrEq (String S1,String S2);
/* Menghasilkan true jika panjang dan setiap elemen S1 dan S2 sama */

boolean StrLess (String S1,String S2);
/* Menghasilkan true jika S1 < S2. Kurang dari di sini dianalogikan seperti di Kamus */

boolean StrLarger (String S1,String S2);
/* Menghasilkan true jika S1 < S2. Kurang dari di sini dianalogikan seperti di Kamus */

void strConcate(String input1, String input2, String output);
/* I.S.	: input1 dan input2 berisi string yang valid
 * F.s.	: output merupakan gabungan dari input1 dan input 2
 */

#endif
