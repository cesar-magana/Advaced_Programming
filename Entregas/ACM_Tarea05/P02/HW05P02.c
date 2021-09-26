/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW05P02
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
 
//------------------------------------------------------------
//Mi función que hace lo mismo que strcmp.
int mystrcmp(const char *s1, const char *s2){
	int i=0;
	int length1 = strlen( s1 );
	int length2 = strlen( s2 );
	if ( length1 > length2 ) return 1;
	if ( length1 < length2 ) return -1;

	for ( i=0; i< length1 ; i++ )
		{
		if ( s1[i]>s2[i] ) return 1;
		if ( s1[i]<s2[i] ) return -1;
		}
	return 0;
	}


//------------------------------------------------------------
int main (int argc, const char * argv[]) {
	char s1[10] = "abeja";
	char s2[10] = "abej";
	int i;
	
  printf( "s1=%s\t", s1 );
  printf( "s2=%s\n", s2 );

  i = mystrcmp( s1, s2 );
  printf( "s1 es " );
  if( i < 0 )  printf( "menor que" );
  else if( i > 0 )  printf( "mayor que" );
  else  printf( "igual a" );
	printf( " s2\n" );

	getchar();
	return 0;
}
//------------------------------------------------------------
