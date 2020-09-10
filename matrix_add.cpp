#include<iostream>

void matrixinput(int[10][10], int, int);
void matrixadd(int[10][10], int[10][10], int[10][10], int, int);
void printmatrix(int matrix3[10][10], int n, int m);
int main(){
	int matrix1[10][10], matrix2[10][10], matrix3[10][10], n, m;
	printf("Enter no of rows");
	scanf("%d", &n);
	printf("Enter no of columns");
	scanf("%d", &m);
	matrixinput(matrix1, n, m);
	matrixinput(matrix2, n, m);
	matrixadd(matrix1, matrix2, matrix3, n, m);
	printmatrix(matrix3, n, m);
	return 0;
}

void matrixinput(int matrix1[10][10], int n, int m){
	int i, j;
	printf("Enter the values \n");
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf("%d", &matrix1[i][j]);
		}
	}
}

void matrixadd(int matrix1[10][10], int matrix2[10][10], int matrix3[10][10], int n, int m){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			matrix3[i][j]=matrix1[i][j]+matrix2[i][j];
		}
	}
}
void printmatrix(int matrix3[10][10], int n, int m){
	int i, j;
	printf("Matrix after addition is \n");
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){	
			printf("%d ", matrix3[i][j]);
		}
		printf("\n");
	}
}



