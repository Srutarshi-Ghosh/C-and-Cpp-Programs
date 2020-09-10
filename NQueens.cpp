#include<stdio.h>
#include<stdlib.h>


int isSafe(int**, int, int, int);
int n_queens(int**, int, int);
void printBoard(int**, int);

int main(){
	int **board, n, i, j, sol = 1;

	printf("Enter the size of the Board: ");
	scanf("%d", &n);
	
	board = (int**)malloc(n * sizeof(int*));
	for(i = 0; i < n; i++)
		board[i] = (int*)calloc(n, sizeof(int));
		
	n_queens(board, n, 0);
	printBoard(board, n);
	
}


void printBoard(int **board, int n){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(board[i][j])
				printf("Q ");
			else
				printf("_ ");
		}
		printf("\n");
	}
	printf("\n");
}


int n_queens(int **board, int n, int col){
	if(col == n){
		return 1;
	}
	
	int i, temp;
	for(i = 0; i < n; i++){
		if(isSafe(board, n, i, col)){
			board[i][col] = 1;
			//sol = n_queens(board, n, col + 1, sol);

			if(n_queens(board, n, col + 1))
				return 1;
			board[i][col] = 0;
		}
	}
	return 0;
}

int isSafe(int **board, int n, int row, int col){
	int i, j, num, r;
	int dir[] = {-1, 0, 1};
	for(i = 0; i < 3; i++){
		num = 1;
		for(j = col - 1; j >= 0; j--){
			r = row - (dir[i] * num);
			if(r < 0 || r >= n)
				break;
			if(board[r][j])
				return 0;
			num++;
		}
	}
	return 1;
}



