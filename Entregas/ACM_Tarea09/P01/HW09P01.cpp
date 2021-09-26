/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW09P01
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
using namespace std;

//------------------------------------------------------------
class Federal
		{
		private:
				class Estatal
					{
					private:
							class Municipal
								{
								public:
										void Municipal::imprimir();
								};					
					public:
							Municipal _Municipal;
							void Estatal::imprimir();
					};
						
		public:
				Estatal _Estatal;
				void Federal::imprimir();

		};


//------------------------------------------------------------
void Federal::imprimir(){
	cout << "Federal" << endl;
}		


//------------------------------------------------------------
void Federal::Estatal::imprimir(){
	cout << "Estatal" << endl;
}		


//------------------------------------------------------------
void Federal::Estatal::Municipal::imprimir(){
	cout << "Municipal" << endl;
}			


//------------------------------------------------------------
int main (int argc, char * const argv[]) {
    Federal _Federal;
		
		_Federal.imprimir();
		_Federal._Estatal.imprimir();
    _Federal._Estatal._Municipal.imprimir();
		
    return 0;
}
//------------------------------------------------------------
