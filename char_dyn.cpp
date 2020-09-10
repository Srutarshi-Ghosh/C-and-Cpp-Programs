#include<stdio.h>
#include<iostream>
#include<stdlib.h>

char** matrixinput(int n, int m);

int main(){
	int n=3, m=3;
	char **mat;
	mat=matrixinput(n, m);
	return 0;
}

char** matrixinput(int n, int m){
	int i, j;
	void *ptr, **mat;
	char temp;
	mat = (void**)malloc(n*sizeof(char*));
	for(i=0; i<n; i++){
		mat[i]=(char*)malloc(m*sizeof(char));
		for(j=0; j<m; j++){
			scanf("%c", &mat[i][j]);
		}
		scanf("%c", &temp);
	}
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			printf("%c ", mat[i][j]);
		}
		printf("\n");
	}
	return mat; 
}
