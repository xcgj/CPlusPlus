#include "cir_and_point.h"
#include <math.h>
//#include "iostream"
//using std::cout;
//using std::endl;

cir::cir()
{
}

cir::~cir()
{
}

void cir::GetPXYR(double x, double y, double r)
{
	centre_x = x;
	centre_y = y;
	cir_r = r;
}

void cir::testfunc()
{
	//cout << "x " << centre_x << ", y " << centre_y << endl;
}

double cir::C_P_comp(point &pt)
{
	double res = pow(cir_r, 2) - pow(pt.point_x - centre_x, 2) - pow(pt.point_y - centre_y, 2);
	return res;
}


 
point::point()
{
}

point::~point()
{
}