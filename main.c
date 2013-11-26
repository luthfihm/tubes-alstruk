#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "mystring/mystring.h"
#include "tools/tools.h"
#include "adt_data/data.h"
#include "ADT Player/player.h"
#include "game/game.h"

int main(){
	/* Kamus */
	String opt,nama,pesan;
	tabData Data;
	ArrayofPlayer TP;
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
		printf("> ");
		i = 0;
		EmptyStr(opt);
		scanf("%s",opt);
		do {
			scanf("%c",&c);
		} while(c == ' ');
		if (StrEq(opt,"highscore")){

		}else if (StrEq(opt,"viewplayers")){
			v_pengguna = true;
		}else if (StrEq(opt,"add")){
			EmptyStr(nama);
			if (c != '\n'){
				scanf("%[^\"]s",nama);
				scanf("%c",&c);
			}
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
			if ((c != '\n')&&(c == '"')){
				i = 0;
				do {
					scanf("%c",&c);
					if ((c != '"')&&(c != '\n')){
						nama[i] = c;
						i++;
					}
				} while ((c != '"')&&(c != '\n'));
			}
			if (StrLength(nama)!=0){
				if ((IsMemberData(Data,nama))&&(!IsTableEmpty(Data))){
					
				}else{
					alert = true;
					EmptyStr(pesan);
					CopyStr("Nama tidak ada!",pesan);
				}
			}else{
				alert = true;
				EmptyStr(pesan);
				CopyStr("Input nama belum dimasukan. Format masukan 'delete <nama>'",pesan);
			}
		}else if (StrEq(opt,"play")){
			if (c != '\n'){
				do {
					scanf("%[^\"]s",nama);
					scanf("%c",&c);
					
					do {
						scanf("%c",&c);
					} while (c == ' ');
				} while (c != '\n');
			}
		}else if (StrEq(opt,"start")){
			StartGame(&TP);
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