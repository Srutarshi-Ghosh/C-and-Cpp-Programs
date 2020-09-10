#include<stdio.h>

int strlength(char[]);
void swap(char*, char*);
int superascii(char[]);
void bubblesort(int[], int);

int main(){
	char s[100];
	int x;
	printf("Enter a String: ");
	scanf("%s", s);
	x = superascii(s);
	if(x==1)
		printf("yes");
	else
		printf("no");
	return 0;
}

int strlength(char ch[100]){
	int length=0;
	while(ch[length]!='\0'){
		length++;
	}
	return length;
}

void swap(char *x, char *y){
	char temp = *x;
	*x = *y;
	*y = temp;
}

void bubblesort(char arr[], int n){
	int i, j;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if((int)arr[j]>(int)arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
}

int superascii(char str[]){
	int i, len, freq[26];
	len = strlength(str);
	for(i=0; i<26; i++){
		freq[i]=0;
	}
	for(i=0; i<len; i++){
		freq[(int)str[i]-(int)'a']++;
	}
	for(i=0; i<26; i++){
		if(freq[i]>0 && freq[i]!=i+1)
			return 0;
	}
	return 1; 
}

