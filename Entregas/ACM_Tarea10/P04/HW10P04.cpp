/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW10P04
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <string>

using namespace std;
//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	
  string s0 ("string inicial");
  // Los constructores son usados en el mismo orden en el que se presentan en el PDF:
  string s1;
  string s2 (s0);
  string s3 (s0, 8, 3);
  string s4 ("Una sucesion de caracteres", 6);
  string s5 ("Otra sucesion de caracteres");
  string s6 (10, '+');
  string s7a (10, 65);
  string s7b (s0.begin(), s0.begin()+7);

  cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
  cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6: " << s6;
  cout << "\ns7a: " << s7a << "\ns7b: " << s7b << endl;

}
//------------------------------------------------------------
