/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW18P01
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <string>

using namespace std;

class String 
	{
	public:
		String(string _original)
			{
			original = _original;
			}
		
		string cons()
			{
			string in = original;
			string out="";
			for ( unsigned int i=0; i< in.length();i++ )
				{
				if	( in[i]!='a' && in[i]!='e' && in[i]!='i' && in[i]!='o' && in[i]!='u' &&
							in[i]!='A' && in[i]!='E' && in[i]!='I' && in[i]!='O' && in[i]!='U'
						)
					out+=in[i];
				}
			return out;
			}
		
		bool operator == ( String &otro)
			{
			if ( this->cons()==otro.cons() )return true;
			else return false;
			}
		
		string original;
	};

//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	String str1("Anita lava la tina");
	String str2("Enite leve le tene");
	
	if ( str1 == str2 )
		{
		cout << "Los strings son iguales: "	<< endl;
		cout << "str1='" << str1.cons() << "' str2='" << str2.cons() << "'"<< endl;
		}
	else
		{
		cout << "Los strings son diferentes. "	<< endl;
		cout << "str1='" << str1.cons() << "' str2='" << str2.cons() << "'"<< endl;
		}
	return 0;
}
//------------------------------------------------------------
