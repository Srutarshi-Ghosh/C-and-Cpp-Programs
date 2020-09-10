#include<stdio.h>

int main(){
	char ch;
	FILE *fsrc, *ftar;
	fsrc = fopen("sample.txt", "r");
	ftar = fopen("copy.txt", "w");
	ch = fgetc(fsrc);
	while(ch!=EOF){
		fputc(ch, ftar);
		ch = fgetc(fsrc);
	}
	fclose(fsrc);
	fclose(ftar);
	return 0;
}
