/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW04P06
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/

#include <stdio.h>;
#include <stdlib.h>;
#include <string.h>;
#include <ctype.h>;

//------------------------------------------------------------
//Función que muestra la sintaxis del programa.
void ShowSyntax(const char * nombre){
   printf("Sintaxis: \n  %s [NOMBRE DEL ARCHIVO]\n\n",nombre);
}


//------------------------------------------------------------
//Función no recursiva para encontrar palíndromos.
int IsPalindrome(char *word){
	int i = 0;
	int length = (int) strlen(word);
	int d = length-1;
	int palindrome=1;
	while ( (palindrome == 1) && (i < length) )
		{
		if ( word[i] != word[d] ) 
			palindrome=0;
		else
			{
      i++;
      d--;
			}
		}
	return palindrome;
}


//------------------------------------------------------------
//Función recursiva para encontrar palíndromos.
int IsPalindromeRecursive(char *word, int length){
	if ( length<1 )
		return 1; 
	if ( word[0] == word[length-1] )
		return IsPalindromeRecursive( word+1, length-2 ); 
	else
		return 0;
}



//------------------------------------------------------------
int main (int argc, const char * argv[]) {
	int i,j,p=0;
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
	else
    {
		printf("Palindromos en el archivo %s\n",argv[1]);
 
		fseek(ENTRADA, 0, SEEK_END);
		length = ftell(ENTRADA);
		fseek(ENTRADA, 0, SEEK_SET);
		w = (char *) malloc(length*sizeof(char *));
		fread(w, sizeof(unsigned int), length, ENTRADA);
		fclose(ENTRADA);
 
		char *aux;
		aux = (char *) malloc(strlen(w)*sizeof(char *));
		
		for( i=0,j=0;i<strlen(w);i++ )
			{
			if( w[i] == ' ' || w[i]=='\n' )
				{
				aux[j] = '\0';
        j=0;
				if ( isalpha(aux[strlen(aux)-1]) ) //printf("%d. \"%s\"\n",++p,aux);
					if( IsPalindrome(aux) ) printf("%d. %s\n",++p,aux);
				if ( isnumber(aux[strlen(aux)-1]) ) 
					if( IsPalindrome(aux) ) printf("%d. %s\n",++p,aux);
				if ( ispunct(aux[strlen(aux)-1]) ) 
					if( IsPalindromeRecursive(aux,strlen(aux)-1) ) printf("%d. %s\n",++p,aux);

        }
			else
				{
        if(w[i] != '\t' && w[i] != ' ');
					{
          aux[j] = w[i];
          j++;
          }
				}//else
			}//for
    }//else
	return 0;
}
/*	char *palindromo = "erland";
	int es;
	es=IsPalindrome( palindromo );
	printf("%d", es);
	getchar();
	return 0;
}*/


//------------------------------------------------------------


