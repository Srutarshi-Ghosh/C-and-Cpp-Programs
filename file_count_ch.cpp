#include<stdio.h>

int main(){
	char ch;
	int dig=0, words=0, lc=0, sp=0, sc=0; 
	FILE *fsrc, *ftar;
	fsrc = fopen("sample.txt", "r");
	ftar = fopen("info.txt", "w");
	do{
		ch = fgetc(fsrc);
		if(ch>='0' && ch<='9')
			dig++;
		else if(ch>='A' && ch<='Z')
			uc++;
		else if(ch>='a' && ch<='z')
			lc++;
		else if(ch==' ')
			sp++;
		else
			sc++;
	}while(ch!=EOF);
	fprintf(ftar, "%s%d\n", "Number of digits: ", dig);
	fprintf(ftar, "%s%d\n", "Number of spaces: ", sp);
	fprintf(ftar, "%s%d\n", "Number of upper case characters: ", uc);
	fprintf(ftar, "%s%d\n", "Number of lower case characters: ", lc);
	fprintf(ftar, "%s%d\n", "Number of special characters: ", sc-1);

	fclose(fsrc);
	fclose(ftar);
	return 0;
}
