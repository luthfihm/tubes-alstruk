#include <stdio.h>
#include "data.h"

int main()
{
	//Kamus
	tabData data;
	String date;
	int i;
	
	//Program

	
	if (!loadData(&data))
	{
		sortScoreDesc(&data);
		for (i = 1; i <= data.jumlahPemain; i++)
		{
			printf("Nama: %s\n", data.TI[i].nama);
			printf("Score: %d\n", data.TI[i].score);
			
			intToWaktu(data.TI[i].time, date);
			printf("Last played: %s\n\n", date);
		}
		addPengguna(&data, "Oji", 75, time(NULL));
		printf ("%d\n", delPengguna(&data, "Oji"));
		saveData(data);
	} else {
		printf("Error\n");
	}
	
	return 0;
}
