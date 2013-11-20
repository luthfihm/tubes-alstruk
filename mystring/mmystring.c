#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

int main(){
	String S1,S2,S3;
	printf("Masukan S1 = ");scanf("%s",S1);
	printf("Masukan S2 = ");scanf("%s",S2);
	printf("S1 = %s %d\n",S1,StrLength(S1));
	printf("S2 = %s %d\n",S2,StrLength(S2));
	if (StrEq(S1,S2)){
		printf("S1 dan S2 sama\n");
	}else{
		if (StrLess(S1,S2)){
			printf("S1 kurang dari S2\n");
		}
		if (StrLarger(S1,S2)){
			printf("S1 lebih dari S2\n");
		}
	}
	CopyStr(S1,S3);
	printf("Hasil salinan S1 ke S3 = %s\n",S3);
	return 0;
}