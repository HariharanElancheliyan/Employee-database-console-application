#pragma once
#include "pch.h"
#include "employee.h"
#include "Developer.h"
#include "qa.h"
#include "Employeefactory.h"
#include "SearchImplementation.h"

enum Set_op { _and, _or, _not };

struct sdev
{
	int id;
	string name;
	int age;
	string dept;
	int salary;
	string plang;
	string team;
};

struct sqa
{
	int id;
	string name;
	int age;
	string dept;
	int salary;
	string assprjt;
	string tectool;
};

struct sm
{
	int id;
	string name;
	int age;
	string dept;
	int salary;
	int noofprjt;
	int yofexp;
};

class EmployeeHandler
{
protected:
	map<int, employee*> m_emp;
	SearchImplementation* s_i;
	
	//searchimplemntation * 

public:
	//Defualt constructor
	EmployeeHandler()
	{
		s_i = new SearchImplementation();
	}

	//Virtual Destructor
	virtual ~EmployeeHandler()
	{
		map<int, employee*>::iterator it;
		if (it != m_emp.end())
		{
			delete (it->second);
		} 

		if (s_i != nullptr)
		{
			delete s_i;
		}
		
	}

	virtual bool addData(int i, sdev sd) = 0;
	virtual bool addData(int i, sqa sq) = 0;
	virtual bool addData(int i, sm smm) = 0;

	virtual bool ListData() = 0;
	
	virtual bool DeleteData(int id) = 0;
	
	virtual void saveData() = 0;
	
	virtual void Loadfromfile(string s) = 0;
	
	virtual map<int, employee*> SearchData(int v, E_details ed, I_operation i_op, map<int, employee*>& _map) = 0;
	virtual map<int, employee*> SearchData(string v, E_details ed, S_operation s_op, map<int, employee*>& _map) = 0;

	virtual map<int, employee*> PerformSetOperation(map<int, employee*>& m1, map<int, employee*>& m2, Set_op s) = 0;

	map<int, employee*> mapData() { return m_emp; };

	//virtual bool Modify(string v , enum ) todo

};

