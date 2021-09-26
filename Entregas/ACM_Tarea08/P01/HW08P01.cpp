/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW08P01
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>

//------------------------------------------------------------
int F00( double a, double b, double c ){
	return (a==b && b==c);
}


//------------------------------------------------------------
int F01( double a, double b, double c ){
	return (a==b && b==c);
}

//------------------------------------------------------------
int F02( double a, double b, double c ){
	return (a==b && b==c);
}

//------------------------------------------------------------
int F03( double a, double b, double c ){
	return (a==b && b==c);
}

//------------------------------------------------------------
int F04( double a, double b, double c ){
	return (a==b && b==c);
}

//------------------------------------------------------------
int F05( double a, double b, double c ){
	return (a==b && b==c);
}

//------------------------------------------------------------
int F06( double a, double b, double c ){
	return ((int)a+(int)b+(int)c);
}

//------------------------------------------------------------
int F07( double a, double b, double c ){
	return (a==b && b==c);
}

//------------------------------------------------------------
int F08( double a, double b, double c ){
	return (a==b && b==c);
}

//------------------------------------------------------------
int F09( double a, double b, double c ){
	return (a==b && b==c);
}

//------------------------------------------------------------
int F10( double a, double b, double c ){
	return (a==b && b==c);
}

//------------------------------------------------------------
int F11( double a, double b, double c ){
	return (a==b && b==c);
}

//------------------------------------------------------------
int F12( double a, double b, double c ){
	return (a==b && b==c);
}

//------------------------------------------------------------
int F13( double a, double b, double c ){
	return (a==b && b==c);
}

//------------------------------------------------------------
int F14( double a, double b, double c ){
	return (a==b && b==c);
}

//------------------------------------------------------------
int F15( double a, double b, double c ){
	return (a==b && b==c);
}

//------------------------------------------------------------
int F16( double a, double b, double c ){
	return (a==b && b==c);
}

//------------------------------------------------------------
int F17( double a, double b, double c ){
	return (a==b && b==c);
}

//------------------------------------------------------------
int F18( double a, double b, double c ){
	return (a==b && b==c);
}

//------------------------------------------------------------
int F19( double a, double b, double c ){
	return (a==b && b==c);
}



//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	int (* F[20])( double a, double b, double c) =
												{ F00, F01, F02, F03, F04, F05, F06, F07, F08, F09,  
												  F10, F11, F12, F13, F14, F15, F16, F17, F18, F19 };
	
	int pintar = (*F[ 5 ])(1,2,3);
	delete F;
	std::cout << pintar << std::endl;
	return 0;
}
//------------------------------------------------------------
