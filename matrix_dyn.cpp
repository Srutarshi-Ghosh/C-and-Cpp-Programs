#include<iostream>
#include<stdlib.h>
int** matrixinput(int n, int m);

int main(){
	int n=2, m=3, **mat;
	mat=matrixinput(n, m);
	return 0;
}

int** matrixinput(int n, int m){
	int i, j, *ptr, **mat;
	mat = (int**)malloc(n*sizeof(int*));
	for(i=0; i<n; i++){
		ptr=(int*)malloc(m*sizeof(int));
		mat[i]=ptr;
		for(j=0; j<m; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	return mat; 
}
