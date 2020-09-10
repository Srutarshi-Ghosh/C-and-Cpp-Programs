#include<stdio.h>
#include<String.h>

int main(){
	char str[100];
	int i, j, l;
	printf("Enter string: ");
	scanf("%s", str);
	l = strlen(str);
	for(i=l-1; i>0; i--){
		for(j=i; j<l; j++){
			printf("%c", str[j]);
		}
		for(j=0; j<i; j++){
			printf("%c", str[j]);
		}
		printf("\n");
	}
	return 0;
}
