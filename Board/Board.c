/* * * * * * * * * * * * * * * * * * * * * * * * */
/* ADT Board v1.5			 					 */
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
#ifndef _WIN32
#include "../tools/tools.h"
#endif

void Board_Init(int PosX,int PosY){
	/* Inisialisasi Board */
	/* PosX dan PosY untuk posisi kiri atas Board */
	int i,j;
	Board_PosX=PosX;
	Board_PosY=PosY;
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
	Board_PutCard(2,8,31);
}

int Board_CekPut(int PosY, int PosX, int Stat){
	/* Mengecek apakah kartu bisa ditaruh pada posisi tertentu */
	/* Kode output :
		1 = bisa ditaruh
		0 = Posisi di luar Board
		-1 = Posisi sudah ada kartu
		-2 = Tidak terhubung dengan Startcard
		-3 = Bentuk salah */
	int a,b;
	if ((0<=PosY)&&(PosY<=4)&&(0<=PosX)&&(PosX<=8)){
		if (Board_Card_Open[PosY][PosX]){
			//printf("Position occupied\n");
			return -1;
		} else {
			if (Board_Card_Flag[PosY][PosX]){ //Cek kartu terhubung langsung dengan start/tidak
				a=(Stat&15)&Board_Card_Around[PosY][PosX];
				b=(Board_Card_Able[PosY][PosX])&Board_Card_Around[PosY][PosX];
				if (!(a^b)){ //Cek bentuk kartu, sesuai dengan kartu sekitar/tidak
					//Bisa ditaruh
					return 1;
				} else {
					//printf("Wrong Shape\n");
					return -3;
				}
			} else {
				//printf("Not Connected\n");
				return -2;
			}
		}
	} else {
		//printf("Position outside board\n");
		return 0;
	}
}

int Board_CekRock(int PosY, int PosX){
	/* Mengecek apakah Rockfall bisa dilakukan pada posisi tertentu */
	/* Rockfall tidak bisa dilakukan pada kartu Start, Goalcard, dan tempat kosong */
	/* Kode output :
		1 = bisa di-rockfall
		0 = Posisi di luar Board
		-1 = Posisi rockfall adalah Startcard
		-2 = Posisi rockfall adalah Goalcard
		-3 = Tidak ada kartu di posisi tertentu */
	if ((0<=PosY)&&(PosY<=4)&&(0<=PosX)&&(PosX<=8)){
		if ((PosY==2)&&(PosX==8)){
			//printf("Can't use Rockfall in Start Card\n");
			return -1;
		} else if (Board_Card_Open[PosY][PosX]<0){
			//printf("Can't use Rockfall in Goalcard\n");
			return -2;
		} else if (Board_Card_Open[PosY][PosX]==0){
			//printf("Can't use Rockfall in Empty Space\n");
			return -3;
		} else {
			//Bisa di Rockfall
			return 1;
		}
	} else {
		//printf("Position outside board\n");
		return 0;
	}
}

void Board_Print(void){
	/* Cetak Board. Ukuran 5x9 kartu. Mencetak bantuan posisi juga. */
	int i,j,a,b;
	int PosX=Board_PosX;
	int PosY=Board_PosY;
	char tmp1,tmp2,tmp3,tmp4,tmp5,tmp6;
	#define border1 '_' // Border datar
	#define border2 '|' // Border tegak
	#define blank ' ' // Kosong
	#define facedown '#' // Kartu tertutup (Goal Card)
	#ifndef _WIN32
	gotoxy(PosX,PosY);
	#endif
	//Print baris berisi nomor kolom
	printf("  ");
	for (j=0;j<9;j++){
		printf("    %c   ",'1'+j);
	}
	#ifndef _WIN32
	PosY++;
	gotoxy(PosX,PosY);
	#else
	printf("\n");
	#endif
	//Print border atas kartu
	printf("  ");
	for (j=0;j<9;j++){
		printf(" ");
		for (b=0;b<7;b++){
			printf("%c",border1);
		}
		//printf(" ");
	}
	#ifndef _WIN32
	PosY++;
	gotoxy(PosX,PosY);
	#else
	printf("\n");
	#endif
	for (i=0;i<5;i++){
		for (a=0;a<5;a++){
			//Print kolom berisi huruf baris
			if (a==2)printf("%c ",'1'+i);
			else printf("  ");
			printf("%c",border2);
			for (j=0;j<9;j++){
				//Print kartu.
				tmp1=blank;tmp2=blank;tmp3=blank;tmp4=blank;tmp5=blank;tmp6=border2;
				switch(a){
					case 0: if (Board_Card_Open[i][j]<0){
								// Card == Goalcard
								if (Board_Card_Open[i][j]<-2){
									// Tertutup
									tmp1=facedown;tmp2=facedown;
									tmp3=facedown;tmp4=facedown;
									tmp5=facedown;
								} else {
									// Kebuka
									tmp2=border2;
									tmp4=border2;
								}
							} else {
								if (Board_Card_Open[i][j]&1){
									tmp2=border2;
									tmp4=border2;
									if (!((Board_Card_Open[i][j]>>4)&1)){
										tmp3=border1;
									}
								}
							}
							break;
					case 1: if (Board_Card_Open[i][j]<0){
								// Card == Goalcard
								if (Board_Card_Open[i][j]<-2){
									// Tertutup
									tmp1=facedown;tmp2=facedown;
									tmp3=facedown;tmp4=facedown;
									tmp5=facedown;
								} else {
									// Kebuka
									tmp1=border1;
									tmp2=border2;
									tmp4=border2;
									tmp5=border1;
								}
							} else {
								if ((Board_Card_Open[i][j]>>1)&1){
									tmp1=border1;
								}
								if ((Board_Card_Open[i][j]>>3)&1){
									tmp5=border1;
								}
								if ((Board_Card_Open[i][j]>>4)&1){
									if (Board_Card_Open[i][j]&1){
										tmp2=border2;
										tmp4=border2;
									} else {
										tmp3=border1;
										if ((Board_Card_Open[i][j]>>1)&1){
											tmp2=border1;
										}
										if ((Board_Card_Open[i][j]>>3)&1){
											tmp4=border1;
										}
									}
								}
							}
							break;
					case 2: if (Board_Card_Open[i][j]<0){
								// Card == Goalcard
								if (Board_Card_Open[i][j]<-2){
									// Tertutup
									tmp1=facedown;tmp2=facedown;
									tmp3=facedown;tmp4=facedown;
									tmp5=facedown;
								} else {
									// Kebuka
									tmp1=border1;
									tmp5=border1;
									if (Board_Card_Open[i][j]==-1){
										//Batu
										tmp3='R';
									} else {
										//Emas
										tmp3='G';
									}
								}
							} else {
								if ((Board_Card_Open[i][j]>>1)&1){
									tmp1=border1;
								}
								if ((Board_Card_Open[i][j]>>3)&1){
									tmp5=border1;
								}
								if ((Board_Card_Open[i][j]>>4)&1){
									if (!((Board_Card_Open[i][j]>>1)&1)){
										tmp2=border2;
									}
									if (!((Board_Card_Open[i][j]>>3)&1)){
										tmp4=border2;
									}
									if (!((Board_Card_Open[i][j]>>2)&1)){
										tmp3=border1;
										if ((Board_Card_Open[i][j]>>1)&1){
											tmp2=border1;
										}
										if ((Board_Card_Open[i][j]>>3)&1){
											tmp4=border1;
										}
									}
								} else {
									if ((Board_Card_Open[i][j]>>1)&1){
										tmp2=border2;
									}
									if ((Board_Card_Open[i][j]>>3)&1){
										tmp4=border2;
									}
								}
							}
							if ((((Board_Card_Able[i][j]&Board_Card_Around[i][j])>>3)&1)&&(Board_Card_Open[i][j])){
								tmp6=blank;
							}
							break;
					case 3: if (Board_Card_Open[i][j]<0){
								// Card == Goalcard
								if (Board_Card_Open[i][j]<-2){
									// Tertutup
									tmp1=facedown;tmp2=facedown;
									tmp3=facedown;tmp4=facedown;
									tmp5=facedown;
								} else {
									// Kebuka
									tmp2=border2;
									tmp4=border2;
								}
							} else {
								if ((Board_Card_Open[i][j]>>2)&1){
									if ((Board_Card_Open[i][j]>>4)&1) {
										tmp2=border2;
										tmp4=border2;
									} else {
										tmp3=border1;
									}
								}
							}
							break;
					case 4: if (Board_Card_Open[i][j]<0){
								// Card == Goalcard
								if (Board_Card_Open[i][j]<-2){
									// Tertutup
									tmp1=facedown;tmp2=facedown;
									tmp3=facedown;tmp4=facedown;
									tmp5=facedown;
								} else {
									// Kebuka
									tmp1=border1;
									tmp2=border2;
									tmp4=border2;
									tmp5=border1;
									if (!((Board_Card_Able[i][j]>>2)&1)){
										tmp3=border1;
									}
								}
							} else {
								tmp1=border1;
								tmp5=border1;
								if ((Board_Card_Open[i][j]>>2)&1){
									tmp2=border2;
									tmp4=border2;
								} else {
									tmp2=border1;
									tmp4=border1;
								}
								if ((!(((Board_Card_Able[i][j]&Board_Card_Around[i][j])>>2)&1))||(!Board_Card_Open[i][j])){
									//Cek kartu bawah terhubung langsung/tidak
									tmp3=border1;
								}
								if ((Board_Card_Open[i][j])&&(j==0)){
									if ((Board_Card_Open[i+1][j]>=-2)&&(Board_Card_Able[i+1][j]&1)){
										//Sebelah Goalcard kebuka
										tmp3=blank;
									}
								}
							}
							break;
				}
				printf("%c%c%c%c%c%c%c%c",tmp1,tmp1,tmp2,tmp3,tmp4,tmp5,tmp5,tmp6);
			}
			#ifndef _WIN32
			PosY++;
			gotoxy(PosX,PosY);
			#else
			printf("\n");
			#endif
		}
	}
	#undef border1
	#undef border2
	#undef blank
	#undef facedown
}

void Board_PrintCard(int PosY, int PosX, int Stat){
	/* Cetak satu kartu, sesuai kode Stat. Lihat penjelasan diatas untuk kode Stat. */
	/* PosX dan PosY untuk posisi kartu di Board (5x9) */
	int a,b,i,j;
	char tmp1,tmp2,tmp3,tmp4,tmp5,tmp6;
	i=PosY;j=PosX;
	PosX=PosX*9+2+Board_PosX;
	PosY=PosY*6+2+Board_PosY;
	#ifndef _WIN32
	gotoxy(PosX,PosY);
	#endif
	#define border1 '_' // Border datar
	#define border2 '|' // Border tegak
	#define blank ' ' // Kosong
	#define facedown '#' // Kartu tertutup (Goal Card)
	for (a=0;a<5;a++){
		//Print kartu.
		tmp1=blank;tmp2=blank;tmp3=blank;tmp4=blank;tmp5=blank;tmp6=border2;
		switch(a){
			case 0: if (Stat<0){
						// Card == Goalcard
						if (Stat<-2){
							// Tertutup
							tmp1=facedown;tmp2=facedown;
							tmp3=facedown;tmp4=facedown;
							tmp5=facedown;
						} else {
							// Kebuka
							tmp2=border2;
							tmp4=border2;
						}
					} else {
						if (Stat&1){
							tmp2=border2;
							tmp4=border2;
							if (!((Stat>>4)&1)){
								tmp3=border1;
							}
						}
					}
					break;
			case 1: if (Stat<0){
						// Card == Goalcard
						if (Stat<-2){
							// Tertutup
							tmp1=facedown;tmp2=facedown;
							tmp3=facedown;tmp4=facedown;
							tmp5=facedown;
						} else {
							// Kebuka
							tmp1=border1;
							tmp2=border2;
							tmp4=border2;
							tmp5=border1;
						}
					} else {
						if ((Stat>>1)&1){
							tmp1=border1;
						}
						if ((Stat>>3)&1){
							tmp5=border1;
						}
						if ((Stat>>4)&1){
							if (Stat&1){
								tmp2=border2;
								tmp4=border2;
							} else {
								tmp3=border1;
								if ((Stat>>1)&1){
									tmp2=border1;
								}
								if ((Stat>>3)&1){
									tmp4=border1;
								}
							}
						}
					}
					break;
			case 2: if (Stat<0){
						// Card == Goalcard
						if (Stat<-2){
							// Tertutup
							tmp1=facedown;tmp2=facedown;
							tmp3=facedown;tmp4=facedown;
							tmp5=facedown;
						} else {
							// Kebuka
							tmp1=border1;
							tmp5=border1;
							if (Stat==-1){
								//Batu
								tmp3='R';
							} else {
								//Emas
								tmp3='G';
							}
						}
					} else {
						if ((Stat>>1)&1){
							tmp1=border1;
						}
						if ((Stat>>3)&1){
							tmp5=border1;
						}
						if ((Stat>>4)&1){
							if (!((Stat>>1)&1)){
								tmp2=border2;
							}
							if (!((Stat>>3)&1)){
								tmp4=border2;
							}
							if (!((Stat>>2)&1)){
								tmp3=border1;
								if ((Stat>>1)&1){
									tmp2=border1;
								}
								if ((Stat>>3)&1){
									tmp4=border1;
								}
							}
						} else {
							if ((Stat>>1)&1){
								tmp2=border2;
							}
							if ((Stat>>3)&1){
								tmp4=border2;
							}
						}
					}
					break;
			case 3: if (Stat<0){
						// Card == Goalcard
						if (Stat<-2){
							// Tertutup
							tmp1=facedown;tmp2=facedown;
							tmp3=facedown;tmp4=facedown;
							tmp5=facedown;
						} else {
							// Kebuka
							tmp2=border2;
							tmp4=border2;
						}
					} else {
						if ((Stat>>2)&1){
							if ((Stat>>4)&1) {
								tmp2=border2;
								tmp4=border2;
							} else {
								tmp3=border1;
							}
						}
					}
					break;
			case 4: if (Stat<0){
						// Card == Goalcard
						if (Stat<-2){
							// Tertutup
							tmp1=facedown;tmp2=facedown;
							tmp3=facedown;tmp4=facedown;
							tmp5=facedown;
						} else {
							// Kebuka
							tmp1=border1;
							tmp2=border2;
							tmp4=border2;
							tmp5=border1;
							if (!((Board_Card_Able[i][j]>>2)&1)){
								tmp3=border1;
							}
						}
					} else {
						tmp1=border1;
						tmp3=border1;
						tmp5=border1;
						if ((Stat>>2)&1){
							tmp2=border2;
							tmp4=border2;
						} else {
							tmp2=border1;
							tmp4=border1;
						}
					}
					break;
		}
		printf("%c%c%c%c%c%c%c%c",tmp1,tmp1,tmp2,tmp3,tmp4,tmp5,tmp5,tmp6);
		#ifndef _WIN32
		PosY++;
		gotoxy(PosX,PosY);
		#else
		printf("\n");
		#endif
	}
	#undef border1
	#undef border2
	#undef blank
	#undef facedown
}

int Board_CekGoal(void){
	/* Mengecek apakah deadlock karena Goalcard tidak bisa dicapai 
	   lagi sudah terjadi/belum */
	/* Tidak mengecek apakah kartu Rockfall sudah habis/belum */
	/*	1 = Deadlock terjadi
		0 = Belum Deadlock */
	int a,b,c,flag[10][15],hsl;
	int Board_CekGoalX(int PosY, int PosX){
		/* Fungsi rekursif dari Board_CekGoal */
		/* Memakai algoritma flood fill. Flag-nya flag */
		/* Untuk mengecek apakah Goalcard terhubung dengan Startcard atau tidak */
		int i,tmp,tmp2,ans;
		if (Board_Card_Open[PosY][PosX]==0){
			//Jika kartu kosong, seolah terhubung dengan kartu kosong dan jalan yang terbuka di sekitar
			tmp=((~Board_Card_Around[PosY][PosX])&15)+(Board_Card_Around[PosY][PosX]&Board_Card_Able[PosY][PosX]);
		} else {
			tmp=Board_Card_Open[PosY][PosX];
		}
		tmp=((tmp>>2)&3)+(tmp<<2);
		tmp2=1;
		ans=0;
		for (i=0;i<4;i++){
			//Cek Kartu sekitar
			if ((0<=(PosY+Board_MoveY[i]))&&((PosY+Board_MoveY[i])<=4)&&(0<=(PosX+Board_MoveX[i]))&&((PosX+Board_MoveX[i])<=8)){
				//Kartu berada dalam board
				if ((tmp&tmp2)&&(!(flag[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]))){
					//Syarat menghubungkan kartu lain : terhubung dan bukan jalan buntu
					//Kartu kosong dianggap menghubungkan
					//flag dipakai agar rekursif tidak pernah ke kartu sama 2x
					flag[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]|=1;
					if (Board_Card_Flag[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]){
						//Kartu terhubung dengan Startcard, artinya Goalcard terhubung dengan Startcard
						ans+=1;
					} else if (Board_Card_Open[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]==0){
						//Rekursif jika kartu kosong
						ans+=Board_CekGoalX(PosY+Board_MoveY[i],PosX+Board_MoveX[i]);
					} else if (Board_Card_Open[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]>15){
						//Rekursif jika kartu bukan jalan buntu dan tidak terhubung Startcard
						//Mengatasi kasus kartu yang putus dari startcard setelah Rockfall
						ans+=Board_CekGoalX(PosY+Board_MoveY[i],PosX+Board_MoveX[i]);
					}
				}
			}
			tmp2<<=1;
		}
		return ans;
	}
	hsl=0;
	for (c=0;c<3;c++){
		if (Board_Card_Open[c*2][0]>-3){
			//Goalcard terbuka
			hsl+=1;
		} else {
			//Reset flag
			for (a=0;a<5;a++){
				for (b=0;b<9;b++){
					flag[a][b]=0;
				}
			}
			//Floodfill dari Goalcard
			flag[c*2][0]=1;
			hsl+=!(Board_CekGoalX(c*2,0));
		}
	}
	return hsl;
}

int Board_Refresh(void){
	/* Mengecek kartu mana saja yang terhubung langsung (satu komponen)
	   dengan kartu start */
	/* Memakai algoritma flood fill. */
	int a,b,flag[10][15];
	int Board_RefreshX(int PosY, int PosX){
		/* Fungsi rekursif dari Board_Refresh */
		/* Memakai algoritma flood fill. Flag-nya flag */
		int i,tmp,tmp2,ans;
		tmp=((Board_Card_Open[PosY][PosX]>>2)&3)+(Board_Card_Open[PosY][PosX]<<2);
		tmp2=1;
		ans=0;
		for (i=0;i<4;i++){
			//Cek Kartu sekitar
			if ((0<=(PosY+Board_MoveY[i]))&&((PosY+Board_MoveY[i])<=4)&&(0<=(PosX+Board_MoveX[i]))&&((PosX+Board_MoveX[i])<=8)){
				//Kartu berada dalam board
				if ((tmp&tmp2)&&(!(flag[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]))){
					//Syarat menghubungkan kartu lain: terhubung, dan penghubung bukan jalan buntu.
					//flag dipakai agar rekursif tidak pernah ke kartu sama 2x
					flag[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]|=1;
					if (Board_Card_Open[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]<-2){
						//Di sebelah Goalcard
						Board_Card_Open[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]+=2;
						if (Board_Card_Open[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]==-2){
							//Kebuka kartu emas
							Board_Win=1;
						}
					} else if (Board_Card_Open[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]>15){
						//Rekursif
						ans+=Board_RefreshX(PosY+Board_MoveY[i],PosX+Board_MoveX[i]);
					} else if (Board_Card_Open[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]==0){
						//Kartu kosong. Boleh ditaruh kartu.
						Board_Card_Flag[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]=1;
						ans+=1;
					}
				}
			}
			tmp2<<=1;
		}
		return ans;
	}
	for (a=0;a<5;a++){
		for (b=0;b<9;b++){
			Board_Card_Flag[a][b]=0;
			flag[a][b]=0;
		}
	}
	flag[2][8]=1;
	return Board_RefreshX(2,8);
}

void Board_Reload(void){
	/* Mengatur ulang keadaan Board setelah load game */
	/* Board_Card_Open harus sudah terisi dengan benar (sudah di-load ulang) */
	int i,j,k,tmp,tmp2;
	for (i=0;i<5;i++){
		for (j=0;j<9;j++){
			Board_Card_Able[i][j]=0;
			Board_Card_Around[i][j]=0;
		}
	}
	for (i=0;i<5;i++){
		for (j=0;j<9;j++){
			if (Board_Card_Open[i][j]>0){
				tmp=((Board_Card_Open[i][j]>>2)&3)+(Board_Card_Open[i][j]<<2);
				tmp2=1;
				for (k=0;k<4;k++){
					if ((0<=(i+Board_MoveY[k]))&&((i+Board_MoveY[k])<=4)&&(0<=(j+Board_MoveX[k]))&&((j+Board_MoveX[k])<=8)){
						Board_Card_Able[i+Board_MoveY[k]][j+Board_MoveX[k]]|=(tmp&tmp2);
						Board_Card_Around[i+Board_MoveY[k]][j+Board_MoveX[k]]|=(tmp2);
					}
					tmp2<<=1;
				}
			}
		}
	}
	tmp=Board_Refresh();
}
	
void Board_PutCard(int PosY, int PosX, int Stat){
	/* Menaruh kartu di Board. Stat berisi kode kartu yang akan ditaruh */
	/* Tidak mengecek PosY, PosX, dan Stat */
	/* Parameter harus memenuhi Board_CekPut dahulu agar tidak error */
	int i,j,tmp,tmp2;
	int a,b;
	//Penyesuaian keadaan Board
	Board_Card_Open[PosY][PosX]=Stat;
	tmp=((Board_Card_Open[PosY][PosX]>>2)&3)+(Board_Card_Open[PosY][PosX]<<2);
	tmp2=1;
	for (i=0;i<4;i++){
		if ((0<=(PosY+Board_MoveY[i]))&&((PosY+Board_MoveY[i])<=4)&&(0<=(PosX+Board_MoveX[i]))&&((PosX+Board_MoveX[i])<=8)){
			Board_Card_Able[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]|=(tmp&tmp2);
			Board_Card_Around[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]|=(tmp2);
		}
		tmp2<<=1;
	}
	//Set ulang keterhubungan kartu di Board dengan kartu start
	tmp=Board_Refresh();
	//Cek keadaan Goalcard
	tmp2=Board_CekGoal();
	if (Board_Win){
		//Gold card terbuka
		//printf("Gold Miner!\n");
	} else if ((tmp==0)||(tmp2==3)){
		//if rockfall==abis
		//Deadlock. Tidak ada kartu yg bisa ditaruh/ Goldcard tidak bisa dicapai
		//printf("Sabotaged!\n");
		Board_Win=-1;
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

void Board_Rockfall(int PosY, int PosX){
	/* Menghancurkan satu kartu di Board, lalu mengatur ulang status Board */
	/* Tidak mengecek PosY dan PosX */
	/* Parameter harus memenuhi Board_CekRock dahulu agar tidak error */
	int i,tmp,tmp2;
	//Penyesuaian keadaan Board
	tmp=((Board_Card_Open[PosY][PosX]>>2)&3)+(Board_Card_Open[PosY][PosX]<<2);
	tmp2=1;
	for (i=0;i<4;i++){
		if ((0<=(PosY+Board_MoveY[i]))&&((PosY+Board_MoveY[i])<=4)&&(0<=(PosX+Board_MoveX[i]))&&((PosX+Board_MoveX[i])<=8)){
			Board_Card_Able[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]-=(tmp&tmp2);
			Board_Card_Around[PosY+Board_MoveY[i]][PosX+Board_MoveX[i]]-=(tmp2);
		}
		tmp2<<=1;
	}
	Board_Card_Open[PosY][PosX]=0;
	//Cek ulang keterhubungan dengan Start card
	tmp=Board_Refresh();
}
