#include <stdio.h>
#include "tools.h"
#include "../mystring/mystring.h"
#include "../boolean.h"

void clrscr()
/*	I.S. Sembarang
	F.S. Tampilan layar menjadi kosong
*/
{
	system(clear);
}

void gotoxy(int x,int y)
/*  I.S. x dan y merupakan koordinat dalam layar
    F.S. Kursor akan terletak sesuai koordinat x,y di layar
*/
{
	printf("%c[%d;%df",0x1B,y,x);
}

void canvas()
/*	I.S. Sembarang
	F.S. Sebuah canvas/media untuk game tertampil di layar
*/
{
	char *cvs[] = {
		"=================================================================================================================",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||=============================================================================================================||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"||=============================================================================================================||",
		"||                                                                                                             ||",
		"||                                                                                                             ||",
		"=================================================================================================================",
		""
	};
	int i;
	i = 0;
	while (!StrEq(cvs[i],"")){
		printf("%s\n",cvs[i]);
		i++;
	}
}

void header()

{
	char *s[] = {
		"##### ##### ###   ##### ##### ##### #   # ####  ##### #   # #   #",
		"#     #   # #  #  #   #   #   #     #   # #   # #     #   # ##  #",
		"##### ##### ####  #   #   #   ####  #   # ####  ####  #   # # # #",
		"    # #   # #   # #   #   #   #     #   # #   # #     #   # #  ##",
		"##### #   # ####  #####   #   ##### ##### #   # ##### ##### #   #",
		""
	};
	int i,x,y;
	i = 0;
	x = 25;
	y = 2;
	while (!StrEq(s[i],"")){
		gotoxy(x,y+i);
		printf("%s\n",s[i]);
		i++;
	}
}

void BacaNama(String Nama)
{
	/* Kamus Lokal */
	char c;
	int i;
	String input;
	boolean done;
	/* Algoritma */
	i = 0;
	done = false;
	EmptyStr(input);
	do {
		c = getchar();
		if ((c != '"')&&(c != '\n' )){
			input[i] = c;
			i++;
		}
	} while ((c != '"')&&(c != '\n' ));
	//if (done){
		CopyStr(input,Nama);
	//}
}