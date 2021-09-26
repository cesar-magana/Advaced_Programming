/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW08P04
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <fstream>
using namespace std;
#define FOR(i, n) for( int i = 0, _n = (n); i < _n; i++ )

//------------------------------------------------------------
template < class T >
struct Matriz
	{
	public:
		int renglones;
		int columnas;
		
		//Inicializa la matriz.		
		int Inicializa( char* archivo )
			{
			ifstream in( archivo );
			in >> renglones >> columnas;
			M=new T*[renglones];
			if (M==NULL) return -1;
			FOR(i, renglones)
				{
				M[i] = new T[columnas];
				if ( M[i]==NULL ) return -1;
				}			 
			FOR(i, renglones)
				FOR(j, columnas)
					in >> M[i][j];
			in.close();
			return 1;
			}

		//Regresa la coordenada (i,j) de la matriz.
		T& operator ()(const unsigned int i, const unsigned int j)
			{
			return M[i][j];
			}

		//Pinta la matriz.
		void Muestra()
			{
			FOR(i, renglones)
				{
				FOR(j, columnas)
					cout << M[i][j] << " " ;
				cout << endl;
				}
			}
		
		//Suma otra matriz a esta.
		int Suma ( Matriz<T> b)
			{
			if ( renglones != b.renglones ) return -1;
			if ( columnas  != b.columnas  ) return -1;
			FOR(i, renglones)
				FOR(j, columnas)
					M[i][j]+=b(i,j);
			return 1;
			}
		
		//Libera la memoria.
		void Destruye()
			{
			FOR (i,columnas)
				delete [] M[i];
			delete[] M;
			}
			
	private:
		T **M;
	};

//------------------------------------------------------------
int main (int argc, char * const argv[]) {

	Matriz<double> A;
	Matriz<double> B;
	
	A.Inicializa("entrada1.txt");
	B.Inicializa("entrada2.txt");

	cout << "Matriz A" << endl;
	A.Muestra();
	cout << "Matriz B" << endl;
	B.Muestra();

	if ( A.Suma(B) == -1)
		cout << "La matrices no son de la misma dimension." << endl;
	else 	
		{
		cout << endl <<"Se ha sumado la matriz B a la matriz A." << endl;
		cout << "Nueva matriz A." << endl;
		A.Muestra();
		}

	A.Destruye();
	B.Destruye();
	return 0;
}
//------------------------------------------------------------
