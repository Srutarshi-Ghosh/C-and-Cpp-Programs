#include<stdio.h>

int checkarmstrong(int);
int power(int, int);

int main(){
	int n, s;
	printf("Enter a no: ");
	scanf("%d", &n);
	s=checkarmstrong(n);
	if(s==1)
		printf("Armstrong number");
	else
		printf("Not an Armstrong number");
	return 0;
}

int checkarmstrong(int n){
	int res=0, dig, no=n;
	while(n>0){
		dig=n%10;
		res+=power(dig, 3);
		n=n/10;
	}
	if(res==no)
		return 1;
	else
	return 0;
	
}

int power(int n, int p){
	int i=1, res=1;
	while(i<p+1){
		res=res*n;
		i++;
	}
	return res;
}
