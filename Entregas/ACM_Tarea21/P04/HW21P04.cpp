/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW21P04
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>

using namespace std;

//------------------------------------------------------------
template<class T>
class MyDeque
	{
	public:
		MyDeque() : m_size(1000)
			{
			try
				{
				data = new T[m_size];
				pfront = pback = data;
				}
			catch(...)
				{
				delete[] data;
				cout << "Se ha arrojado una excepcion..." << endl;
				throw;
				}
			}

		MyDeque(int max_size) throw (int) : m_size(max_size)
			{
			try
				{
				data = new T[m_size];
				pfront = pback = data;
				}
			catch(...)
				{
				delete[] data;
				cout << "Se ha arrojado una excepcion..." << endl;
				throw;
				}
			}

		MyDeque(int max_size, const T &copy) : m_size(2*max_size)
			{
			try
				{
				data = new T[m_size];
				for( int i = 0; i < max_size; i++ )
						data[i] =  copy;
				pfront = data;
				pback  = data + max_size - 1;
				}
			catch(...)
				{
				delete[] data;
				cout << "Se ha arrojado una excepcion..." << endl;
				throw;
				}
			}

		~MyDeque()
			{
			delete[] data;
			}

		// get
		T front() throw(int)
			{
			if( size() == 0 )
				throw 1;
			return *pfront;
			}

		T back() throw(int)
			{
			if( size() == 0 )
				throw 1;
			// regresar el frente
			return *pback;
			}

		T* begin()
			{
			return pfront;
			}

		T* end()
			{
			return back;
			}

		unsigned int size()
			{
			if( pfront <= pback )
					return (pback - pfront);
			return m_size - (unsigned int)(pfront - pback);
			}

		void clear()
			{
			pfront = pback = data;
			}

		// push y pop
		void push_front(const T &d )
			{
			if( size() == m_size - 1 )
					throw 1;

			prevPos(pfront);
			*pfront = d;
			}

		void push_back(const T &d )
			{
			if( size() == m_size - 1 )
					throw 1;

			*pback = d;
			nextPos(pback);
			}

		void pop_front()
			{
			if( size() == 0 )
					throw 1;
			nextPos(pfront);
			}

		void pop_back()
			{
			if( size() == 0 )
					throw 1;
			prevPos(pback);
			}

	private:
		unsigned int m_size;
		T *data, *pfront, *pback;

		void nextPos(T* &pp)
			{
			if( pp == data + m_size - 1 )
				{
				pp = data;
				return;
				}
			pp++;
			}

		void prevPos(T* &pp)
			{
			if( pp == data )
				{
				pp = data + m_size - 1;
				return;
				}
			pp--;
			}
	};


//------------------------------------------------------------
int main()
	{
	MyDeque<int> dint1;
	MyDeque<int> dint2(100);
	MyDeque<int> dint3(100, 1);
	dint1.push_back(1);
	dint1.push_back(2);
	dint1.push_back(3);
	dint1.push_front(0);
	dint1.pop_front();
	return 0;
	}
//------------------------------------------------------------
