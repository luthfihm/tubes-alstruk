#include <stdio.h>

int Card_Open[10][15]; /* Isi dari kartu yang ditaruh */
int Card_Around[10][15]; /* kartu sebelah kosong/tdk */
int Card_Able[10][15]; /* Jalan mana aja yang kebuka */
int MoveY[]={1,0,-1,0};
int MoveX[]={0,1,0,-1};

/* Viewmap, Put disebelah goalcard, randomize goalcard, IsWin (pake bool aja), Goalcard kebuka */
/* Rencana goalcard:
	Card < 0 = goalcard 
	-1 = Batu (tutup)
	-2 = Emas (tutup)
	-3 = Batu kebuka
	-4 = Emas Kebuka */

void PrintBoard(void){
	int i,j,a,b;
	/*
	#define border1 6
	#define border2 5
	#define blank 20
	#define corner1 1
	#define corner2 2
	#define corner3 3
	#define corner4 4
	#define sect1 22
	#define sect2 21
	#define sect3 25
	#define sect4 23
	#define sect5 16
	#define up 26
	#define down 26
	#define left 26
	#define right 26
	#define mid 26
	/*/
	#define border1 '-' /* Border datar */
	#define border2 '|' /* Border tegak */
	#define blank ' ' /* Kosong */
	#define facedown '#' /* Kartu tertutup (Goal Card) */
	#define corner1 ' ' /* Border kiri atas (|^) */
	#define corner2 ' ' /* Border kanan atas (^|) */
	#define corner3 ' ' /* Border kiri bawah (|_) */
	#define corner4 ' ' /* Border kanan bawah (_|) */
	#define sect1 ' ' /* Border atas tengah (^|^) */
	#define sect2 ' ' /* Border bawah tengah (_|_) */
	#define sect3 ' ' /* Border kiri tengah (|-) */
	#define sect4 ' ' /* Border kanan tengah (-|) */
	#define sect5 ' ' /* Border tengah (+) */
	#define up 'H' /* Jalan atas kebuka */
	#define down 'H' /* Jalan bawah kebuka */
	#define left '=' /* Jalan kiri kebuka */
	#define right '=' /* Jalan kanan kebuka */
	#define mid 'O' /* Jalan tengah kebuka (buntu/tidak) */
	printf("   ");
	for (j=0;j<9;j++){
		printf("  %c ",'1'+j);
	}
	printf("\n");
	for (i=0;i<5;i++){
		printf("   ");
		for (j=0;j<9;j++){
			if (i==0){
				if (j==0)printf("%c",corner1);
				else printf("%c",sect1);
			} else {
				if (j==0)printf("%c",sect3);
				else printf("%c",sect5);
			}
			for (b=0;b<3;b++){
				printf("%c",border1);
			}
		}
		if (i==0)printf("%c\n",corner2);
		else printf("%c\n",sect4);
		for (a=0;a<3;a++){
			if (a==1)printf(" %c ",'A'+i);
			else printf("   ");
			for (j=0;j<9;j++){
				printf("%c",border2);
				switch(a){
					case 0: if (Card_Open[i][j]==-1){
								printf("%c",facedown);
							} else printf("%c",blank);
							if (Card_Open[i][j]==-1){
								printf("%c",facedown);
							} else if ((Card_Open[i][j])&1){
								printf("%c",up);
							} else {
								printf("%c",blank);
							}
							if (Card_Open[i][j]==-1){
								printf("%c",facedown);
							} else printf("%c",blank);
							break;
					case 1: if (Card_Open[i][j]==-1){
								printf("%c",facedown);
							} else if (((Card_Open[i][j])>>1)&1){
								printf("%c",left);
							} else {
								printf("%c",blank);
							}
							if (Card_Open[i][j]==-1){
								printf("%c",facedown);
							} else if (((Card_Open[i][j])>>4)&1){
								printf("%c",mid);
							} else {
								printf("%c",blank);
							}
							if (Card_Open[i][j]==-1){
								printf("%c",facedown);
							} else if (((Card_Open[i][j])>>3)&1){
								printf("%c",right);
							} else {
								printf("%c",blank);
							}
							break;
					case 2: if (Card_Open[i][j]==-1){
								printf("%c",facedown);
							} else printf("%c",blank);
							if (Card_Open[i][j]==-1){
								printf("%c",facedown);
							} else if (((Card_Open[i][j])>>2)&1){
								printf("%c",down);
							} else {
								printf("%c",blank);
							}
							if (Card_Open[i][j]==-1){
								printf("%c",facedown);
							} else printf("%c",blank);
							break;
				}
			}
			printf("%c\n",border2);
		}
	}
	printf("   ");
	for (j=0;j<9;j++){
		if (j==0)printf("%c",corner3);
		else printf("%c",sect2);
		for (b=0;b<3;b++){
			printf("%c",border1);
		}
	}
	printf("%c\n",corner4);
	#undef border1
	#undef border2
	#undef blank
	#undef facedown
	#undef corner1
	#undef corner2
	#undef corner3
	#undef corner4
	#undef sect1
	#undef sect2
	#undef sect3
	#undef sect4
	#undef sect5
	#undef up
	#undef down
	#undef left
	#undef right
	#undef mid
}

void PutCard(int PosY, int PosX, int Stat){
	int i,tmp,tmp2;
	int a,b;
	printf("%d %d %d\n",Stat&15,Card_Able[PosY][PosX],Card_Around[PosY][PosX]);
	printf("%d %d\n",Stat&15^Card_Able[PosY][PosX],Card_Around[PosY][PosX]);
	if (Card_Around[PosY][PosX]&Card_Able[PosY][PosX]){
		a=(Stat&15)&Card_Around[PosY][PosX];
		b=(Card_Able[PosY][PosX])&Card_Around[PosY][PosX];
		if (!(a^b)){
			Card_Open[PosY][PosX]=Stat;
			tmp=((Stat>>2)&3)+(Stat<<2);
			tmp2=(Stat>>4)&1;
			for (i=0;i<4;i++){
				if ((0<=(PosY+MoveY[i]))&&((PosY+MoveY[i])<=4)&&(0<=(PosX+MoveX[i]))&&((PosX+MoveX[i])<=8)){
					Card_Able[PosY+MoveY[i]][PosX+MoveX[i]]|=(tmp&tmp2);
					Card_Around[PosY+MoveY[i]][PosX+MoveX[i]]|=(tmp2);
				}
				tmp2<<=1;
			}
		} else {
			printf("Wrong Shape\n");
		}
	} else {
		printf("No Connected\n");
	}
}

void Init(){
	int i,j;
	for (i=0;i<5;i++){
		for (j=0;j<9;j++){
			Card_Open[i][j]=0;
			Card_Able[i][j]=0;
			Card_Around[i][j]=0;
		}
	}
	/* Kartu Start */
	Card_Around[2][8]=15;
	Card_Able[2][8]=15;
	PutCard(2,8,31);
	/* Kartu Goal */
	Card_Open[0][0]=-1;
	Card_Open[2][0]=-1;
	Card_Open[4][0]=-1;
}

void PrintCard(int Stat){

	#define border1 '-' /* Border datar */
	#define border2 '|' /* Border tegak */
	#define blank ' ' /* Kosong */
	#define facedown '#' /* Kartu tertutup (Goal Card) */
	#define corner1 ' ' /* Border kiri atas (|^) */
	#define corner2 ' ' /* Border kanan atas (^|) */
	#define corner3 ' ' /* Border kiri bawah (|_) */
	#define corner4 ' ' /* Border kanan bawah (_|) */
	#define sect1 ' ' /* Border atas tengah (^|^) */
	#define sect2 ' ' /* Border bawah tengah (_|_) */
	#define sect3 ' ' /* Border kiri tengah (|-) */
	#define sect4 ' ' /* Border kanan tengah (-|) */
	#define sect5 ' ' /* Border tengah (+) */
	#define up 'H' /* Jalan atas kebuka */
	#define down 'H' /* Jalan bawah kebuka */
	#define left '=' /* Jalan kiri kebuka */
	#define right '=' /* Jalan kanan kebuka */
	#define mid 'O' /* Jalan tengah kebuka (buntu/tidak) */
	int a;
	for (a=0;a<3;a++){
		printf("%c",border2);
		switch(a){
			case 0: if (Stat==-1){
						printf("%c",facedown);
					} else printf("%c",blank);
					if (Stat==-1){
						printf("%c",facedown);
					} else if ((Stat)&1){
						printf("%c",up);
					} else {
						printf("%c",blank);
					}
					if (Stat==-1){
						printf("%c",facedown);
					} else printf("%c",blank);
					break;
			case 1: if (Stat==-1){
						printf("%c",facedown);
					} else if (((Stat)>>1)&1){
						printf("%c",left);
					} else {
						printf("%c",blank);
					}
					if (Stat==-1){
						printf("%c",facedown);
					} else if (((Stat)>>4)&1){
						printf("%c",mid);
					} else {
						printf("%c",blank);
					}
					if (Stat==-1){
						printf("%c",facedown);
					} else if (((Stat)>>3)&1){
						printf("%c",right);
					} else {
						printf("%c",blank);
					}
					break;
			case 2: if (Stat==-1){
						printf("%c",facedown);
					} else printf("%c",blank);
					if (Stat==-1){
						printf("%c",facedown);
					} else if (((Stat)>>2)&1){
						printf("%c",down);
					} else {
						printf("%c",blank);
					}
					if (Stat==-1){
						printf("%c",facedown);
					} else printf("%c",blank);
					break;
		}
		printf("%c\n",border2);
	}
	#undef border1
	#undef border2
	#undef blank
	#undef facedown
	#undef corner1
	#undef corner2
	#undef corner3
	#undef corner4
	#undef sect1
	#undef sect2
	#undef sect3
	#undef sect4
	#undef sect5
	#undef up
	#undef down
	#undef left
	#undef right
	#undef mid
}

int main(){
	int a,b,c;
	Init();
	PrintBoard();
	while(1){
		scanf("%d %d %d",&a,&b,&c);
		PrintCard(c);
		PutCard(a,b,c);
		PrintBoard();
	}
	return 0;
}