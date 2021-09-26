/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW05P03
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//------------------------------------------------------------
//Función que muestra la sintaxis del programa.
void ShowSyntax(const char * nombre){
   printf("Sintaxis: \n  %s [NOMBRE DEL ARCHIVO]\n\n",nombre);
}


//------------------------------------------------------------
//Función que cuenta las funciones en una cadena de caracteres.
int CountFunctions(const char * character){
	int i;
	int contador = 0;
	int llave = 0;
	char anterior;
	for( i=0;i<strlen(character);i++ )
		{
		if (character[i]!=' ' && character[i]!='\n' && character[i]!='\t' && character[i]!='\r')
			{
			//Aquí se cuentan funciones, clases, estructuras ...
			if ( character[i]=='{' ) if ( 0==llave++ ) contador++;
			if ( character[i]=='}' ) llave--;			
			//Aquí se descuentan las que no sean funciones
			if ( llave==0 && character[i]==';' && anterior=='}') contador--;
			anterior=character[i];
			}
		}
	return contador; 
}



//------------------------------------------------------------
int main (int argc, const char * argv[]) {

	int cuantas = 0;
	long length;
	FILE *ENTRADA;
	char *w;
	if(argc < 2)
		{
		ShowSyntax(argv[0]);
		return -1;
		}
	if((ENTRADA=fopen(argv[1],"r")) == NULL)
		{
		fprintf(stderr,"Error al abrir el archivo.\n");
		return 0;
		}
	fseek(ENTRADA, 0, SEEK_END);
	length = ftell(ENTRADA);
	fseek(ENTRADA, 0, SEEK_SET);
	w = (char *) malloc(length*sizeof(char *));
	if ( w==NULL) return 0;
	fread(w, sizeof(unsigned int), length, ENTRADA);
	fclose(ENTRADA);
	cuantas = CountFunctions(w);
	free(w);
	printf( "Numero de funciones en %s: %d.\n", argv[1], cuantas );
	getchar();
	return 0;
	
}
//------------------------------------------------------------
