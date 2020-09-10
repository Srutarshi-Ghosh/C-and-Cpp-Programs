#include<stdio.h>

void resetgame(char[][3]);
int checkgrid(char[][3]);
void play(char[3][3]);
void printgrid(char[][3]);

int main(){
	char game[3][3], choice;
	do{
		play(game);
		printf("Do you want to play another game?(Y/y)\n");
		scanf("%s", &choice);
	}while(choice=='y' || choice=='Y');
	return 0;
}

void resetgame(char game[3][3]){
	int i, j;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			game[i][j] = '_';
		}
	}
}

void play(char game[3][3]){
	int flag=1, no, i, j, x;
	resetgame(game);
	printgrid(game);
	do{
		printf("Player %d's turn: ", flag);
		scanf("%d", &no);
		i = no/3;
		j = (no%3)-1;
		if(j==-1){
			i--;
			j = 2;
		}
		while(no<1 || no>9 || game[i][j]!='_'){
			printf("Invalid input!\nEnter again: ");
			scanf("%d", &no);
			i = no/3;
			j = (no%3)-1;
			if(j==-1){
				i--;
				j = 2;
			}
		}	
		
		if(flag==1){
			game[i][j] = 'X';
			flag = 2;
		}
		else{
			game[i][j] = 'O';
			flag = 1;
		}
		printgrid(game);
		x = checkgrid(game);
		
	}while(x==0);
	
	if(x==1 || x==2)
		printf("Player %d has won the game!!\n", x);
	else
		printf("Its a draw!\n");
}

int checkgrid(char game[3][3]){
	int i, moves = 0, j;
	for(i=0; i<3; i++){
		if(game[i][0]==game[i][1] && game[i][1]==game[i][2] && (game[i][0]=='X' || game[i][0]=='O')){
			if(game[i][0]=='X')
				return 1;
			else
				return 2;
		}
	}	
	for(i=0; i<3; i++){
		if(game[0][i]==game[1][i] && game[1][i]==game[2][i] && (game[0][i]=='X' || game[0][i]=='O')){
			if(game[0][i]=='X')
				return 1;
			else
				return 2;
		}
	}
	if(game[0][0]==game[1][1] && game[1][1]==game[2][2] && (game[1][1]=='X' || game[1][1]=='O')){
		if(game[1][1]=='X')
			return 1;
		else
			return 2;
	}	
	if(game[0][2]==game[1][1] && game[1][1]==game[2][0] && (game[1][1]=='X' || game[1][1]=='O')){
		if(game[1][1]=='X')
			return 1;
		else
			return 2;
	}
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(game[i][j]=='_')
				moves++;
		}
	}
	if(moves==0)
		return -1;
	return 0;	
}

void printgrid(char game[3][3]){
	int i, j;
	for(i=0; i<3; i++){
		printf("\n     ");
		for(j=0; j<3; j++){
			printf("%c ", game[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
