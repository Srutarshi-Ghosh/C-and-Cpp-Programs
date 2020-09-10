#include<stdio.h>

int conv(int[], char[], int, char*, int);

int main(){
	int no;
	int dig[] = {1, 5, 10, 50, 100, 500, 1000};
	char rom[] = "IVXLCDM";
	char s[20] = "";
	printf("Enter number to convert: ");
	scanf("%d", &no);
	conv(dig, rom, no, s, 0);
	printf("The no after converting is: %s", s);
	return 0;
}

int conv(int dig[], char rom[], int no, char *str, int ind){
	int i, x;
	if(no == 0)
		return 0;
	for(i=6; i>=0; i--){
		x = no - dig[i];
		if(x >= 0){
			str[ind] = rom[i];
			no = x;
			break;
		}
		if(i % 2 !=0 && x < 0 && x >= -1 * dig[i - 1]){
			str[ind] = rom[i - 1];
			str[ind + 1] = rom[i];
			ind++;
			no = x + dig[i - 1];
			break;
		}
		if(i % 2 ==0 && x < 0 && x >= -1 * dig[i - 2]){
			str[ind] = rom[i - 2];
			str[ind + 1] = rom[i];
			ind++;
			no = x + dig[i - 2];
			break;
		}
		
	}
	ind++;
	conv(dig, rom, no, str, ind);
	return 0;
}
