/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW05P04
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

//------------------------------------------------------------
//Ésta es la función que se va a derivar.
double F ( double x, double y ){
	return x*x*y/2;
}

//------------------------------------------------------------
//Esta "función" calcula las derivadas parciales de una función y las guarda en parcialx y parcialy. 
int DerivadaParcial( double x_0, double y_0, double h, double (*f)( double, double ), double *parcialx, double *parcialy ){
	if ( h==0 ) 
		return -1;
	*parcialx = ((*f)(x_0+h,y_0)-(*f)(x_0-h,y_0))/(2*h);
	*parcialy = ((*f)(x_0,y_0+h)-(*f)(x_0,y_0-h))/(2*h);
	return 0;
}


//------------------------------------------------------------
int main (int argc, const char * argv[]) {
	double x0 = 5.0;
	double y0 = 3.0;
	double h = 0.00000001;
	double parcialx, parcialy;

	if ( DerivadaParcial(x0, y0, h, &F, &parcialx, &parcialy) < 0 )
		return -1;
	printf("Las derivadas parciales de F( x, y ) en ( %lf,%lf ) son: ( %lf, %lf ).\n",x0,y0,parcialx, parcialy);
	getchar();
	return 0;
}
//------------------------------------------------------------
