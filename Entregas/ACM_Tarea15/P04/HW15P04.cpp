/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW15P04
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <string>


using namespace std;
//------------------------------------------------------------
class Animal
	{
	public:
		string name;
		virtual bool operator *(const Animal &otro);
		//virtual bool coexiste( Animal &otro) = 0;
	};


//------------------------------------------------------------
class Cat : public Animal
	{
	public:
		Cat()
			{
			name="Cat";
			}
		bool operator *(const Animal &otro)
			{
			if ( otro.name=="Dog" || otro.name=="Fish") return false;
			else return true;
			//return otro.coexiste(this);
			}
/*		bool coexiste(Dog *d)
			{
			if ( otro.name=="Dog" || otro.name=="Fish") return false;
			else return true;
			return false;
			}*/

	};


//------------------------------------------------------------
class Dog : public Animal
	{
	public:
		Dog()
			{
			name="Dog";
			}
		bool operator *(const Animal &otro)
			{
			if ( otro.name=="Cat" ) return false;
			else return true;
			}
	};


//------------------------------------------------------------
class Horse : public Animal
	{
	public:
		Horse()
			{
			name="Horse";
			}
		bool operator *(const Animal &otro)
			{
			return true;
			}
	};



//------------------------------------------------------------
class Fish : public Animal
	{
	public:
		Fish()
			{
			name="Fish";
			}
		bool operator *(const Animal &otro)
			{
			if ( otro.name=="Cat" ) return false;
			else return true;
			}
	};


//------------------------------------------------------------
class Human : public Animal
	{
	public:
		Human()
			{
			name="Human";
			}
		bool operator *(const Animal &otro)
			{
			return false;
			}
	};
	

//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	Dog		perro;
	Cat		gato;
	Horse caballo;
	Fish	pez;
	Human	humano;
	cout << gato.name << "*" << perro.name << "=" << gato*perro << endl;
	cout << gato.name << "*" << pez.name << "=" << gato*pez << endl;
	cout << gato.name << "*" << caballo.name << "=" << gato*caballo << endl;
	cout << gato.name << "*" << humano.name << "=" << gato*humano << endl;

	cout << perro.name << "*" << gato.name << "=" << perro*gato << endl;
	cout << perro.name << "*" << pez.name << "=" << perro*pez << endl;
	cout << perro.name << "*" << caballo.name << "=" << perro*caballo << endl;
	cout << perro.name << "*" << humano.name << "=" << perro*humano << endl;

	cout << caballo.name << "*" << gato.name << "=" << caballo*gato << endl;
	cout << caballo.name << "*" << pez.name << "=" << caballo*pez << endl;
	cout << caballo.name << "*" << perro.name << "=" << caballo*perro << endl;
	cout << caballo.name << "*" << humano.name << "=" << caballo*humano << endl;

	cout << pez.name << "*" << gato.name << "=" << pez*gato << endl;
	cout << pez.name << "*" << caballo.name << "=" << pez*caballo << endl;
	cout << pez.name << "*" << perro.name << "=" << pez*perro << endl;
	cout << pez.name << "*" << humano.name << "=" << pez*humano << endl;

	cout << humano.name << "*" << gato.name << "=" << humano*gato << endl;
	cout << humano.name << "*" << caballo.name << "=" << humano*caballo << endl;
	cout << humano.name << "*" << perro.name << "=" << humano*perro << endl;
	cout << humano.name << "*" << pez.name << "=" << humano*pez << endl;

	
	return 0;
}
//------------------------------------------------------------
