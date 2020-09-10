#inclue<stdio.h>
#include<stdlib.h>


int strlength(char[]);
void conc_str(char[], char[]);

int main(){
	char ch[1000], s[1000];
	int length, i;
	gets(ch);
	conc_str(ch, s);
	printf("%s", s);
	return 0;
}

int strlength(char ch[1000]){
	int length=0;
	while(ch[length]!='\0'){
		length++;
	}
	return length;
}

void conc_str(char str[], char s[]){
	int len, i=0, j=0;
	len=strlength(str);
	for(i=0; i<len; i++){
		if((str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z')){
			s[j]=str[i];
			j++;
		}
	}
	
}
