#include "cube.h"

cube::cube()
{
}

cube::~cube()
{
}

int cube::GetRidge(int edge)
{
	return beam = edge;
}

int cube::Proportion()
{
	return beam * beam * 6;
}

int cube::Cubature()
{
	return beam * beam * beam;
}