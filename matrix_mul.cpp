#include<iostream>
#include<stdlib.h>

int** matrixinput(int, int);
int** matrixmul(int**, int**, int, int, int);
void printmatrix(int**, int, int);

int main(){
	int **matrix1, **matrix2, **matrix3, n, m, p, q;
	printf("Enter no of rows of first matrix: ");
	scanf("%d", &n);
	printf("Enter no of columns of first matrix: ");
	scanf("%d", &m);
	printf("Enter no of rows of second matrix: ");
	scanf("%d", &p);
	printf("Enter no of columns of second matrix: ");
	scanf("%d", &q);
	if(m!=p){
		printf("Invalid Input");
	}
	else{
		matrix1=matrixinput(n, m);
		matrix2=matrixinput(p, q);
		matrix3=matrixmul(matrix1, matrix2, n, m, q);
		printmatrix(matrix3, n, q);
	}
	return 0;
}

int** matrixinput(int n, int m){
	int i, j, **mat;
	printf("Enter the elements of the matrix: \n");
	mat = (int**)malloc(n*sizeof(int*));
	for(i=0; i<n; i++){
		mat[i]=(int*)malloc(m*sizeof(int));
		for(j=0; j<m; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	
	return mat; 
}

int** matrixmul(int **matrix1, int **matrix2, int n, int m, int q){
	int i, j, k, **matrix3;
	matrix3=(int**)malloc(m*sizeof(int*));
	for(i=0; i<n; i++){
		matrix3[i]=(int*)malloc(q*sizeof(int));
		for(j=0; j<q; j++){
			matrix3[i][j]=0;
			for(k=0; k<m; k++){
				matrix3[i][j]+=matrix1[i][k]*matrix2[k][j];
			}
		}
	}
	return matrix3;
}

void printmatrix(int **matrix3, int m, int p){
	int i, j;
	printf("Matrix after multiplication is: \n");
	for(i=0; i<m; i++){
		for(j=0; j<p; j++){	
			printf("%d ", matrix3[i][j]);
		}
		printf("\n");
	}
}

