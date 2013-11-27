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

Kartu KartuonIndex(ArrayofPlayer T, index user, index Kartu) {
	/*	Kamus Lokal */

	/* Algoritma */
	return (T).Player[user].OnHand[Kartu-1];
}

/* 	----- Pembuatan Array Kosong ----- */
void MakeEmptyAP (ArrayofPlayer *T) {
	/*	Kamus Lokal */
	index i;

	/* Algoritma */
	for (i = 0; i < MaxPlayer; i++) {
		UpdateConditiononPlayer(T,i,Absent);
	}
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

boolean IsMemberofKartuonHand (ArrayofPlayer T, index i, Kartu ID) {
	/* Kamus Lokal */
	boolean Found;
	index idxKartu;

	/* Algoritma */
	Found = false;
	idxKartu = 0;
	while ((idxKartu<MaxKartu) && (!Found)) {
		if ((T).Player[i].OnHand[idxKartu].ID == ID.ID) {
			Found = true;
		} else {
			idxKartu++;
		}
	}
	return Found;
}

/*	----- Pengolahan Elemen Array ----- */
boolean InsertPlayer (ArrayofPlayer *T, String Name) {
	/* Kamus Lokal */
	index i;

	/* Algoritma */
	if ((!IsMemberofArrayPlayer(*T,Name)) && (!IsFullofArrayPlayer(*T))) {
		i = 0;
		while (ConditionofPlayer(*T,i) != Absent) {
			i++;
		}
		CopyStr(Name,(*T).Player[i].Name);
		UpdateConditiononPlayer(T,i,Enabled);
		UpdateScoreonPlayer(T,i,0);
		return true;
	} else {
		return false;
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

void FillKartuonPlayer (ArrayofPlayer *T, index i, Kartu ID) {
	/* Kamus Lokal */
	boolean Found = false;
	index j = 0;

	/* Algoritma */
	while ((j<MaxKartu) && (!Found)) {
		if ((*T).Player[i].OnHand[j].ID == Dummy) {
			Found = true;
		} else {
			j++;
		}
	}
	if (Found == true) {
		(*T).Player[i].OnHand[j] = ID;
	}
}

void TakeKartufromPlayer (ArrayofPlayer *T, index i, Kartu ID) {
	/* Kamus Lokal */
	boolean Found = false;
	index j = 0;

	/* Algoritma */
	while ((j<MaxKartu) && (!Found)) {
		if ((*T).Player[i].OnHand[j].ID == ID.ID) {
			Found = true;
		} else {
			j++;
		}
	}
	if (Found == true) {
		(*T).Player[i].OnHand[j].ID = Dummy;
	} else {
		printf("Kartu tidak ada di tangan\n");
	}
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