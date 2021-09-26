/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW04P07
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/

#include <stdio.h>

//------------------------------------------------------------
//Función que muestra la sintaxis del programa.
void ShowSyntax(const char * nombre){
   printf("Sintaxis: \n  %s [ARCHIVO DE ENTRADA] [ARCHIVO DE SALIDA]\n",nombre);
}


//------------------------------------------------------------
//Codificador
char Coder(char c, int recorre)
	{
	if( isalpha( c ) )
		{
		c = tolower(c);
		return (char)( 97 + ( ( c - 97 ) + recorre ) % 26);
		}
	else return c;
	}


//------------------------------------------------------------
int main (int argc, const char * argv[]) {
	char c;
	int recorre;
	FILE *ENTRADA;
	FILE *SALIDA;

	if (argc<3)
		{
		ShowSyntax(argv[0]);
		return 0;
		}

	printf( "Introduzca un numero para recorrer:\n" );
	scanf( "%d",&recorre );

	if((ENTRADA=fopen(argv[1],"r")) == NULL)
		{
		fprintf(stderr,"Error al abrir el archivo entrada.txt.\n");
		return 0;
		}

	if((SALIDA=fopen(argv[2],"w")) == NULL)
		{
		fprintf(stderr,"Error al abrir el archivo salida.txt.\n");
		return 0;
		}

	do 
		{
		c = fgetc (ENTRADA);
		fprintf (SALIDA, "%c",Coder(c,recorre) );
    } 
	while (c != EOF);
	
	
	fclose(ENTRADA);
	fclose(SALIDA);
	getchar();
	return 0;
}
//------------------------------------------------------------
