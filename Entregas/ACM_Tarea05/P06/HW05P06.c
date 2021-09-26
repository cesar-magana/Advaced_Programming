/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW05P06
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>;
#include <string.h>;

//------------------------------------------------------------
int main (int argc, const char * argv[]) {
	int i;
	int contador_lineas = 0;
	int contador_caracteres = 0;
	long length;
	char *nombre = "HW05P06.c";
	
	FILE *ENTRADA;
	char *w;
	 
	if((ENTRADA=fopen(nombre,"r")) == NULL)
		{
		fprintf(stderr,"Error al abrir el archivo.\n");
		return 0;
		}

	fseek(ENTRADA, 0, SEEK_END);
	length = ftell(ENTRADA);
	fseek(ENTRADA, 0, SEEK_SET);
	w = (char *) malloc(length*sizeof(char *));
	if ( w==NULL ) return 0;
	fread(w, sizeof(unsigned int), length, ENTRADA);
	fclose(ENTRADA);

	for( i=0;i<strlen(w);i++ )
		{
		if ( w[i] != '\n' )contador_caracteres++;
		else contador_lineas++;
		}
	free(w);
	printf( "Numero de caracteres en %s: %d.\n", nombre, contador_caracteres );
	printf( "Numero de lineas en %s: %d.\n", nombre, contador_lineas);
	getchar();
	return 0;
}
//---------------------------------------------------------
