/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW03P05
Andrés César Magaña Martínez
cesar@cimat.mx

--------------------------------------------------------------*/

#include <stdlib.h>
 
void reinit ( int **ptr ) { 
	if ( *ptr !=NULL) free( *ptr ) ; 
	*ptr = ( int* ) calloc( 10, sizeof(int) ) ; 
} 


int main ( ) { 
	int *a = ( int* ) calloc( 10, sizeof(int) );
	reinit ( &a ) ; 
	return 0;
} 