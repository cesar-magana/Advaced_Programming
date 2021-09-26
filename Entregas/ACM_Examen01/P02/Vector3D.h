/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I EX01P02 Clase Vector3D
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/

#ifndef Vector3DH
#define Vector3DH

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define FOR(i, n) for( int i = 0, _n = (n); i < _n; i++ )

//---------------------------------------------------------------------------

template < class T >
class Vector3D
	{
	public:
		T x;
		T y;
		T z;
		Vector3D( )
			{
			this->x = 0.0;
			this->y = 0.0;
			this->z = 0.0;
			}
		Vector3D( T x, T y, T z )
			{
			this->x = x;
			this->y = y;
			this->z = z;
			}
		~Vector3D() { }
		
	Vector3D<T> operator + ( const Vector3D<T> &other ) const
		{
		Vector3D<T> sum( this->x + other.x, this->y + other.y, this->z + other.z );
		return sum;
		}

	Vector3D<T> operator - ( const Vector3D<T> &other ) const
		{
		Vector3D<T> sum( this->x - other.x, this->y - other.y, this->z - other.z );
		return sum;
		}

	T operator * ( const Vector3D<T> &other ) const
		{
		T sum = this->x * other.x+ this->y * other.y+ this->z - other.z;
		return sum;
		}



/*
	Vector3D<T> operator - ( const Vector3D<T> &other, int ) const
		{
		Vector3D<T> sum( -this->x , -this->y , -this->z );
		return sum;
		}
*/


	Vector3D<T>& operator=(const Vector3D<T> &o) 
		{ 
		x = o.x; 
		y = o.y;
		z = o.z; 
		return *this; 
		} 		
		
	T norm()
		{
		return sqrt(this->x*this->x+this->y*this->y+this->z*this->z);
		}
	};
	
template<class T>
ostream &operator << ( ostream &out, Vector3D<T> &input )
	{
	out << "(" << input.x << "," << input.y << "," << input.z << ")";
	return out;
	}

/*
template<class T>
Vector3D<T> operator * ( const Vector3D<T> &other ) const
	{
	Vector3D<T> sum( this->x - other.x, this->y - other.y, this->z - other.z );
	return sum;
	}
*/


#endif
