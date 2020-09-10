#include<stdio.h>
#include<time.h>

void resetgame(char[][3]);
void playerturn(char[][3]);
void play(char[3][3]);
void firstmove(char[][3]);
int cpuwin(char[][3]);
int cpublock(char[][3]);
int strategy(char[][3]);
void arbitrary(char[][3]);
void mark(char[][3], int);
void printgrid(char[][3]);
void delay(float);

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
	int m, flag=0;
	resetgame(game);
	printgrid(game);
	for(m=0; m<9; m++){
		if(m%2==0){
			playerturn(game);
			printgrid(game);
		}
		else{
			printf("CPU's turn: ");
			delay(0.5);
			if(m==1){
				firstmove(game);
				continue;
			}
			if(cpuwin(game)==1){
				flag=1;
				break;
			}
			if(cpublock(game)==1)
				continue;
			if(m==3){
				if(strategy(game)==0){
					printgrid(game);
					continue;
				}
			}	
			arbitrary(game);
		}
	}
	if(flag==0)
		printf("It's a draw!\n");
}

void firstmove(char game[][3]){
	if(game[1][1]=='_')
		mark(game, 5);
	else 
		mark(game, 1);
	printgrid(game);
}

void playerturn(char game[][3]){
	int i, j, no=0;
	printf("Player's Turn: ");
	scanf("%d", &no);
	while(no<1 || no>9){
		printf("Invalid Input!\nEnter again: ");
		scanf("%d", &no);
	}
	i = no/3;
	j = (no%3)-1;
	if(j==-1){
		i--;
		j = 2;
	}
	while(game[i][j]=='X' || game[i][j]=='O'){
		printf("Block is taken!\nEnter again: ");
		scanf("%d", &no);
		i = no/3;
		j = (no%3)-1;
		if(j==-1){
			i--;
			j = 2;
		}
	}
	game[i][j] = 'X';
}


int cpuwin(char game[][3]){
	int blank, c, a, b, no = -1, i, j;
	for(i=0; i<3; i++){
		blank = 0;
		c = 0;
		for(j=0; j<3; j++){
			if(game[i][j]=='_'){
				blank++;
				a = i;
				b = j;
			}
			if(game[i][j]=='O')
				c++;
		}
		if(blank==1 && c==2){
			no = (3*a) + b+1;
			mark(game, no);
			printgrid(game);
			printf("CPU has won the game!\n");
			return 1;
		}
	}	
	for(i=0; i<3; i++){
		blank = 0;
		c = 0;
		for(j=0; j<3; j++){
			if(game[j][i]=='_'){
				blank++;
				a = j;
				b = i;
			}
			if(game[j][i]=='O')
				c++;
		}
		if(blank==1 && c==2){
			no = (3*a) + b+1;
			mark(game, no);
			printgrid(game);
			printf("CPU has won the game!\n");
			return 1;
		}
	}
	
	blank = 0;
	c = 0;
	for(i=0; i<3; i++){
		
		if(game[i][i]=='_'){
			blank++;
			a = i;
			b = i;
		}
		if(game[i][i]=='O')
			c++;
	}
	if(blank==1 && c==2){
		no = (3*a) + b+1;
		mark(game, no);
		printgrid(game);
		printf("CPU has won the game!\n");
		return 1;
	}
	
	blank = 0;
	c = 0;
	for(i=0, j=2; j>=0; j--, i++){
		if(game[i][j]=='_'){
			blank++;
			a = i;
			b = j;
		}
		if(game[i][j]=='O')
			c++;
	}
	if(blank==1 && c==2){
		no = (3*a) + b+1;
		mark(game, no);
		printgrid(game);
		printf("CPU has won the game!\n");
		return 1;
	}
	return 0;	
}

int cpublock(char game[][3]){
	int blank, c, a, b, no = -1, i, j;
	for(i=0; i<3; i++){
		blank = 0;
		c = 0;
		for(j=0; j<3; j++){
			if(game[i][j]=='_'){
				blank++;
				a = i;
				b = j;
			}
			if(game[i][j]=='X')
				c++;
		}
		if(blank==1 && c==2){
			no = (3*a) + b+1;
			mark(game, no);
			printgrid(game);
			return 1;
		}
	}	
	for(i=0; i<3; i++){
		blank = 0;
		c = 0;
		for(j=0; j<3; j++){
			if(game[j][i]=='_'){
				blank++;
				a = j;
				b = i;
			}
			if(game[j][i]=='X')
				c++;
		}
		if(blank==1 && c==2){
			no = (3*a) + b+1;
			mark(game, no);
			printgrid(game);
			return 1;
		}
	}
	
	blank = 0;
	c = 0;
	for(i=0; i<3; i++){
		if(game[i][i]=='_'){
			blank++;
			a = i;
			b = j;
		}
		if(game[i][i]=='X')
			c++;
	}
	if(blank==1 && c==2){
		no = (3*a) + b+1;
		mark(game, no);
		printgrid(game);
		return 1;
	}
	
	blank = 0;
	c = 0;
	for(i=0, j=2; j>=0; i++, j--){
		
		if(game[i][j]=='_'){
			blank++;
			a = i;
			b = j;
		}
		if(game[i][j]=='X')
			c++;
	}
	if(blank==1 && c==2){
		no = (3*a) + b+1;
		mark(game, no);
		printgrid(game);
		return 1;
	}
	return 0;	
}

int strategy(char game[][3]){
	int i, j, pos1=0, pos2;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(game[i][j]=='X'){
				if(pos1==0)
					pos1 = (3*i)+j+1;
				else
					pos2 = (3*i)+j+1;
			} 
		}
	}
	if((pos1==1 && pos2==9) || (pos1==3 && pos2==7)){
		mark(game, 2);
		return 0;
	}
	if(pos1==2 && pos2==4){
		mark(game, 1);
		return 0;
	}
	if(pos1==2 && pos2==6){
		mark(game, 3);
		return 0;
	}
	if(pos1==4 && pos2==8){
		mark(game, 7);
		return 0;
	}
	if(pos1==6 && pos2==8){
		mark(game, 9);
		return 0;
	}
	if((pos1==2 && pos2==8) || (pos1==4 && pos2==6)){
		mark(game, 1);
		return 0;
	}
	if((pos1==4 && pos2==9) || (pos1==1 && pos2==8)){
		mark(game, 7);
		return 0;
	}
	if((pos1==3 && pos2==4) || (pos1==2 && pos2==7)){
		mark(game, 1);
		return 0;
	}
	if((pos1==1 && pos2==6) || (pos1==2 && pos2==9)){
		mark(game, 3);
		return 0;
	}
	if((pos1==3 && pos2==8) || (pos1==6 && pos2==7)){
		mark(game, 9);
		return 0;
	}
	if(pos1==5 && pos2==9){
		mark(game, 7);
		return 0;
	}
	return 1;
	
}

void arbitrary(char game[][3]){
	int i, j, no;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(game[i][j]=='_'){
				no = (3*i)+j+1;
				mark(game, no);
				printgrid(game);
				return;
			}
		}
	}
}

void mark(char game[][3], int no){
	int i, j;
	i = no/3;
	j = (no%3)-1;
	if(j==-1){
		i--;
		j = 2;
	}
	game[i][j] = 'O';
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

void delay(float n){
	float ms = 1000*n;
	clock_t start = clock();
	while(clock()<start+ms);
}
