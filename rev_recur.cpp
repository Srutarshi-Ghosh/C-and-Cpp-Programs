#include<stdio.h>


int rev(char[], int, int);



int rev(char str[], int x, int y){
	char temp;
	if(x>=y){
		printf("%s", str);
		return 0;
	}
	temp = str[x];
	str[x] = str[y];
	str[y] = temp;
	rev(str, x+1, y-1); 
}

int main(){
	char str[100];
	int len=0;
	scanf("%s", str);
	while(str[len]!='\0')
		len++;
	rev(str, 0, len-1);
	return 0;
}
