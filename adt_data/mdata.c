#include <stdio.h>
#include "data.h"

int main()
{
	//Kamus
	tabData data;
	
	//Program
	CreateEmptyData(&data);
	
	addPengguna(&data, "Reza", 40, time(NULL));
	addPengguna(&data, "Muntaha", 50, time(NULL));
	addPengguna(&data, "Oji", 100, time(NULL));
	sortScoreDesc(&data);
	printf("%s\n", data.TI[3].nama);
	return 0;
}
