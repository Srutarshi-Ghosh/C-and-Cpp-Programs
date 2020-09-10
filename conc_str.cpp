#include<iostream>

int strlength(char[100]);
void conc_str(char[100], char[100]);

int main(){
	char ch[100], s[100];
	int length, i;
	printf("Enter a string \n");
	gets(ch);
	printf("Enter second string \n");
	gets(s);
	conc_str(ch, s);
	printf("After adding the strings \n %s", ch);
	return 0;
}

int strlength(char ch[100]){
	int length=0;
	while(ch[length]!='\0'){
		length++;
	}
	return length;
}

void conc_str(char ch[], char s[]){
	int len, i=0;
	len=strlength(ch);
	while(s[i]!='\0'){
		ch[len]=s[i];
		len++;
		i++;
	}
	
}
