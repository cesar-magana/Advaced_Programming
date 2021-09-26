/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW04P01
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

//------------------------------------------------------------
//Ésta es una función para intentar saber cuántas recursiones se pueden hacer.
int MaxRecursion ( int n ){
	printf("Recursion: %d\n", n);
	return MaxRecursion(n+1);
}


//------------------------------------------------------------
//Ésta es la función a la cual se le aplica la composición.
double F ( double x ){
	return cos(x);
}


//------------------------------------------------------------
//Composición de funciones.
//Composicion(x,f,n) = f(f(...(f(x)))...) 

double Composicion ( double x, double (* funcion)( double ), int n ){
	return (n==0)?x:Composicion( (*funcion)(x), &*(funcion), n-1 ); 
}


//------------------------------------------------------------
int main (int argc, const char * argv[]) {
	
	double entrada = 0.0;
	int n = 300;
	
	printf( "%1.60lf\n", Composicion( entrada, &F, n ) );
	//n=1;
	//MaxRecursion(n);
	getchar();
	return 0;	
}
//------------------------------------------------------------

