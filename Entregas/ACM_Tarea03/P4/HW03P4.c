/*---------------------------------------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW01P04
Andrés César Magaña Martínez
cesar@cimat.mx

---------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//---------------------------------------------------------------------------------------------
//Función para crear una matriz de tres dimensiones.
unsigned int *** create_matrix( int height, int width, int length ) {
	int k, l;
	unsigned int *** matrix;
	matrix = (unsigned int ***) malloc( height * sizeof(unsigned int *) );
	for ( k = 0; k < height; k++ )
		{
		matrix[k] = (unsigned int **) malloc (width * sizeof(unsigned int));
		for ( l = 0; l < width; l++ )
				matrix[k][l] = (unsigned int*) malloc (length * sizeof(unsigned int));
		}
	return matrix;
}


//---------------------------------------------------------------------------------------------
//Función para liberar la memoria de una matriz de tres dimensiones.
void free_matrix(unsigned int ***matrix, int height, int width){
	int k, l;
	for (k = 0; k < height; k++)
		{
		for (l = 0; l < width; l++)
				free(matrix[k][l]);
		free(matrix[k]);
		}
	free(matrix);
}


//---------------------------------------------------------------------------------------------
//Función para llenar una matriz de tres dimensiones con valores aleatorios.
void fill_matrix_pseudo_randomly( unsigned int ***matrix, int height, int width, int length ){
	int i,j,k;

	
	for ( i=0; i<height; i++ )
		for ( j=0; j<width; j++ )
			for ( k=0; k<length; k++ )
				{	
				matrix[i][j][k] = rand();
				}
}


//---------------------------------------------------------------------------------------------
//Función para pintar una matriz de tres dimensiones.
void print_matrix( unsigned int ***matrix, int height, int width, int length ){
	int i,j,k;

	for ( i=0;i<height;i++)
		for ( j=0;j<width;j++)
			for ( k=0;k<length;k++)
				printf("rand[%d][%d][%d] = %d\n",i,j,k,matrix[i][j][k]);

}


//---------------------------------------------------------------------------------------------

int main (int argc, const char * argv[]) {
	int height = 100;
	int width  = 100;
	int length = 100;
	unsigned int ***a;
  srand (time(NULL));	

	
	a = create_matrix( height, width, length );
	printf("La matriz ha sido creada.\n");
	fill_matrix_pseudo_randomly( a, height, width, length );	
	//Descomentar para mostrar la matriz:
	//print_matrix( a, height, width, length );
	printf("La matriz esta llena con valores pseudo-aleatorios.\n");
	free_matrix( a, height, width );
	printf("La memoria usada por la matriz ha sido liberada.\n");
	
	return 0;
}

//---------------------------------------------------------------------------------------------
