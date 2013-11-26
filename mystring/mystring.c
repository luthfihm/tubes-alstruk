#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

void EmptyStr (String S)
/*	I.S. S sembarang
	F.s. setiap elemen S bernilai Nil
*/
{
	/* Kamus Lokal */
	int i;
	/* Algoritma */
	for (i=0;i<255;i++){
		S[i] = 0;
	}
}

int StrLength (String S)
/* Menghasilkan panjang dari string S */
{
	/* Kamus Lokal */
	int i;
	/* Algoritma */
	i = 0;
	while (S[i] != 0){
		i++;
	}
	return i;
}

void CopyStr (String Str_in,String Str_out)
/*	I.S. Str_in mungkin kosong, Str_out Sebarang
	F.s. Str_out berisi salinan elemen dari Str_in
*/
{
	/* Kamus Lokal */
	int i;
	/* Algoritma */
	EmptyStr(Str_out);
	i = 0;
	while (Str_in[i] != 0){
		Str_out[i] = Str_in[i];
		i++;
	}
}

boolean StrEq (String S1,String S2)
/* Menghasilkan true jika panjang dan setiap elemen S1 dan S2 sama */
{
	/* Kamus Lokal */
	int i;
	boolean equal;
	/* Algoritma */
	if (StrLength(S1) == StrLength(S2)){
		i = 0;
		equal = true;
		while ((i < StrLength(S1))&&(equal)){
			if (S1[i] != S2[i]){
				equal = false;
			}else{
				i++;
			}
		}
		return equal;
	}else{
		return false;
	}
}

boolean StrLess (String S1,String S2)
/* Menghasilkan true jika S1 < S2. Kurang dari di sini dianalogikan seperti di Kamus */
{
	/* Kamus Lokal */
	int i;
	boolean IsLess,equal;
	/* Algoritma */
	i = 0;
	equal = true;
	IsLess = false;
	while ((S1[i] != 0)&&(S2[i] != 0)&&(equal)){
		if (S1[i] == S2[i]){
			i++;
		}else{
			equal = false;
			IsLess = (S1[i] < S2[i]);
		}
	}
	return IsLess;
}

boolean StrLarger (String S1,String S2)
/* Menghasilkan true jika S1 < S2. Kurang dari di sini dianalogikan seperti di Kamus */
{
	/* Kamus Lokal */
	int i;
	boolean IsLarger,equal;
	/* Algoritma */
	i = 0;
	equal = true;
	IsLarger = false;
	while ((S1[i] != 0)&&(S2[i] != 0)&&(equal)){
		if (S1[i] == S2[i]){
			i++;
		}else{
			equal = false;
			IsLarger = (S1[i] > S2[i]);
		}
	}
	return IsLarger;
}

void strConcate(String input1, String input2, String output)
/* I.S.	: input1 dan input2 berisi string yang valid
 * F.s.	: output merupakan gabungan dari input1 dan input 2
 */
{
	//Kamus
	int i, j;
	
	//Program
	i = 0;
	while ((input1[i] != '\0') && (i < MaxLength))
	{
		output[i] = input1[i];
		i++;
	}
	
	j = 0;
	
	while ((input2[j] != '\0') && (i < MaxLength))
	{
		output[i] = input2[j];
		i++;
		j++;
	}
	
	output[i] = '\0';
}


void itoa(int i, String out)
/* I.S.	:i adalah sebuah integer >= 0
 * F.S.	:out berisi i dalam bentuk string
 */
{
    char const digit[] = "0123456789";
    int pos, shift, convert;
    
    pos = 0;
    shift = i;
    convert = i;
    
    do
    {
		pos++;
		shift = shift / 10;
	} while (shift);
	
	
	out[pos] = '\0';
	
	do
	{
		pos--;
		out[pos] = digit[convert % 10];
		convert = convert /10;
	} while (convert);
	
}
