#include <stdio.h>
#include "data.h"

int main()
{
	//Kamus
	tabData data;
	
	//Program
	CreateEmptyData(&data);
	
	addPengguna(&data, "Reza", 40, 100);
	addPengguna(&data, "Muntaha", 50, 100);
	addPengguna(&data, "Oji", 100, 100);
	sortScoreDesc(&data);
	printf("%s\n", data.TI[3].nama);
	return 0;
}
