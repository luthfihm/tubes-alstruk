#include <stdio.h>
#include "data.h"

int main()
{
	//Kamus
	tabData data;
	String date;
	String newNama, delNama;
	int i;
	
	//Program
	
	printf("Loading data from file...\n");
	
	if (!loadData(&data))
	{
		printf("Load data succesfull..\nSorting data by its score..\n");
		sortScoreDesc(&data);
		printf("Data setelah di sort:\n");
		for (i = 1; i <= data.jumlahPemain; i++)
		{
			printf("Nama: %s\n", data.TI[i].nama);
			printf("Score: %d\n", data.TI[i].score);
			
			intToWaktu(data.TI[i].time, date);
			printf("Last played: %s\n\n", date);
		}
		
		printf("Masukkan nama pengguna untuk ditambahkan ke data:\n");
		scanf("%s", newNama);
		if(IsMemberData(data, newNama))
		{
			printf("Nama pengguna sudah ada di data\n");
		} else {
			if(IsTabFull(data))
			{
				printf("Tabel penuh\n");
			} else {
				addPengguna(&data, newNama, 75, time(NULL));
				printf("Pengguna berhasil ditambahkan ke tabel data\n");
			}
		}
		
		printf("Masukkan nama pengguna untuk dihapus dari tabel:\n");
		scanf("%s", delNama);
		if(IsMemberData(data, delNama))
		{
			if(!delPengguna(&data, delNama))
			{
				printf("Pengguna gagal dihapus dari data\n");
			} else {
				printf("Pengguna berhasil dihapus dari data\n");
			}
		} else {
			printf("Nama yang anda masukkan tidak ada dalam tabel\n");
		}
		
		printf("Menyimpan data ke file...\n");
		saveData(data);
		
		printf("done..\n");
	} else {
		printf("Error loading data\n");
	}
	
	return 0;
}
