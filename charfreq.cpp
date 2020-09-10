#include<iostream>

int strlength(char[100]);
void charfreq(char[100]);

int main(){
	char ch[100];
	printf("Enter a string \n");
	gets(ch);
	charfreq(ch);
	return 0;
}

int strlength(char ch[100]){
	int length=0;
	while(ch[length]!='\0'){
		length++;
	}
	return length;
}

void charfreq(char str[]){
	int len, i, j, freq=1;
	len=strlength(str);
	for(i=0; i<len-1; i++){
		if(str[i]==' ')
			continue;
		for(j=i+1; j<len; j++){
			if(str[i]==str[j]){
				freq++;
				str[j]=' ';
			}
		}
		printf("The frequency of the character %c is %d\n", str[i], freq);
		freq = 1;
	}
	if(str[len-1]!=' '){
		printf("The frequency of the character %c is %d", str[len-1], freq);
	}
}
	
