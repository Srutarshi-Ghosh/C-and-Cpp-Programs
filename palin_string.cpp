#include<iostream>

int strlength(char[]);
int palin(char[100], int);
int main(){
	char ch[100];
	int length, i;
	printf("Enter a string: \n");
	gets(ch);
	length=strlength(ch);
	if(palin(ch, length)==1)
		printf("The string is palindrome");
	else
		printf("The string is not palindrome");
	return 0;
}

int strlength(char ch[100]){
	int length=0;
	while(ch[length]!='\0'){
		length++;
	}
	return length;
}

int palin(char ch[], int length){
	int i;
	for(i=0; i<length/2; i++){
		if(ch[i]!=ch[length-1-i])
			return 0;
	}
	return 1;
}
