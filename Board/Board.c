/* * * * * * * * * * * * * * * * * * * * * * * * */
/* ADT Board v0.6			 					 */
/* By Muntaha Ilmi 13512048  					 */
/* Body 					 					 */
/* Mengatur Board. Melingkupi pencetakan Board,  */
/* Taruh kartu, viewmap, dan pengecekan kondisi  */
/* deadlock/win	untuk Saboteur/Goldminer		 */
/* * * * * * * * * * * * * * * * * * * * * * * * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Board.h"

/* Things to do : 
	port ke linux.
		buat print board hanya pada init, 2 parameter, Posisi kiri atas board.
		ganti semua printf("\n") jadi goto.
	Buat setiap kali putcard, hanya printcard, tambah 2 parameter, posisi kartu print
*/

void Board_Init(){
	/* Inisialisasi Board */
	/* Things todo :
		Cetak board jika sudah memakai goto. Tambah 2 parameter (?) */
	int i,j;
	for (i=0;i<5;i++){
		for (j=0;j<9;j++){
			Board_Card_Open[i][j]=0;
			Board_Card_Able[i][j]=0;
			Board_Card_Around[i][j]=0;
			Board_Card_Flag[i][j]=0;
		}
	}
	/* Kartu Goal */
	Board_Card_Open[0][0]=-3;
	Board_Card_Open[2][0]=-3;
	Board_Card_Open[4][0]=-3;
	/* Randomize Gold Card */
	srand(time(NULL));
	Board_Card_Open[0+2*(rand()%3)][0]=-4;
	/* Win Flag */
	Board_Win=0;
	/* Kartu Start */
	Board_Card_Flag[2][8]=1;
	Board_Card_Able[2][8]=15;
	Board_PutCard(2,8,31);
}

void Board_Print(void){
	/* Cetak Board. Ukuran 9x7. Mencetak bantuan posisi juga. */
	/* Things todo:
		Tambah 2 Parameter untuk posisi kiri atas Board.
		Memakai goto. */
	int i,j,a,b;
	char tmp1,tmp2,tmp3,tmp4,tmp5;
	#define border1 '_' /* Border datar */
	#define border2 '|' /* Border tegak */
	#define blank ' ' /* Kosong */
	#define facedown '#' /* Kartu tertutup (Goal Card) */
	//Print baris berisi nomor kolom
	printf("  ");
	for (j=0;j<9;j++){
		printf("    %c    ",'1'+j);
	}
	printf("\n");
	for (i=0;i<5;i++){
		//Print border atas kartu
		printf("  ");
		for (j=0;j<9;j++){
			printf(" ");
			for (b=0;b<7;b++){
				printf("%c",border1);
			}
			printf(" ");
		}
		printf("\n");
		for (a=0;a<5;a++){
			//Print kolom beris huruf baris
			if (a==2)printf("%c ",'A'+i);
			else printf("  ");
			for (j=0;j<9;j++){
				//Print kartu.
				tmp1=blank;tmp2=blank;tmp3=blank;tmp4=blank;tmp5=blank;
				switch(a){
					case 0: if (Board_Card_Open[i][j]<0){
								// Card == Goalcard
								if (Board_Card_Open[i][j]<-2){
									// Tertutup
									tmp3=facedown;
									tmp2=facedown;
									tmp1=facedown;
								} else {
									// Kebuka
									tmp2=border2;
									/*if (Board_Card_Open[i][j]==-1){
										//Batu
										//???
									} else {
										//Emas
										//???
									}*/
								}
							} else {
								if (Board_Card_Open[i][j]&1){
									tmp2=border2;
									if (!((Board_Card_Open[i][j]>>4)&1)){
										tmp1=border1;
									}
								}
							}
							printf("%c%c%c%c%c%c%c%c%c",border2,tmp3,tmp3,tmp2,tmp1,tmp2,tmp3,tmp3,border2);
							break;
					case 1: if (Board_Card_Open[i][j]<0){
								// Card == Goalcard
								if (Board_Card_Open[i][j]<-2){
									// Tertutup
									tmp1=facedown;
									tmp2=facedown;
									tmp3=facedown;
									tmp4=facedown;
								} else {
									// Kebuka
									tmp2=border2;
									tmp3=border1;
									tmp4=border1;
									/*if (Board_Card_Open[i][j]==-1){
										//Batu
										//???
									} else {
										//Emas
										//???
									}*/
								}
							} else {
								if ((Board_Card_Open[i][j]>>1)&1){
									tmp3=border1;
								}
								if ((Board_Card_Open[i][j]>>3)&1){
									tmp4=border1;
								}
								if ((Board_Card_Open[i][j]>>4)&1){
									if (Board_Card_Open[i][j]&1){
										tmp2=border2;
									} else {
										tmp1=border1;
									}
								}
							}
							printf("%c%c%c%c%c%c%c%c%c",border2,tmp3,tmp3,tmp2,tmp1,tmp2,tmp4,tmp4,border2);
							break;
					case 2: if (Board_Card_Open[i][j]<0){
								// Card == Goalcard
								if (Board_Card_Open[i][j]<-2){
									// Tertutup
									tmp1=facedown;
									tmp2=facedown;
									tmp3=facedown;
									tmp4=facedown;
									tmp5=facedown;
								} else {
									// Kebuka
									tmp3=border1;
									tmp4=border1;
									if (Board_Card_Open[i][j]==-1){
										//Batu
										tmp1='R';
									} else {
										//Emas
										tmp1='G';
									}
								}
							} else {
								if ((Board_Card_Open[i][j]>>1)&1){
									tmp3=border1;
								}
								if ((Board_Card_Open[i][j]>>3)&1){
									tmp4=border1;
								}
								if ((Board_Card_Open[i][j]>>4)&1){
									if (!((Board_Card_Open[i][j]>>1)&1)){
										tmp2=border2;
									}
									if (!((Board_Card_Open[i][j]>>3)&1)){
										tmp5=border2;
									}
									if (!((Board_Card_Open[i][j]>>2)&1)){
										tmp1=border1;
									}
								} else {
									if ((Board_Card_Open[i][j]>>1)&1){
										tmp2=border2;
									}
									if ((Board_Card_Open[i][j]>>3)&1){
										tmp5=border2;
									}
								}
							}
							printf("%c%c%c%c%c%c%c%c%c",border2,tmp3,tmp3,tmp2,tmp1,tmp5,tmp4,tmp4,border2);
							break;
					case 3: if (Board_Card_Open[i][j]<0){
								// Card == Goalcard
								if (Board_Card_Open[i][j]<-2){
									// Tertutup
									tmp3=facedown;
									tmp2=facedown;
									tmp1=facedown;
								} else {
									// Kebuka
									tmp2=border2;
									/*if (Board_Card_Open[i][j]==-1){
										//Batu
										//???
									} else {
										//Emas
										//???
									}*/
								}
							} else {
								if ((Board_Card_Open[i][j]>>2)&1){
									tmp2=border2;
									if (!((Board_Card_Open[i][j]>>4)&1)){
										tmp2=blank;
										tmp1=border1;
									}
								}
							}
							printf("%c%c%c%c%c%c%c%c%c",border2,tmp3,tmp3,tmp2,tmp1,tmp2,tmp3,tmp3,border2);
							break;
					case 4: if (Board_Card_Open[i][j]<0){
								// Card == Goalcard
								if (Board_Card_Open[i][j]<-2){
									// Tertutup
									tmp3=facedown;
									tmp2=facedown;
									tmp1=facedown;
								} else {
									// Kebuka
									tmp1=border1;
									tmp2=border2;
									tmp3=border1;
									/*if (Board_Card_Open[i][j]==-1){
										//Batu
										//???
									} else {
										//Emas
										//???
									}*/
								}
							} else {
								tmp1=border1;
								tmp2=border1;
								tmp3=border1;
								if ((Board_Card_Open[i][j]>>2)&1){
									tmp2=border2;
								}
							}
							printf("%c%c%c%c%c%c%c%c%c",border2,tmp3,tmp3,tmp2,tmp1,tmp2,tmp3,tmp3,border2);
							break;
				}
			}
			printf("\n");
		}
	}
	#undef border1
	#undef border2
	#undef blank
	#undef facedown
}

void Board_PrintCard(int Stat){
	/* Cetak satu kartu, sesuai kode Stat. Lihat penjelasan diatas untuk kode Stat. */
	/* Things todo:
		Menambah 2 Parameter, posisi kartu dalam Board (5x9)
		Memakai goto, jadi langsung 'mencetak' kartu di board. */
	int a,b;
	char tmp1,tmp2,tmp3,tmp4,tmp5;
	#define border1 '_' /* Border datar */
	#define border2 '|' /* Border tegak */
	#define blank ' ' /* Kosong */
	#define facedown '#' /* Kartu tertutup (Goal Card) */
	for (a=0;a<5;a++){
		//Print kartu
		tmp1=blank;tmp2=blank;tmp3=blank;tmp4=blank;tmp5=blank;
		switch(a){
			case 0: if (Stat<0){
						// Card == Goalcard
						if (Stat<-2){
							// Tertutup
							tmp3=facedown;
							tmp2=facedown;
							tmp1=facedown;
						} else {
							// Kebuka
							tmp2=border2;
							/*if (Stat==-1){
								//Batu
								//???
							} else {
								//Emas
								//???
							}*/
						}
					} else {
						if (Stat&1){
							tmp2=border2;
							if (!((Stat>>4)&1)){
								tmp1=border1;
							}
						}
					}
					printf("%c%c%c%c%c%c%c%c%c",border2,tmp3,tmp3,tmp2,tmp1,tmp2,tmp3,tmp3,border2);
					break;
			case 1: if (Stat<0){
						// Card == Goalcard
						if (Stat<-2){
							// Tertutup
							tmp1=facedown;
							tmp2=facedown;
							tmp3=facedown;
							tmp4=facedown;
						} else {
							// Kebuka
							tmp2=border2;
							tmp3=border1;
							tmp4=border1;
							/*if (Stat==-1){
								//Batu
								//???
							} else {
								//Emas
								//???
							}*/
						}
					} else {
						if ((Stat>>1)&1){
							tmp3=border1;
						}
						if ((Stat>>3)&1){
							tmp4=border1;
						}
						if ((Stat>>4)&1){
							if (Stat&1){
								tmp2=border2;
							} else {
								tmp1=border1;
							}
						}
					}
					printf("%c%c%c%c%c%c%c%c%c",border2,tmp3,tmp3,tmp2,tmp1,tmp2,tmp4,tmp4,border2);
					break;
			case 2: if (Stat<0){
						// Card == Goalcard
						if (Stat<-2){
							// Tertutup
							tmp1=facedown;
							tmp2=facedown;
							tmp3=facedown;
							tmp4=facedown;
							tmp5=facedown;
						} else {
							// Kebuka
							tmp3=border1;
							tmp4=border1;
							if (Stat==-1){
								//Batu
								tmp1='R';
							} else {
								//Emas
								tmp1='G';
							}
						}
					} else {
						if ((Stat>>1)&1){
							tmp3=border1;
						}
						if ((Stat>>3)&1){
							tmp4=border1;
						}
						if ((Stat>>4)&1){
							if (!((Stat>>1)&1)){
								tmp2=border2;
							}
							if (!((Stat>>3)&1)){
								tmp5=border2;
							}
							if (!((Stat>>2)&1)){
								tmp1=border1;
							}
						} else {
							if ((Stat>>1)&1){
								tmp2=border2;
							}
							if ((Stat>>3)&1){
								tmp5=border2;
							}
						}
					}
					printf("%c%c%c%c%c%c%c%c%c",border2,tmp3,tmp3,tmp2,tmp1,tmp5,tmp4,tmp4,border2);
					break;
			case 3: if (Stat<0){
						// Card == Goalcard
						if (Stat<-2){
							// Tertutup
							tmp3=facedown;
							tmp2=facedown;
							tmp1=facedown;
						} else {
							// Kebuka
							tmp2=border2;
							/*if (Stat==-1){
								//Batu
								//???
							} else {
								//Emas
								//???
							}*/
						}
					} else {
						if ((Stat>>2)&1){
							tmp2=border2;
							if (!((Stat>>4)&1)){
								tmp2=blank;
								tmp1=border1;
							}
						}
					}
					printf("%c%c%c%c%c%c%c%c%c",border2,tmp3,tmp3,tmp2,tmp1,tmp2,tmp3,tmp3,border2);
					break;
			case 4: if (Stat<0){
						// Card == Goalcard
						if (Stat<-2){
							// Tertutup
							tmp3=facedown;
							tmp2=facedown;
							tmp1=facedown;
						} else {
							// Kebuka
							tmp1=border1;
							tmp2=border2;
							tmp3=border1;
							/*if (Stat==-1){
								//Batu
								//???
							} else {
								//Emas
								//???
							}*/
						}
					} else {
						tmp1=border1;
						tmp2=border1;
						tmp3=border1;
						if ((Stat>>2)&1){
							tmp2=border2;
						}
					}
					printf("%c%c%c%c%c%c%c%c%c",border2,tmp3,tmp3,tmp2,tmp1,tmp2,tmp3,tmp3,border2);
					break;
		}
		printf("\n");
	}
	#undef border1
	#undef border2
	#undef blank
	#undef facedown
}

int Board_Refresh(int PosY, int PosX){
	/* Fungsi rekursif untuk mengecek kartu mana saja yang 
	   terhubung langsung (satu komponen) dengan kartu start */
	/* Memakai algoritma flood fill. Flag-nya Card_Able */
	/* Untuk mengantisipasi Rockfall, sebelum dipanggil, 
	   Card_Able, Card_Around, dan Card_Flag dikosongkan dulu. */
	int i,tmp,tmp2,ans;
	tmp=((Board_Card_Open[PosY][PosX]>>2)&3)+(Board_Card_Open[PosY][PosX]<<2);
	tmp2=1;
	ans=0;
	for (i=0;i<4;i++){
		//Cek Kartu sekitar
		if ((0<=(PosY+Board_MoveY[i]))&&((PosY+Board_MoveY[i])<=4)&&(0<=(PosX+Board_MoveX[i]))&&((PosX+Board_MoveX[i])<=8)){
			//Kartu berada dalam board
			if ((tmp&tmp2)&&(!(Board_Card_Able[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]))&&((Board_Card_Open[PosY][PosX]>>4)&1)){
				//Syarat menghubungkan kartu lain: terhubung, dan penghubung bukan jalan buntu.
				//Board_Card_Able dipakai untuk flag agar tidak ke kartu sama 2x
				Board_Card_Able[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]|=(tmp&tmp2);
				Board_Card_Around[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]|=(tmp2);
				if (Board_Card_Open[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]<-2){
					//Di sebelah Goalcard
					Board_Card_Open[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]+=2;
					if (Board_Card_Open[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]==-2){
						//Kebuka kartu emas
						Board_Win=1;
					}
				} else if (Board_Card_Open[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]>0){
					//Rekursif
					ans+=Board_Refresh(PosY+Board_MoveY[i],PosX+Board_MoveX[i]);
				} else if (Board_Card_Open[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]==0){
					//Kartu kosong. Boleh ditaruh kartu.
					Board_Card_Flag[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]=1;
					ans+=1;
				}
			} else {
				Board_Card_Able[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]|=(tmp&tmp2);
				Board_Card_Around[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]|=(tmp2);
			}
		}
		tmp2<<=1;
	}
	return ans;
}

void Board_PutCard(int PosY, int PosX, int Stat){
	/* Menaruh kartu di Board. Stat berisi kode kartu yang akan ditaruh */
	/* Things todo:
		Langsung memanggil Printcard */
	int i,j,tmp,tmp2;
	int a,b;
	if (Board_Card_Open[PosY][PosX]){
		printf("Position occupied\n");
	} else {
		if (Board_Card_Flag[PosY][PosX]){
			//Cek kartu terhubung langsung dengan start/tidak
			a=(Stat&15)&Board_Card_Around[PosY][PosX];
			b=(Board_Card_Able[PosY][PosX])&Board_Card_Around[PosY][PosX];
			if (!(a^b)){
				//Cek bentuk kartu, sesuai dengan kartu sekitar/tidak
				Board_Card_Open[PosY][PosX]=Stat;
				//Reset semua status kartu diboard, terhubung dengan start/tidak
				for (i=0;i<5;i++){
					for (j=0;j<9;j++){
						Board_Card_Able[i][j]=0;
						Board_Card_Around[i][j]=0;
						Board_Card_Flag[i][j]=0;
					}
				}
				Board_Card_Able[2][8]=15;
				tmp=Board_Refresh(2,8);
				tmp2=0;
				//Cek status goalcard.
				if (Board_Card_Open[0][0]>-3){
					//Terbuka
					tmp2++;
				} else if ((!(Board_Card_Flag[0][0]))&&(Board_Card_Around[0][0]==12)){
					//Tidak bisa dibuka
					//if rockfall habis
					tmp2++;
				}
				if (Board_Card_Open[2][0]>-3){
					//Terbuka
					tmp2++;
				} else if ((!(Board_Card_Flag[2][0]))&&(Board_Card_Around[2][0]==13)){
					//Tidak bisa dibuka
					//if rockfall habis
					tmp2++;
				}
				if (Board_Card_Open[4][0]>-3){
					//Terbuka
					tmp2++;
				} else if ((!(Board_Card_Flag[4][0]))&&(Board_Card_Around[4][0]==9)){
					//Tidak bisa dibuka
					//if rockfall habis
					tmp2++;
				}
				if (Board_Win){
					//Gold card terbuka
					//???
					printf("Gold Miner!\n");
				} else if ((tmp==0)||(tmp2==3)){
					//Stalemate. Tidak ada kartu yg bisa ditaruh/ Goldcard tidak bisa dicapai
					printf("Sabotaged!\n");
					Board_Win=-1;
				}
			} else {
				printf("Wrong Shape\n");
			}
		} else {
			printf("Not Connected\n");
		}
	}
}

int Board_Viewmap(int pos){
	/* Mengirimkan kode isi kartu Goalcard. Memakai rumus */
	/* Penjelasan pos : 
		0 = Goalcard paling atas
		1 = Goalcard tengah
		2 = Goalcard paling bawah */
	/* Penjelasan output :
		0 = Yang dilihat kartu Batu
		1 = Yang dilihat kartu Gold */
	//Rumus
	return !(Board_Card_Open[(pos-1)*2][0]%2);
}
