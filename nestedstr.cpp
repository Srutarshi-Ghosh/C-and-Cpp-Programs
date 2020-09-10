#include<iostream>
#include<stdio.h>

int strlength(char[]);
int neststring(char[], char[]);

int main(){
	char s1[100], s2[100];
	int pos;
	printf("Enter first String: ");
	scanf("%s", s1);
	printf("Enter second String: ");
	scanf("%s", s2);
	pos = neststring(s1, s2);
	printf("%d", pos);
	return 0;
}

int strlength(char ch[100]){
	int length=0;
	while(ch[length]!='\0'){
		length++;
	}
	return length;
}

int neststring(char s1[], char s2[]){
	int i, j=0, pos=-1, flag=0, len1, len2;
	len1=strlength(s1);
	len2=strlength(s2);
	for(i=0; i<len1; i++){
		if(s1[i]==s2[j]){
			pos=i;
			i++;
			j++;
			while(j<len2 && i<len1){
				
				if(s1[i]!=s2[j]){
					j=0;
					i--;
					break;
				}
				i++;
				j++;
			}
			if(j==len2){
				flag=1;
				break;
			}
			else 
				pos=-1;
		}
	}
	return pos;
}


