#ifndef TOOLS_H
#define TOOLS_H

#include "../boolean.h"
#include "../mystring/mystring.h"

#define clear "clear"

void clrscr();
/*	I.S. Sembarang
	F.S. Tampilan layar menjadi kosong
*/

void gotoxy(int x,int y);
/*  I.S. x dan y merupakan koordinat dalam layar
    F.S. Kursor akan terletak sesuai koordinat x,y di layar
*/

void canvas();
/*	I.S. Sembarang
	F.S. Sebuah canvas/media untuk game tertampil di layar
*/

void header();

void BacaNama(String Nama);

#endif