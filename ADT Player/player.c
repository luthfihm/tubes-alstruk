/*	----- Konstanta ----- */
#define Dummy -999

/*	----- File Include ----- */
#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "../boolean.h"

/*	----- Selektor ----- */
Dataplayer NamePlayer(ArrayofPlayer T, index i) {
	/*	Kamus Lokal */

	/*	Algoritma */
	return (T).Player[i];
}

char CharacterofPlayer(ArrayofPlayer T, index i) {
	/*	Kamus Lokal */

	/*	Algoritma */
	return (T).Player[i].Character;
}

char ConditionofPlayer(ArrayofPlayer T, index i) {
	/*	Kamus Lokal */

	/*	Algoritma */
	return (T).Player[i].Condition;
}

int ScorePlayer(ArrayofPlayer T, index i) {
	/*	Kamus Lokal */

	/*	Algoritma */
	return (T).Player[i].Score;
}

index GetPlayerIdx (ArrayofPlayer T,String Nama)
{
	/* Kamus Lokal */
	index i;
	boolean Found;
	/* Algoritma */
	i = 0;
	Found = false;
	while ((i < NbPlayer(T))&&(!Found)){
		if (StrEq(T.Player[i].Name,Nama)){
			Found = true;
		}else{
			i++;
		}
	}
	if (Found){
		return i;
	}else{
		return IdxUndef;
	}
}

Kartu KartuonIndex(ArrayofPlayer T, index user, index Kartu) {
	/*	Kamus Lokal */

	/* Algoritma */
	return (T).Player[user].OnHand[Kartu-1];
}

/* 	----- Pembuatan Array Kosong ----- */
void MakeEmptyAP (ArrayofPlayer *T) {
	/*	Kamus Lokal */
	//index i;

	/* Algoritma */
	/*
	for (i = 0; i < MaxPlayer; i++) {
		UpdateConditiononPlayer(T,i,Absent);
	}*/
	NbPlayer(*T) = 0;
}

/*	----- Predikat ----- */
boolean IsMemberofArrayPlayer (ArrayofPlayer T, String Name) {
	/*	Kamus Lokal */
	index i;
	boolean Found;

	/*	Algoritma */
	i = 0;
	Found = false;
	while ((i < MaxPlayer) && (!Found)) {
		if (StrEq(T.Player[i].Name,Name)) {
			Found = true;
		}
		i = i + 1;
	}
	return Found;
}

boolean IsFullofArrayPlayer (ArrayofPlayer T) {
	/* Kamus Lokal */

	/* Algoritma */
	return (NbPlayer(T)==MaxPlayer);
}

boolean IsLessMinofArrayPlayer (ArrayofPlayer T) {
	/* Kamus Lokal */

	/* Algoritma */
	return (NbPlayer(T)<MinPlayer);
}

boolean IsMemberofKartuonHand (ArrayofPlayer T, index i, String Nama) {
	/* Kamus Lokal */
	boolean Found;
	index idxKartu;

	/* Algoritma */
	Found = false;
	
	return Found;
}

/*	----- Pengolahan Elemen Array ----- */
void InsertPlayer (ArrayofPlayer *T, String Name) {
	/* Kamus Lokal */
	index i;
	char c;

	/* Algoritma */
	if ((!IsMemberofArrayPlayer(*T,Name)) && (!IsFullofArrayPlayer(*T))) {
		i = NbPlayer(*T);
		/*while (ConditionofPlayer(*T,i) != Absent) {
			i++;
		}*/
		CopyStr(Name,(*T).Player[i].Name);
		UpdateConditiononPlayer(T,i,Enabled);
		UpdateScoreonPlayer(T,i,0);
		NbPlayer(*T)++;
		
	}
}

void UpdateScoreonPlayer (ArrayofPlayer *T, index i, int Score) {
	/* Kamus Lokal */

	/* Algoritma */
	(*T).Player[i].Score = Score;
}

void UpdateConditiononPlayer (ArrayofPlayer *T, index i, char Condition) {
	/* Kamus Lokal */

	/* Algoritma */
	(*T).Player[i].Condition = Condition;
}

void UpdateCharacterofPlayer (ArrayofPlayer *T, index i, char Character) {
	/* Kamus Lokal */

	/* Algoritma */
	(*T).Player[i].Character = Character;
}

void FillKartuonPlayer (ArrayofPlayer *T, index i, Kartu C) {
	/* Kamus Lokal */
	int n;
	/* Algoritma */
	n = (*T).Player[i].NKartu;
	(*T).Player[i].OnHand[n].ID = C.ID;
	(*T).Player[i].OnHand[n].Jenis = C.Jenis;
	(*T).Player[i].OnHand[n].Guna = C.Guna;
	(*T).Player[i].NKartu++;
}

boolean TakeKartufromPlayer (ArrayofPlayer *T, index i,String Card, Kartu *C) {
	/* Kamus Lokal */
	boolean Found = false;
	String Nama;
	index j = 0;
	/* Algoritma */
	while ((j < (*T).Player[i].NKartu)&&(!Found)){
		EmptyStr(Nama);
		NamaKartu((*T).Player[i].OnHand[j],Nama);
		if (StrEq(Nama,Card)){
			(*C).ID = (*T).Player[i].OnHand[j].ID;
			(*C).Jenis = (*T).Player[i].OnHand[j].Jenis;
			(*C).Guna = (*T).Player[i].OnHand[j].Guna;
			Found = true;
		}else{
			j++;
		}
	}
	if (Found){
		while (j < ((*T).Player[i].NKartu-1)){
			(*T).Player[i].OnHand[j].ID = (*T).Player[i].OnHand[j+1].ID;
			(*T).Player[i].OnHand[j].Jenis = (*T).Player[i].OnHand[j+1].Jenis;
			(*T).Player[i].OnHand[j].Guna = (*T).Player[i].OnHand[j+1].Guna;
			j++;
		}
		(*T).Player[i].NKartu--;
	}
	return Found;
}

/*	----- Penghitungan Character ----- */
int NbSaboteur (ArrayofPlayer T) {
	/* Kamus Lokal */

	/* Algoritma */
	return (NbPlayer(T) - 1)/2;
}

int NbGoldMiner (ArrayofPlayer T) {
	/* Kamus Lokal */

	/* Algoritma */
	return (NbPlayer(T) - NbSaboteur(T));
}

/*	----- Penghitungan Kartu ----- */
int KartuOnHand (ArrayofPlayer T, index user) {
	/* Kamus Lokal */
	index i = 0;
	int jumlah = 0;

	/* Algoritma */
	while (i<MaxKartu) {
		if (T.Player[user].OnHand[i].ID != Dummy) {
			jumlah++;
		}
		i++;
	}
	return jumlah;
}