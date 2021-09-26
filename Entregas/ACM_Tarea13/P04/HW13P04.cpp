/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW13P04
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>

using namespace std;
//------------------------------------------------------------
class Image
	{
	public:
	int x;
  Image()
		{
		someMethod();
		}
	virtual void someMethod() 
		{
		cout << "IMAGE" << endl;
		}
	};


//------------------------------------------------------------
class SquareImage: public Image
	{
	public:
  SquareImage()
    {
		someMethod();
    }
	virtual void someMethod() 
		{
		cout << "SQUARE IMAGE" << endl;
		}
	
	};


//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	SquareImage img;
	Image &image_ref = img;
	image_ref.x=0;
	return 0;
}
//------------------------------------------------------------
