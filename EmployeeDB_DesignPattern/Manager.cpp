#include "pch.h"
#include "Manager.h"

void Manager::setnfprjt(int n)
{
	noofprjt = n;
}

void Manager::setyexp(int ye)
{
	yofexp = ye;
}


int Manager::getnfprjt()
{
	return noofprjt;
}

int Manager::getyexp()
{
	return yofexp;
}
