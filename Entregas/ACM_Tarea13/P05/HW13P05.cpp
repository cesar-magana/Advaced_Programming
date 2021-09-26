/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW13P05
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>

using namespace std;

class Caja{
};

class CajaRegalo : public Caja{
	public:
		virtual void abrirRegalo()
			{
			cout << "REGALO" << endl;
			}
};

class CajaBomba : public Caja{
public:
	virtual void prenderBomba()
		{
		cout << "BOMBA!!" << endl;
		}

};

//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	CajaRegalo c;
	CajaRegalo *cptr = &c;
	CajaRegalo **cptrptr = &cptr;
	//Al descomentar la siguiente línea nos marcará un error.
	//Caja **jptrptr = cptrptr;
	//Con la siguiente línea activa obtendremos el resultado no deseado.
	Caja **jptrptr = reinterpret_cast <Caja**>(cptrptr);
	CajaBomba b;
	CajaBomba *bPtr = &b;
	*jptrptr = bPtr;
	cptr->abrirRegalo();
	return 0;
}
//------------------------------------------------------------
