#include<iostream>

int rev(int);

int main(){
	int no, r;
	printf("ENTER A NUMBER ");
	scanf("%d", &no);
	r=rev(no);
	printf("REVERSE OF THE NUMBER IS %d", r);
	return 0;
}

int rev(int no){
	int r=0;
	while(no>10){
		r+=no%10;
		r=r*10;
		no=no/10;
	}
	r+=no;
	return r;
}
