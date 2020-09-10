#include<iostream>

int palin(int);

int main(){
	int no, x;
	printf("ENTER A NUMBER ");
	scanf("%d", &no);
	x=palin(no);
	if(x==1)
		printf("NO IS PALINDROME");
	else
		printf("NO IS NOT PALINDROME");
	return 0;
}

int palin(int no){
	int i, a, l;
	char arr[100];
	sprintf(arr, "%d", no);
	l=strlen(arr);
	for(i=0; i<l/2; i++){
		a=no%10;
		if(arr[i]!=a)
			return 0;
		no=no/10;
	}
	return 1;
}
