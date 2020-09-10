#include<stdio.h>

typedef struct complex{
	int real;
	int img;
}comp;

comp inputcomplex();
comp mulcomplex(comp, comp);

int main(){
	comp c1, c2, res;
 	c1 = inputcomplex();
	c2 = inputcomplex();
	res = mulcomplex(c1, c2);
	printf("The resultant complex is %d + %di", res.real, res.img);
	return 0;
}

comp inputcomplex(){
	comp c;
	printf("Enter real part: ");
	scanf("%d", &c.real); 
	printf("Enter immaginary part: ");
	scanf("%d", &c.img); 
	return c;
}

comp mulcomplex(comp c1, comp c2){
	comp res;
	res.real = (c1.real * c2.real) - (c1.img * c2.img);
	res.img = (c1.real * c2.img) + (c2.real * c1.img);
	return res;
}
