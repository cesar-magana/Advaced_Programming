/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I PROYECTO HOUGH
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#define FOR(i, n) for( int i = 0, _n = (n); i < _n; i++ )

using namespace std;

//---------------------------------------------------------------	


//---------------------------------------------------------------	
//Clase Image.
class Image
	{
	public:
		int width;
		int height;
		double **data;

		double max_grey_value;
		string filetype;
		
		Image ();
		~Image();
		bool pgm_read_header(ifstream &in);
		bool pgm_read_data(ifstream &in);
		bool pgm_read(char* filename);
		bool pgm_write_header();
		bool pgm_write_data();
		bool pgm_write();
		double get_data(int i, int j);
		bool init(Image &output);
		bool dxb(Image &output);
		bool dyb(Image &output);
		bool dxf(Image &output);
		bool dyf(Image &output);
		bool dxc(Image &output);
		bool dyc(Image &output);
		bool norma_gradiente(Image &output);
		bool hough_transform(Image &output);
	};



//---------------------------------------------------------------	
Image::Image ( )
	{
	width=0;
	height=0;
	max_grey_value=0;
	}


//---------------------------------------------------------------		
Image::~Image()
	{
	if (width!=0)
		{
		FOR (k,width)
				{
				delete data[k];
				}
		delete data;
		}
	}					


//---------------------------------------------------------------
bool Image::init(Image &output)
	{
	output.filetype=filetype;
	output.width=width;
	output.height=height;
	output.max_grey_value=max_grey_value;
	output.data=new double*[width];
	FOR(i, width)
		output.data[i] = new double[height];
	return true;	
	}					


//---------------------------------------------------------------
//Derivada en x hacia atrás
bool Image::dxb(Image &output)
	{
	this->init(output);
	FOR (i,width)
		{
		for (int j = 1 ; j < height ; j++)
			output.data[i][j] = data[i][j] - data[i][j-1] ;
		output.data[i][0] = output.data[i][1] ;
		}
	return true;	
	}					

//---------------------------------------------------------------
//Derivada en y hacia atrás
bool Image::dyb(Image &output)
	{
	this->init(output);
	FOR (j,height)
		{
		for (int i = 1 ; i < width ; i++)
			output.data[i][j] = data[i][j] - data[i-1][j] ;
		output.data[0][j] = output.data[1][j] ;
		}
	return true;	
	}					


//---------------------------------------------------------------
//Derivada en x hacia adelante
bool Image::dxf(Image &output)
	{
	this->init(output);
	FOR (i,width)
		{
		FOR (j,height-1)
		 output.data[i][j] = data[i][j+1] - data[i][j] ;
		output.data[i][height-1] = output.data[i][height-2] ;
		}
	return true;
	}

//---------------------------------------------------------------
//Derivada en y hacia adelante
bool Image::dyf(Image &output)
	{
	this->init(output);
	FOR (j,height)
		{
		FOR (i,width-1)
		 output.data[i+1][j] = data[i+1][j] - data[i][j] ;
		output.data[width-1][j] = output.data[width-2][j] ;
		}
	return true;
	}

//---------------------------------------------------------------
//Derivada centrada con respecto a x
bool Image::dxc(Image &output)
	{
	this->init(output);
	FOR (i,width)
		{
		for (int j = 1 ; j < height-1 ; j++)
		 output.data[i][j] = data[i][j+1] - data[i][j-1];
		output.data[i][height-1] = output.data[i][height-2];
		output.data[i][0] = output.data[i][1];
		}
	return true;
	}

//---------------------------------------------------------------
//Derivada centrada con respecto a x
bool Image::dyc(Image &output)
	{
	this->init(output);
	FOR (j,height)
		{
		for (int i = 1 ; i < width-1 ; i++)
		 output.data[i][j] = data[i+1][j] - data[i-1][j];
		output.data[width-1][j] = output.data[width-2][j];
		output.data[0][j] = output.data[1][j];
		}
	return true;
	}


//---------------------------------------------------------------
//Norma del gradiente
bool Image::norma_gradiente(Image &output)
	{
	this->init(output);
	double **dx;
	dx=new double*[width];
	FOR(i, width)
		dx[i] = new double[height];
	double **dy;
	dy=new double*[width];
	FOR(i, width)
		dy[i] = new double[height];

	//Derivada centrada respecto a x
	FOR (i,width)
		{
		for (int j = 1 ; j < height-1 ; j++)
		 dx[i][j] = data[i][j+1] - data[i][j-1];
		dx[i][height-1] = dx[i][height-2];
		dx[i][0] = dx[i][1];
		}
	//Derivada centrada respecto a y
	FOR (j,height)
		{
		for (int i = 1 ; i < width-1 ; i++)
		 dy[i][j] = data[i+1][j] - data[i-1][j];
		dy[width-1][j] = dy[width-2][j];
		dy[0][j] = dy[1][j];
		}
	
	FOR(i, width)
		FOR(j, height)
			output.data[i][j]=sqrt(dx[i][j]*dx[i][j]+dy[i][j]*dy[i][j]);

	FOR (k,width)
			{
			delete dx[k];
			delete dy[k];
			}
	delete dx;
	delete dy;
	
	return true;
	}


//---------------------------------------------------------------
bool Image::pgm_read_header(ifstream &in)
	{
	in >> filetype;
	in >> height >> width;
	in >> max_grey_value;
	return true;
	}


//---------------------------------------------------------------
bool Image::pgm_read_data(ifstream &in)
	{
	data=new double*[width];
	FOR(i, width)
		data[i] = new double[height];
	FOR(i, width)
		FOR(j, height)
			in >> data[i][j];
	return true;
	}


//---------------------------------------------------------------
bool Image::pgm_read(char* filename)
	{
	ifstream in(filename);
	if ( !in )
		{
		cout << "pgm_read error" << endl;
		return false;
		}
	if ( !pgm_read_header(in) )
		{
		cout << "pgm_read_header error" << endl; 
		return false;
		}
	if ( !pgm_read_data(in) )
		{
		cout << "pgm_read_data error" << endl;
		return false; 
		}
	in.close();
	return true;
	}


//---------------------------------------------------------------			
bool Image::pgm_write_header()
	{
	cout << filetype << endl;
	//cout << "#Comentado generado mi programa" << endl;
	cout << height << endl;
	cout << width << endl;
	cout << max_grey_value << endl;
	return true;
	}


//---------------------------------------------------------------			
bool Image::pgm_write_data()
	{
	FOR (i,width)
		{
		FOR (j,height)
			cout << data[i][j] << " ";
		cout << endl;
		}
	return true;
	}



//---------------------------------------------------------------			
bool Image::pgm_write()
	{
	pgm_write_header();
	pgm_write_data();
	return true;
	}


//---------------------------------------------------------------	
double Image::get_data(int i, int j)
	{
	return data[i][j];
	}


//---------------------------------------------------------------	
bool Image::hough_transform (Image &z)
	{
	//this->init(z);
	int center_x, center_y, r, omega, i, j, rmax;
	int t=70;
	double conv;
	//double sin(), cos(), sqrt();

	//*error_code = 0;
	conv = 3.1415926535/180.0;
	center_x = width/2;	
	center_y = height/2;
	rmax =  (int)(sqrt((double)(width*width+height*height))/2.0);

	//z = newimage (180, 2*rmax+1, error_code);
	z.filetype="P2";
	z.height=180;
	z.width=2*rmax+1;
	z.max_grey_value=max_grey_value;
	z.data=new double*[z.width];
	FOR(i, z.width)
		z.data[i] = new double[z.height];

	//if (*error_code) return;

	for (r = 0; r < 2 * rmax+1; r++)
	   for (omega = 0; omega < 180; omega++)
	   	z.data[r][omega] = 0;

	for (j = 0; j < height; j++)
	   for (i = 0; i < width; i++)
		if (data[i][j] <= t)
		   for (omega = 0; omega < 180; ++omega) {
		   	r = (i - center_y) * sin((double)(omega*conv)) 
			   + (j - center_x) * cos((double)(omega*conv));
			if (r>0)r++;
		   	z.data[omega][rmax+r] += 1;
		   }
	//writeimage (z, "hough.alpha", error_code);
	return true;
	}




//---------------------------------------------------------------
int main (int argc, char * const argv[]) {
	Image img;
	if ( !img.pgm_read(argv[1]) )
		{
		cout << "No fue posible abrir el archivo" << endl;
		return -1;
		}
		
	Image grad;
	img.norma_gradiente(grad);
	Image h;
	grad.hough_transform(h);
	h.pgm_write();
	return 0;
}
//---------------------------------------------------------------