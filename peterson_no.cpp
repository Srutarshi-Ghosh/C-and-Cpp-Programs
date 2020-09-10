#include<stdio.h>

int fact(int);
void paterson_no(int);
int main(){
	int no;
	printf("Enter a number: ");
	scanf("%d", &no);
	paterson_no(no);
	return 0;
}

void paterson_no(int no){
	int sum=0, n=no;
	while(n>0){
		sum+=fact(n%10);
		n=n/10;		
	}
	if(sum==no)
		printf("Paterson number");
	else
		printf("Not a Paterson number");
}

int fact(int no){
	int res=1, i;
	for(i=2; i<=no; i++){
		res*=i;
	}
	return res;
}
