/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW09P02
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/

#include <iostream>
#include <vector>

using namespace std;


template<class T>
class Queue
	{
	public:

					Queue( ) : index(0){
					}

					bool empty(){
						return data.size() == 0;
					}

					void push(const T &_newdata){
						data.push_back(_newdata);
						index++;
					}

					void pop(){
						if( index == 0 )
							throw 1;
						data.erase(data.begin());
						index--;
					}

					T &front(){
						if( index == 0 )
							throw 1;
						return data[0];
						}

						T &back(){
						if( index == 0 )
							throw 1;
						return data[index - 1];
						}

						class iterator;
						friend class iterator;

						class iterator
								{
								public:

											iterator(Queue &is) : queueRef(is), index(0){}
											iterator(Queue &is, bool) : queueRef(is), index(queueRef.data.size()){}

											T &operator *()
												{
												return queueRef.data[index];
												}

											T &operator++() // prefix
												{
												if( index >= queueRef.data.size() - 1 )
													throw 1;
												return queueRef.data[++index];
												}

											T &operator++(int) // postfix
												{
												if( index >= queueRef.data.size() )
													throw 1;
												return queueRef.data[index++];
												}

											T &operator+=(const int &ind) // postfix
												{
												if( index + ind >= queueRef.data.size() )
													throw 1;
												index += ind;
												return queueRef.data[index];
												}

											T &operator--() // prefix
												{
												if( index == 0 )
													throw 1;
												return queueRef.data[--index];
												}

											T &operator--(int) // postfix
												{
												if( index == 0 )
													throw 1;
												index--;
												return queueRef.data[index];
												}

											bool operator == (const iterator &otro) const
												{
												return index == otro.index;
												}

											bool operator != (const iterator &otro) const
												{
												return index != otro.index;
												}

					private:
								Queue &queueRef;
								unsigned int index;
					};

		iterator begin()
			{
			return iterator(*this);
			}

		iterator end()
			{
			return iterator(*this, true);
			}

	private:

				unsigned int index;
				vector<T> data;
};

int main(){
	Queue<int> q1;
	Queue<float> q2;

	for( int i = 0; i < 10; i++ )
		{
		q1.push( rand() % 255 );
		q2.push( rand() % 255 * rand()/float(1 << 15) );
		cout << q1.back() << "  " << q2.back() << endl;
		}
	cout << endl << endl;
	Queue<int>::iterator iterq1 = q1.begin();
	Queue<float>::iterator iterq2 = q2.begin();;

	// Recorrido int
	cout << "Elementos de la queue 1" << endl;
	for( ; iterq1 != q1.end(); iterq1++ )
			cout << *iterq1 << endl;
	cout << endl << endl;

	// Recorrido float
	cout << "Elementos de la queue 2" << endl;
	for( ; iterq2 != q2.end(); iterq2++ )
			cout << *iterq2 << endl;
	cout << endl << endl;

	// Borrado int
	cout << "Borrando elementos de la queue 1" << endl;
	while( !q1.empty() )
		{
		cout << q1.front() << endl;
		q1.pop();
		}

	// Borrado float
	cout << "Borrando elementos de la queue 2" << endl;
	while( !q2.empty() )
		{
		cout << q2.front() << endl;
		q2.pop();
		}
	return 0;
}