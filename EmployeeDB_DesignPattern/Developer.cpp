#include "pch.h"
#include "Developer.h"

void developer::setplang(string plang)
{
	prog_lang = plang;
}

void developer::settname(string tname)
{
	team_name = tname;
}

string developer::getplang()
{
	return prog_lang;
}

string developer::gettname()
{
	return team_name;
}




