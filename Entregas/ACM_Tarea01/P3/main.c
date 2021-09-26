/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA HW01P03
Andrés César Magaña Martínez
cesar@cimat.mx
NO SUPE COMO QUITAR LOS WARNINGS
--------------------------------------------------------------*/

#include <stdio.h>

int main (int argc, const char * argv[]) {
	unsigned long long a;
	unsigned long long b;
	unsigned long long c;
	double p;	
	//"Positivo más grande que se pueda representar con doubles"
	a = 0x7FEFFFFFFFFFFFFF;
	p = *(double*)&(a);
	printf("Positivo mas grande representable con doubles\n");
	printf("a=%lf \n\n",p);

	//"Segundo positivo más grande que se pueda representar con doubles"
	b = 0x7FEFFFFFFFFFFFFE;
	p = *(double*)&(b);
	printf("Segundo positivo mas grande representable con doubles\n");
	printf("b=%lf \n\n",p);

	c=a-b;
	printf("Diferencia\n");
	printf("a-b=\n%1.350lf \n\n",c);

	//"Positivo más pequeño que se pueda representar con doubles"
	a = 0x10000000000001;
	p = *(double*)&(a);
	printf("Positivo mas pequeno representable con doubles\n");
	printf("a=%1.350lf \n\n",p);

	//"Positivo más pequeño denormalizado que se pueda representar con doubles"
	a = 0x00000000000001;
	p = *(double*)&(a);
	printf("Positivo denormalizado mas pequeno representable con doubles\n");
	printf("a=%1.350lf \n\n",p);

	
	printf("Presione cualquier tecla para salir...\n");	
	getchar();
  return 0;
}
