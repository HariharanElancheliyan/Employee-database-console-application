#pragma once
#include "employee.h"
 class qa : public employee
{
private:
	string assprjt;
	string tools;
public:
	//Default constructor
	qa()
	{

	}

	//Parameterized Constructor
	qa(int id, string name, int age, string dept, int salary, string apjt, string tls,int etype)
		:employee(id, name, age, dept, salary,etype), assprjt(apjt), tools(tls)
	{

	}
	~qa()
	{
		
	}

	//setters
	void setassprjt(string a);
	void settools(string t);
	
	//getters
	string getassprjt();
	string gettools();
};

