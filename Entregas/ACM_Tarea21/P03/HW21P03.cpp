/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW21P03
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <vector>

using namespace std;

//------------------------------------------------------------
class Integer
	{
	public:
		static int id;
		Integer(int _i = 0) : i(_i), my_id(id++)
			{
			cout << "Contruyendo " << my_id << " Integer" << endl;
			}

		~Integer()
			{
			cout << "Destruyendo " << my_id << " Integer" << endl;
			}

	private:
		int i;
		int my_id;
	};
//------------------------------------------------------------

int Integer::id = 0;

//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	Integer inte(0);
	vector<Integer> array(10);
	while( 1 )
		{
		array.push_back(inte);
		cout << array.capacity() << endl;
		if( array.capacity() > 40 )
				break;
		}
	return 0;
	}
//------------------------------------------------------------