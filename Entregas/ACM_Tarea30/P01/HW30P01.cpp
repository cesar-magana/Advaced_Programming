/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW30P01
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/

#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

//------------------------------------------------------------
template<class T>
bool is_heap(T c)
	{
	int n=c.size();
	for(int k=0;2*k+1<=n-1;k++)
		{
		if(c[k]<c[2*k+1])
			return false;
		if((2*k+2)<=n-1 && c[k]<c[2*k+2])
			return false;
		}
	return true;
	}

//------------------------------------------------------------
int main() {
	vector<int> vheap;
	vheap.resize(7);
	vheap[ 0 ] = 82;
	vheap[ 1 ] = 67;
	vheap[ 2 ] = 43;
	vheap[ 3 ] = 49;
	vheap[ 4 ] = 10;
	vheap[ 5 ] = 32;
	vheap[ 6 ] = 43;		
	
	cout << "Primera prueba: ";
	cout << ( is_heap(vheap)?"Si":"No")	<< " es monticulo." << endl;

	vheap[ 0 ] = 66;

	cout << "Segunda prueba: ";
	cout << ( is_heap(vheap)?"Si":"No")	<< " es monticulo." << endl;

	deque<int> dheap;
	dheap.resize(8);
	dheap[ 0 ] = 8;
	dheap[ 1 ] = 7;
	dheap[ 2 ] = 4;
	dheap[ 3 ] = 6;
	dheap[ 4 ] = 3;
	dheap[ 5 ] = 2;
	dheap[ 6 ] = 1;		
	dheap[ 7 ] = 5;		
		
	cout << "Tercera prueba: ";
	cout << ( is_heap(dheap)?"Si":"No")	<< " es monticulo." << endl;

	cout << "Cuarta prueba: ";
	dheap[ 7 ] = 7;
	cout << ( is_heap(dheap)?"Si":"No")	<< " es monticulo." << endl;

	return 0;
}
//------------------------------------------------------------