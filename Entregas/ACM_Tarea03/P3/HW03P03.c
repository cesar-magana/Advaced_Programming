/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW03P03
Andrés César Magaña Martínez
cesar@cimat.mx

--------------------------------------------------------------*/

#include <stdio.h>

//------------------------------------------------------------
// Estructura para un punto en R^3.
typedef struct{
	double x;				// Coordenada x
	double y;				// Coordenada y
	double z;				// Coordenada z
	char name[8];	// Nombre del punto
} point;


//------------------------------------------------------------
// Estructura para un paralelepípedo.
typedef struct{
	point p1;				// Punto p1
	point p2;				// Punto p2
	char name[8];	// Nombre del paralelepípedo
} parallelepiped;


//------------------------------------------------------------
// Esta función verifica si dos puntos p, q son iguales.
int equal ( point p, point q ) {
	if ( p.x != q.x ) return 0;
	if ( p.y != q.y ) return 0;
	if ( p.z != q.z ) return 0;
	return 1;
};


//------------------------------------------------------------
// Esta función verifica si un paralelepípedos A está bien formado.
int verify_parallelepiped ( parallelepiped A ) {
	//Revisa si los puntos son el mismo.
	if ( equal(A.p1, A.p2) ) return 0;
	
	//Revisa si la diagonal dada define un paralelepípedo.
	if ( A.p1.x == A.p2.x )	return 0;
	if ( A.p1.y == A.p2.y )	return 0;
	if ( A.p1.z == A.p2.z )	return 0;

	return 1;
};


//------------------------------------------------------------
// Esta función verifica si dos paralelepípedos A, B son iguales.
int equal_parallelepiped ( parallelepiped A, parallelepiped B ) {
	if ( equal(A.p1,B.p1) && equal(A.p2,B.p2) ) return 1;
	if ( equal(A.p1,B.p2) && equal(A.p2,B.p1) ) return 1;
	return 0;
};


//------------------------------------------------------------
int main (int argc, const char * argv[]) {
	parallelepiped PAR1, PAR2;

	printf("Introduzca las coordenadas de los puntos del primer paralelepípedo separadas por un espacio. Ejemplo: Para (0,0,0),(1,1,1) introduzca: 0 0 0 1 1 1\n");
	scanf ("%lf %lf %lf %lf %lf %lf",&PAR1.p1.x,&PAR1.p1.y,&PAR1.p1.z,&PAR1.p2.x,&PAR1.p2.y,&PAR1.p2.z);

	printf("De la misma manera hacerlo ahora para el segundo paralelepípedo.\n");
	scanf ("%lf %lf %lf %lf %lf %lf",&PAR2.p1.x,&PAR2.p1.y,&PAR2.p1.z,&PAR2.p2.x,&PAR2.p2.y,&PAR2.p2.z);
	
	//Descomentar para introducir los valores dentro del código.
	//Coordenadas del paralelepípedo 1
	/*
	PAR1.p1.x=1;
	PAR1.p1.y=2;
	PAR1.p1.z=4;		
	PAR1.p2.x=2;
	PAR1.p2.y=1;
	PAR1.p2.z=1;
	*/		
	//Coordenadas del paralelepípedo 2
	/*
	PAR2.p1.x=2;
	PAR2.p1.y=1;
	PAR2.p1.z=1;		
	PAR2.p2.x=1;
	PAR2.p2.y=2;
	PAR2.p2.z=4;
	*/


	printf("\n\nPrimer paralelepípedo PAR1: (%lf,%lf,%lf),(%lf,%lf,%lf) \n",PAR1.p1.x,PAR1.p1.y,PAR1.p1.z,PAR1.p2.x,PAR1.p2.y,PAR1.p2.z );
	printf("Segundo paralelepípedo PAR2: (%lf,%lf,%lf),(%lf,%lf,%lf) \n",PAR2.p1.x,PAR2.p1.y,PAR2.p1.z,PAR2.p2.x,PAR2.p2.y,PAR2.p2.z );

	//Revisa si los primeros puntos de cada paralelepipedo son iguales.
	/*
	if ( equal(PAR1.p1, PAR2.p1) )
		printf("\n\nPuntos iguales.\n");
	else 
		printf("Puntos desiguales.\n");
	*/

	//Verifica si los paralelepipedos son válidos.
	if ( verify_parallelepiped( PAR1 ) )
		printf("Paralelepipedo 1 es valido.\n");
	else 
		printf("Paralelepipedo 1 no es valido.\n");

	if ( verify_parallelepiped( PAR2 ) )
		printf("Paralelepipedo 2 es valido.\n");
	else 
		printf("Paralelepipedo 2 no es valido.\n");
	
	//Revisa si los paralelepipedos son iguales.
	if ( equal_parallelepiped(PAR1, PAR2) )
		printf("Paralelepipedos PAR1=PAR2.\n");
	else 
		printf("Paralelepipedos PAR1!=PAR2.\n");
	getchar();
	return 0;
}
//------------------------------------------------------------
