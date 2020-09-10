#include<stdio.h>
#include<stdlib.h>

int strlength(char[]);
void add(char[], char[]);

int main(){
	char num1[100], num2[100], i, len;
	int* res;
	printf("Enter first no: ");
	scanf("%s", num1);
	printf("Enter second no: ");
	scanf("%s", num2);
	printf("The number after adding is: \n");
	add(num1, num2);
	return 0;
}

void add(char num1[], char num2[]){
	int len1, len2, max, carry=0, i, j, len;
	int* res;
	len1=strlength(num1);
	len2=strlength(num2);
	if(len1>len2)
		max=len1;
	else
		max=len2;
	res = (int*)malloc(sizeof(int)*(max+1));
	i=len1-1;
	j=len2-1;
	len=max;
	while(i>=0 && j>=0){
		res[max] = (num1[i] - '0' + num2[j] - '0' + carry)%10;
		carry = (num1[i] - '0' + num2[j] - '0' + carry)/10;
		i--; 
		j--;
		max--;
	}
	
	while(i>=0){
		res[max] = (num1[i] - '0' + carry)%10;
		carry=0;
		i--;
		max--; 
	}
	
	while(j>=0){
		res[max] = (num1[j] - '0' + carry)%10;
		carry=0;
		j--;
		max--; 
	}
	res[0]=carry;
	for(i=0; i<=len; i++){
		if(i==0 && res[i]==0)
			continue;
		printf("%d", res[i]);
	}

}

int strlength(char ch[100]){
	int length=0;
	while(ch[length]!='\0'){
		length++;
	}
	return length;
}
