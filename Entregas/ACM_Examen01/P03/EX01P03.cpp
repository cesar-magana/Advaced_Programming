/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I EX01P03
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class PQ
	{
	public:
		PQ( ) : index(0) { }

		bool empty()
			{
			return data.size() == 0;
			}

		void push(const T &_newdata, int newpriority)
			{
			data.push_back(_newdata);
			priority.push_back( newpriority );
			index++;
			}

		void pop()
			{
			if( index == 0 )
				throw 1;
			data.erase(data.begin());
			priority.erase(priority.begin());
			index--;
			}

		T top(int &_prioridad)
			{
			if( index == 0 )
				throw 1;
			int max_prior=0;
			unsigned int j=0;
			for (unsigned int i=0;i<priority.size();i++)
				{
				if ( priority[i] >= max_prior )
					{
					max_prior=priority[i];
					j=i;
					}
				}
			_prioridad = max_prior;
			return data[j];
			}


		T &front(int &_priority)
			{
			if( index == 0 )
				throw 1;
			_priority = priority[0];
			return data[0];
			}

		T &back(int &_priority)
			{
			if( index == 0 )
				throw 1;
			_priority = priority[index - 1];	
			return data[index - 1];
			}

		int size()
			{
			return priority.size();
			}
	private:
			unsigned int index;
			vector<T> data;
			vector<int> priority;
};

int main(){
	PQ<float> q2;
	int prioridad = rand() % 5;
	
	for( int i = 0; i < 10; i++ )
		{
		q2.push( rand() % 255 * rand()/float(1 << 15), rand() % 5 );
		}
	cout << endl << endl;

	cout << "Tamano de la cola de prioridad: "<< q2.size() << endl;
	cout << "Top: "<< q2.top(prioridad) << " Prioridad: "<< prioridad << endl;

	// Borrado float
	cout << "Borrando elementos de la cola de prioridad" << endl;
	while( !q2.empty() )
		{
		cout << "Elemento: " << q2.front(prioridad) << " Prioridad: "<< prioridad<< endl;
		q2.pop();
		}
	return 0;
}