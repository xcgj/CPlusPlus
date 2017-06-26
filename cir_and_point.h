#pragma once

class point;//类的前置声明

class cir
{
public:
	cir();
	~cir();
	void GetPXYR(double x, double y, double r);
	double C_P_comp(point &pt);
	void testfunc();
private:
	double centre_x;
	double centre_y;
	double cir_r;
};

class point
{
public:
	point();
	~point();
	double point_x;
	double point_y;
private:
};