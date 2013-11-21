/*	----- File Include ----- */
#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "boolean.h"
#include "kartu.h"

/*	----- Selektor ----- */
string NamePlayer(ArrayofPlayer T, index i) {
	/*	Kamus Lokal */

	/*	Algoritma */
	return (T).Player[i].Name;
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

card CardonIndex(ArrayofPlayer T, index user, index cards) {
	/*	Kamus Lokal */

	/* Algoritma */
	if ((cards > MaxCard) || (cards < 1)) {
		return false;
	} else {
		return (T).Player[user].OnHand[cards-1];
	}
}

/* 	----- Pembuatan Array Kosong ----- */
void MakeEmpty (ArrayofPlayer *T) {
	/*	Kamus Lokal */
	index i;

	/* Algoritma */
	for (i = 0; i < MaxPlayer; i++) {
		UpdateConditiononPlayer(T,i,Absent);
	}
	NbPlayer(*T) = 0;
}

/*	----- Predikat ----- */
boolean IsMemberofArrayPlayer (ArrayofPlayer T, string Name) {
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

boolean IsMemberofCardonHand (ArrayofPlayer T, index i, card ID) {
	/* Kamus Lokal */
	boolean Found;
	index idxcards;

	/* Algoritma */
	Found = false;
	idxcards = 0;
	while ((idxcards<MaxCard) && (!found)) {
		if ((T).Player[i].OnHand[idxcards] == ID) {
			Found = true;
		} else {
			idxcards++;
		}
	}
	return Found;
}

/*	----- Pengolahan Elemen Array ----- */
void InsertPlayer (ArrayofPlayer *T, string Name) {
	/* Kamus Lokal */
	index i;

	/* Algoritma */
	if ((!IsMemberofArrayPlayer(*T,Name)) && (!IsFullofArrayPlayer(*T))) {
		i = 0;
		while (ConditionofPlayer(*T,i) != Absent) {
			i++;
		}
		strcpy((T).Player[i].Name,Name);
		UpdateConditiononPlayer(T,i,Enabled);
		UpdateScoreonPlayer(T,i,0);
	} else if (IsMemberofArrayPlayer(*T,Name)) {
		printf("%s sudah ada\n",Name);
	} else {
		printf("Input melebihi batas maksimum\n");
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

void FillCardonPlayer (ArrayofPlayer *T, index i, card ID) {
	/* Kamus Lokal */
	boolean Found = false;
	index j = 0;

	/* Algoritma */
	while ((j<MaxCard) && (!Found)) {
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

void TakeCardfromPlayer (ArrayofPlayer *T, index i, card ID) {
	/* Kamus Lokal */
	boolean Found = false;
	index j = 0;

	/* Algoritma */
	while ((j<MaxCard) && (!Found)) {
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
int CardOnHand (ArrayofPlayer T, index user) {
	/* Kamus Lokal */
	index i = 0;
	boolean Found = false;

	/* Algoritma */
	while ((i<MaxCard) && !Found) {
		if (CardonIndex(T,user,i)==Dummy) {
			Found = true;
		} else {
			i++;
		}
	}
	return i+1;
}