#include<iostream>

int fact(int);
int permutation(int, int);
int series(int, int, int);

int main(){
	int n, r, i, ans;
	printf("ENTER N ");
	scanf("%d", &n);
	printf("ENTER R ");
	scanf("%d", &r);
	printf("ENTER I ");
	scanf("%d", &i);
	if(n<r || i<0)
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

int permutation(int n, int r){

	return (int)fact(n)/fact(n-r);
}

int series(int n, int r, int i){
	int ans=0;
	i--;
	while(i>=0){
		ans += permutation(n, r+i);
		i--;
	}
	return ans;
}
