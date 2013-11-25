#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "mystring/mystring.h"
#include "tools/tools.h"

int main(){
	/* Kamus */
	String opt,nama,pesan;
	int i;
	boolean alert;
	char c;
	/* Algoritma */
	alert = false;
	do {
		clrscr();
		canvas();
		header();
		if (alert){
			gotoxy(5,34);
			printf("%s\n",pesan);
			alert = false;
		}
		gotoxy(5,33);
		printf("> ");scanf("%s",opt);
		if (StrEq(opt,"highscore")){

		}else if (StrEq(opt,"viewplayers")){

		}else if (StrEq(opt,"add")){
			EmptyStr(nama);
			i = 0;
			do {
				c = getchar();
				if ((c != '\n')&&(c != ' ')){
					nama[i] = c;
					i++;
				}
			}while(c!='\n');
			if (StrLength(nama)!=0){

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
				if ((c != '\n')&&(c != ' ')){
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