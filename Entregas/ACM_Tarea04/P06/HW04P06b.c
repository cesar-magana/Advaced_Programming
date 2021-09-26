/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW04P06b
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/

#include <stdio.h>;
#include <stdlib.h>;
#include <string.h>;

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

	//char *palabra = "oso";
	char *palabra = "ososo";
	//char *palabra = "aba";
	int es;
	
	es=IsPalindrome( palabra );
	if (es) printf("\"%s\" es palindromo.\n",palabra);
	else printf("\"%s\" no es palindromo.\n",palabra);
	getchar();
	return 0;
}


//------------------------------------------------------------


