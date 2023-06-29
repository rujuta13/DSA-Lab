#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void randomGen(int count, int lower, int upper, char fname[])
{
	FILE *fp;
	fp = fopen(fname, "w");
	
	if(fp == NULL){//unable to open file
		printf("test 1 in randomGen");
		return;
	}
		
	
	for (int i = 0; i < count; i++) {
		int num = (rand() % (upper - lower + 1)) + lower;
		//printf("%d\n", num);
		fprintf(fp, "%d",num); 
		fputs("\n",fp);
	}
	fclose(fp);
}

void main(int s, char *A[]){
	char *fname; 
	int lower, upper, count;
	strcpy(fname, A[1]);
	count = atoi(A[2]);
	lower = atoi(A[3]);
	upper = atoi(A[4]);
	
	srand(time(0));
	randomGen(count, lower, upper, fname);
<<<<<<< HEAD
}
=======
}
>>>>>>> aad6c423ea575c2efb7f74f0e94a40d0a591e050
