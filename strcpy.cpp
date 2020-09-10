#include<iostream>

int strlength(char[100]);
void strcpy(char[100], char[100]);

int main(){
	char ch[100], s[100];
	printf("Enter a string \n");
	gets(ch);
	strcpy(ch, s);
	printf("After copying the string: %s", s);
	return 0;
}

int strlength(char ch[100]){
	int length=0;
	while(ch[length]!='\0'){
		length++;
	}
	return length;
}

void strcpy(char str[], char s[]){
	int len, i=0, j=0;
	len=strlength(str);
	for(i=0; i<len; i++){
			s[i]=str[i];
		}
	}
	
