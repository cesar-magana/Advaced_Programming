/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA HW02P06
Andrés César Magaña Martínez
cesar@cimat.mx

--------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

int main () {
int iteration, i ;
const float pion180 = M_PI / 180.0;
float tang[360];

for ( i =0; i <360; i++)
	tang[i] = fabs ( tan ( pion180*i ) ) ;

for ( iteration =0; iteration <1000; iteration++) 
	{
	for ( i =0; i <360; i++)
		{
		float val = tang[i];
		printf("%f\n",val);
		}
	}
printf("Presione cualquier tecla para salir...\n");
return 0;
}