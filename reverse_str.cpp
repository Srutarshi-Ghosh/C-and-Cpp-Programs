#include<iostream>

int strlength(char[100]);
void rev_str(char[100], int);

int main(){
	char str[100];
	int length, i;
	printf("Enter a string \n");
	gets(str);
	length=strlength(str);
	rev_str(str, length);
	printf("Reverse of the string is %s", str);
	return 0;
}

int strlength(char ch[100]){
	int length=0;
	while(ch[length]!='\0'){
		length++;
	}
	return length;
}

void rev_str(char str[], int length){
	char temp;
	int i;
	for(i=0; i<length/2; i++){
		temp = str[i];
		str[i] = str[length - i -1];
		str[length-1-i] = temp;
	}
}
