/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW15P03
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
const double PI = M_PI;

//------------------------------------------------------------
class Shape 
	{
	public:
		virtual ~Shape() { };
		virtual Shape* clone() const = 0;
		virtual Shape* create() const = 0;
		virtual double getArea() const = 0;
		virtual double getPerimeter() const = 0;
		virtual void print() const = 0;
	};


//------------------------------------------------------------
class Circle : public Shape 
	{
	private:
		double x;
		double y;
		double r;
	public:
		Circle()
			{	
			x=0;	
			y=0;	
			r=0;	
			}
		Circle( const Circle &c ): Shape(c)
			{
			x=c.x;	
			y=c.y;	
			r=c.r;
			}
		Circle( const double &x, const double &y, const double &r )
			{
			this->x=x;	
			this->y=y; 
			this->r=r;
			}
		Circle* clone() const;
		Circle* create() const;
		double getArea() const
			{	
			return PI*r*r;	
			}
		double getPerimeter() const
			{	
			return 2.0*PI*r;	
			}
		void print() const
			{	
			cout<< "Circle: " << "Center: (" << x<< "," << y << ") Radius: "<< r << endl;	
			}
	};


//------------------------------------------------------------
class Square : public Shape 
	{
	private:
		double xmin;
		double xmax;
		double ymin;
		double ymax;
	public:
		Square()
			{	
			xmin=0;	
			xmax=0;	
			ymin=0;	
			ymax=0;	
			}
		Square(const Square &s): Shape(s)
			{
			xmin=s.xmin;	
			xmax=s.xmax;	
			ymin=s.ymin;	
			ymax=s.ymax;
			}
		Square(const double &xi,const double &yi,const double &xf, const double &yf)
			{
			xmin=xi;	
			xmax=xf;	
			ymin=yi;	
			ymax=yf;
			}
		Square* clone() const;
		Square* create() const;
		double getArea() const
			{	
			return (xmax-xmin)*(xmax-xmin);	
			}
		double getPerimeter() const
			{	
			return 4.0*fabs(xmax-xmin);	
			}
		void print() const
			{	
			cout<<"Square: "<<"(("<< xmin << "," << ymin <<"),("<< xmax << ","<< ymax <<"))"<<endl;	}
	};


//------------------------------------------------------------
Circle* Circle::clone() const{
	return new Circle(*this);
	}


//------------------------------------------------------------
Circle* Circle::create() const{
	return new Circle();
	}


//------------------------------------------------------------
Square* Square::clone() const{
	return new Square(*this);
	}


//------------------------------------------------------------
Square* Square::create() const{
	return new Square();
	}


//------------------------------------------------------------
int main (int argc, char * const argv[]){
	Shape *Circulo = new Circle(-1.0,1.0,3.0);
	Shape *Cuadrado = new Square(-1.0,-1.0,10.0,10.0);
	Shape *Figura1;
	Shape *Figura2;
	Shape *Figura3;
	Shape *Figura4;

	Circulo->print();
	Cuadrado->print();

	Figura1 = Circulo->clone();
	Figura1->print();

	Figura2 = Cuadrado->clone();
	Figura2->print();
	
	Figura3 = Circulo->create();
	Figura3->print();
	
	Figura4 = Cuadrado->create();
	Figura4->print();

	delete Circulo;
	delete Cuadrado;
	delete Figura1;
	delete Figura2;
	delete Figura3;
	delete Figura4;
	return 0;
	}
//------------------------------------------------------------
