/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW23P02
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <queue>

using namespace std;

//------------------------------------------------------------
template <class T>
class QueueStack
	{
	public:
		QueueStack(){};
		~QueueStack(){};
		void push(const T &_data)
			{
			queue<T> temporal;
			temporal.push(_data);
			while( !fila.empty() )
				{
				temporal.push( fila.front() );
				fila.pop();
				}
			while( !temporal.empty() )
				{
				fila.push( temporal.front() );
				temporal.pop();
				}
			}
		void pop()
			{
			fila.pop();
			}
		T &top()
			{
			return fila.front();
			}
		unsigned int size() const
			{
			return fila.size();
			}
	private:
		queue<T> fila;
	};


//------------------------------------------------------------
int main()
	{
	QueueStack<int> qsInt;
	cout << "Insertando objetos..." << endl;
	for( int i = 0; i < 5; i++ )
		{
		qsInt.push(rand()%100);
		cout << qsInt.top() << endl;
		}
	cout << endl;
	cout << "Eliminando ultimos 2 objetos insertados... " << endl;
	cout << qsInt.top() << endl;
	qsInt.pop();
	cout << qsInt.top() << endl;
	qsInt.pop();
	cout << endl;
	cout << "Insertando nuevamente objetos..." << endl;
	for( int i = 0; i < 5; i++ )
		{
		qsInt.push(rand()%100);
		cout << qsInt.top() << endl;
		}
	cout << endl;
	cout << endl << endl << "Eliminando todos los objetos..." << endl;
	while( qsInt.size() )
		{
		cout << qsInt.top() << endl;
		qsInt.pop();
		}
	return 0;
	}
//------------------------------------------------------------

