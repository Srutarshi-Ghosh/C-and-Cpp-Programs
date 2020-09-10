#include<iostream>

int fact(int)
int comb(int, int);
int series(int, int, int);

int main(){
	int n, r, i, ans=0;
	printf("ENTER N");
	scanf("%d", &n);
	printf("ENTER R");
	scanf("%d", &r);
	printf("ENTER I");
	scanf("%d", &i);
	if(n<r)
		printf("INVALID INPUT");
	else{
		ans=series(n, r, i);
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

	return (int)fact(n)/(fact(n-r)*fact(r));
}

int series(int n, int r, int i){
	int ans=0;
	i--;
	while(i>=0){
		ans += comb(n, r+i);
		i--;
	}
	return ans;
}
