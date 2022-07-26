#pragma once
#include "employee.h"

class developer : public employee
{
private:
	string prog_lang;
	string team_name;
	
public:
	//Default constructor
	developer()
	{

	}

	//Parameterized constructor
	developer(int id, string name, int age, string dept, int salary,string plang,string tname,int etype)
		:employee(id,name,age,dept,salary, etype),prog_lang(plang),team_name(tname)
	{

	}

	//Default destructor
	~developer()
	{
		
	}

	//setters
	void setplang(string plang);
	void settname(string tname);

	//getters
	string getplang();
	string gettname();

};
