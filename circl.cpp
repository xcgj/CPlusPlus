#include "circl.h"

int circl::SetArris(int edge)
{
	return arris = edge;
}

int circl::GetArris()
{
	return arris;
}

bool circl::CompareArris(circl &an)
{
	if (arris == an.arris)
		return 1;
	else
		return 0;
}

circl::circl()
{

}

circl::~circl()
{

}