#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "mystring/mystring.h"
#include "tools/tools.h"
#include "adt_data/data.h"

int main(){
	/* Kamus */
	String opt,nama,pesan;
	tabData Data;
	int i;
	boolean alert,v_pengguna;
	char c;
	/* Algoritma */
	alert = false;
	v_pengguna = false;
	CreateEmptyData(&Data);
	do {
		clrscr();
		canvas();
		header();
		if (alert){
			gotoxy(5,35);
			printf("%s\n",pesan);
			alert = false;
		}
		if (v_pengguna){
			PrintPengguna(Data);
			v_pengguna = false;
		}
		gotoxy(5,34);
		printf("> ");scanf("%s",opt);
		if (StrEq(opt,"highscore")){

		}else if (StrEq(opt,"viewplayers")){
			v_pengguna = true;
		}else if (StrEq(opt,"add")){
			EmptyStr(nama);
			i = 0;
			do {
				c = getchar();
				if ((c == ' ')&&(i==0)){
					
				}else if ((c != '\n')&&(c != '"')){
					nama[i] = c;
					i++;
				}
			}while(c!='\n');
			if (StrLength(nama)!=0){
				if (!IsMemberData(Data,nama)){
					if (addPengguna(&Data,nama,0,time(NULL))){
						alert = true;
						EmptyStr(pesan);
						CopyStr("Nama berhasil ditambahkan!",pesan);
					}else{
						alert = true;
						EmptyStr(pesan);
						CopyStr("Nama gagal ditambahkan!",pesan);
					}
				}else{
					alert = true;
					EmptyStr(pesan);
					CopyStr("Nama sudah ada!",pesan);
				}
			}else{
				alert = true;
				EmptyStr(pesan);
				CopyStr("Input nama belum dimasukan. Format masukan 'add <nama>'",pesan);
			}
		}else if (StrEq(opt,"delete")){
			EmptyStr(nama);
			i = 0;
			do {
				c = getchar();
			} while(c == ' ');
			do {
				c = getchar();
				if ((c != '\n')&&(c != '"')){
					nama[i] = c;
					i++;
				}
			}while(c!='\n');
			if (StrLength(nama)!=0){

			}else{
				alert = true;
				EmptyStr(pesan);
				CopyStr("Input nama belum dimasukan. Format masukan 'delete <nama>'",pesan);
			}
		}else if (StrEq(opt,"play")){

		}else if (StrEq(opt,"start")){

		}else if (StrEq(opt,"exit")){

		}else {
			alert = true;
			EmptyStr(pesan);
			CopyStr("Perintah tidak ditemukan!",pesan);
		}
	} while (!StrEq(opt,"exit"));
	clrscr();
	return 0;
}