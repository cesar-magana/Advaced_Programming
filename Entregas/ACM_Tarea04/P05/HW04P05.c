/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW04P05
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/

#include <stdio.h>

//------------------------------------------------------------
//Función que muestra la sintaxis del programa.
void ShowSyntax(const char * nombre){
   printf("Sintaxis: \n  %s [PARAMETROS]\n",nombre);
   printf ("\
        -n,	Numero de linea.\n\
        -k,	Numero de caracter en la linea.\n");
}


//------------------------------------------------------------
//Función que maneja las entradas de la línea de comando para este problema.
int HandleParameters(int argc, const char * argv[], int *k, int *n){
	int arg=1;
	if (argc<6)
		{
		ShowSyntax(argv[0]);
		return 0;
		}
		
	while ( arg<argc-1 )
		{
		switch(argv[arg][1])
			{
			case 'k':
				*k = atoi(&argv[arg+1][0]);
			break;

			case 'n':
				*n = atoi(&argv[arg+1][0]);
			break;

			default:
				ShowSyntax(argv[0]);
				return 0;
			}
		arg+=2;
    }
	return 1;
}


//------------------------------------------------------------
int main (int argc, const char * argv[]) {
	int i,j;
	int k,n	;
	char linea[300];
	
	if ( !HandleParameters( argc, argv, &k, &n) ) 
		return 0;
	
	FILE *ENTRADA;
	printf( "Archivo: %s --> ", argv[5] );

	if((ENTRADA=fopen(argv[5],"r")) == NULL)
		{
		fprintf(stderr,"Error al abrir el archivo.\n");
		return 0;
		}
	printf( "Archivo abierto.\n\n" );
	
	i=0;
	do 
		{
		fgets( linea, 200, ENTRADA );			
		if ( i==n )
			{
			j=0;
			while ( linea[j]!='\n' && j<200 ) j++ ;
			if ( k<j ) printf( "El caracter en la linea %d posicion %d es '%c'\n",n,k,linea[k] );
			else printf( "xxx" );
			}
		i++;
		}
	while (i<n+1);

	fclose(ENTRADA);
	getchar();
	return 0;
}
//------------------------------------------------------------
