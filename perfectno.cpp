#include<stdio.h>

int checkperfect(int);
int power(int, int);

int main(){
	int n, s;
	printf("Enter a no: ");
	scanf("%d", &n);
	s=checkperfect(n);
	if(s==1)
		printf("Armstrong number");
	else
		printf("Not an Armstrong number");
	return 0;
}

int checkperfect(int n){
	int res=0, dig, no=n, i;
	for(i=1; i<=n/2; i++){
		if(n%i==0){
			res+=i;
		}
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
