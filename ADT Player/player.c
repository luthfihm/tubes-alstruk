/*	----- File Include ----- */
#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "../boolean.h"
#include "../adt_deck/adt-deck.h"

/*	----- Selektor ----- */
/* String NamePlayer(ArrayofPlayer T, index i) {
	/*	Kamus Lokal */

	/*	Algoritma */
	/*return (T).Player[i].Name;
} */

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

Kartu KartuonIndex(ArrayofPlayer T, index user, index Kartus) {
	/*	Kamus Lokal */

	/* Algoritma */
	if ((Kartus > MaxKartu) || (Kartus < 1)) {
		return false;
	} else {
		return (T).Player[user].OnHand[Kartus-1];
	}
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
		if (strcmp(NamePlayer(T,i),Name) == 0) {
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
	index idxKartus;

	/* Algoritma */
	Found = false;
	idxKartus = 0;
	while ((idxKartus<MaxKartu) && (!Found)) {
		if ((T).Player[i].OnHand[idxKartus] == ID) {
			Found = true;
		} else {
			idxKartus++;
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
		CopyStr((*T).Player[i].Name,Name);
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

void CharacterofPlayer (ArrayofPlayer *T, index i, char Character) {
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
		if ((*T).Player[i].OnHand[j]==Dummy) {
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
		if ((*T).Player[i].OnHand[j]==ID) {
			Found = true;
		} else {
			j++;
		}
	}
	if (Found == true) {
		(*T).Player[i].OnHand[j] = Dummy;
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
	boolean Found = false;

	/* Algoritma */
	while ((i<MaxKartu) && !Found) {
		if (KartuonIndex(T,user,i)==Dummy) {
			Found = true;
		} else {
			i++;
		}
	}
	return i+1;
}