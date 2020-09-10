#include<iostream>

int fact(int);
int comb(int, int);
int main(){
	int n, r, i, q, m, ans=0;
	printf("ENTER N");
	scanf("%d", &n);
	printf("ENTER R");
	scanf("%d", &r);
	printf("ENTER M");
	scanf("%d", &m);
	printf("ENTER Q");
	scanf("%d", &q);
	printf("ENTER I");
	scanf("%d", &i);
	if(n<r || r>i || m<q || q<i)
		printf("INVALID INPUT");
	else{
		
	while(r!=i+1){
		ans+=comb(n, r)*comb(m, q);
		r++;
		q--;
	}
	printf("%d", ans);
	}
	return 0;
}


int fact(int n){
	int res=1, i;
	for(i=2; i<=n; i++){
		res=res*i;
	}
	return res;
}

int comb(int n, int r){

	return fact(n)/(fact(n-r)*fact(r));
}
	
