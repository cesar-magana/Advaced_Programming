/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW15P05
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>

using namespace std;
//------------------------------------------------------------
class Base
	{
	private:
		int x;
	public:
		virtual void setX()
			{
			x = 120;
			cout << x << endl;
			}
	};


//------------------------------------------------------------
class Derivada : virtual public Base
	{
	private:
		int x;
	public:
		void setX()
			{
			x = 600;
			cout << x << endl;
			}
	};


//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	Derivada d;
	Derivada *DerivadaPtr = &d;
	DerivadaPtr->setX();
	Base *BasePtr = &d;
	BasePtr->setX();
	getchar();
	return 0;
}
//------------------------------------------------------------
