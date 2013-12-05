#include <stdio.h>
#include "../adt_deck/adt-deck.h"

int Board_Card_Open[10][15];
typedef struct
{
	int LastPlayer;
	int rockfall;
	unsigned int Keluar_Kartu;
	unsigned int Sudah_Ambil;
	Deck D;
} GameStatus;


void saveGameStatus(GameStatus status)
{
	FILE *f;
	Kartu temp;
	
	f = fopen("gamestatus", "w");
	fprintf(f, "%d ", status.LastPlayer);
	fprintf(f, "%d ", status.rockfall);
	fprintf(f, "%d ", status.Keluar_Kartu);
	fprintf(f, "%d ", status.Sudah_Ambil);
	fprintf(f, "%d\n", status.D.TOP);
	while(!IsEmpty(status.D))
	{
		Draw(&status.D,  &temp);
		fprintf(f, "%d %c %c\n",  temp.ID, temp.Jenis, temp.Guna);
	}
	
	fclose(f);
}

void loadGameStatus(GameStatus status)
{
	FILE *f;
	int i;
	Kartu temp;
	
	f = fopen("gamestatus", "r");
	fscanf(f, "%d", &status.LastPlayer);
	fscanf(f, "%d", &status.rockfall);
	fscanf(f, "%d", &status.Keluar_Kartu);
	fscanf(f, "%d", &status.Sudah_Ambil);
	fscanf(f, "%d", &status.D.TOP);
	for(i = status.D.TOP; i >= 0; i++)
	{
		fprintf(f, "%d %c %c\n",  status.D[i].ID, status.D[i].Jenis, status.D[i].Guna);
	}
	fclose(f);
}


void loadCard()
//I.S. : sembarang, file savegame ada di direktori yang sama dgn executable
//F.S. : array Board_Card_Open diload dari file ke Board_Card_Open
{
	FILE * f;
	int i, j;
	
	f = fopen("savegame", "r");
	for(i=0; i < 5; i++)
	{
		for (j=0;j<9;j++){
			fscanf(f,"%d",&Board_Card_Open[i][j]);
		}
	}
	
	fclose(f);
}

void saveCard()
//I.S. : array Board_Card_Open terdefinisi
//F.S. : array Board_Card_Open disimpan ke file
{
	FILE * f;
	int i, j;
	
	f = fopen("savegame", "w");
	for(i=0; i < 5; i++)
	{
		for (j=0;j<9;j++){
			fprintf(f,"%d ",Board_Card_Open[i][j]);
		}
	}
	
	fclose(f);
}

int main()
{
	int i, j;
	GameStatus g;
	
	CreateEmpty(&g.D);

}