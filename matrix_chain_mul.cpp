#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int matrix_chain_multiplication(int**, int);
//void print_matrix(int**, int, int);

int main(){
	int **dim, n, i, rows, cols, ans;
	printf("Enter number of matrices to multiply: ");
	scanf("%d", &n);
	
	dim = (int**)malloc(sizeof(int*) * n);
	for(i = 0; i < n; i++){
		dim[i] = (int*)malloc(sizeof(int) * 2);
		printf("Enter Number of Rows and Columns: ");
		scanf("%d %d", &rows, &cols);
		dim[i][0] = rows, dim[i][1] = cols;
	}
	ans = matrix_chain_multiplication(dim, n);
	printf("The minimum number of multiplications required is: %d\n", ans);
	return 0;
}


int matrix_chain_multiplication(int **dim, int n){
	int i, j, k, d, min, q;
	int *arr = (int*)malloc((n + 1) * sizeof(int));
	int **matmul;
	//parenthesis = (int**)malloc((n + 1) * sizeof(int*));
	matmul = (int**)malloc((n + 1) * sizeof(int*));
	
	for(i = 0; i <= n; i++){
		matmul[i] = (int*)malloc((n + 1) * sizeof(int));
		//parenthesis[i] = (int*)malloc((n + 1) * sizeof(int));
		matmul[i][i] = 0;
		if(i == n)
			arr[i] = dim[n-1][1];
		else
			arr[i] = dim[i][0]; 
	}
	
	for(d = 1; d < n; d++){
		for(i = 1; i < n - d + 1; i++){
			j = i + d;
			min = INT_MAX;
			for(k = i; k <= j - 1; k++){
				q = matmul[i][k] + matmul[k+1][j] + (arr[i-1] * arr[k] * arr[j]);
				if(q < min){
					min = q;
					//parenthesis[i][j] = k;
				}
			}
			matmul[i][j] = min;
		}
	}

	//printf("%d\n", matmul[1][n]);
	return matmul[1][n];
	
}

//
//void print_matrix(int **mat, int n, int m){
//	int i, j;
//	for(i = 0; i < n; i++){
//		for(j = 0; j < m; j++){
//			printf("%d ", mat[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}




