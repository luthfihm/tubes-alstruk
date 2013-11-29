#ifndef GAME_H
#define GAME_H
#include "../boolean.h"
#include "../Board/Board.h"
#include "../ADT Player/player.h"
#include "../mystring/mystring.h"

void StartGame(ArrayofPlayer *T);

void AcakKarakterPlayer (ArrayofPlayer *T);

void BagiKartu (ArrayofPlayer *T,Deck *D);

void BagiGold (ArrayofPlayer *T,char Winner);

void ShowKartuPlayer (Dataplayer P);

void ScoreBoard (ArrayofPlayer T,char Winner);

void ShowPlayerList (ArrayofPlayer T);

void GameHelp ();

void HelpHeader ();

#endif