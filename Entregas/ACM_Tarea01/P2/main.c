/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA HW01P02
Andrés César Magaña Martínez
cesar@cimat.mx

--------------------------------------------------------------*/

#include <stdio.h>

int main (int argc, const char * argv[]) {
	unsigned int a;
	float p;	
	
	//"-0"
	a = 0x80000000;
	p = *(float*)&a;
	printf("Cero negativo \n");
	printf("p=%f \n\n",p);
			
	//"Número denormalizado"
	a = 0x00400000;
	p = *(float*)&a;
	printf("Numero denormalizado \n");
	printf("p=%f \n\n",p);
	
	//"Positivo más pequeño que se pueda representar"
	a = 0x00800001;
	p = *(float*)&a;
	printf("Positivo mas pequeno representable \n");
	printf("p=%1.150f \n\n",p);

	//"Positivo más grande que se pueda representar"
	a = 0x7F7FFFFF;
	p = *(float*)&a;
	printf("Positivo mas grande representable \n");
	printf("p=%f \n\n",p);

	//"Mas Infinito"
	a = 0x7F800000;
	p = *(float*)&a;
	printf("Mas infinito \n");
	printf("p=%f \n\n",p);

	//"Menos Infinito"
	a = 0xFF800000;
	p = *(float*)&a;
	printf("Menos infinito \n");
	printf("p=%f \n\n",p);

	//"NaN"
	a = 0x7F8C0000;
	p = *(float*)&a;
	printf("NaN \n");
	printf("p=%f \n\n",p);
	
	printf("Presione cualquier tecla para salir...\n");
	getchar();
  return 0;
}
