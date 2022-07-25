#pragma once
#include "pch.h"
#include "employee.h"
#include "Developer.h"
#include "qa.h"
#include "Employeefactory.h"

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

public:
	//Defualt constructor
	EmployeeHandler()
	{

	}

	//Virtual Destructor
	virtual ~EmployeeHandler()
	{
		map<int, employee*>::iterator it;
		if (it != m_emp.end())
		{
			delete (it->second);
		} 
	}

	virtual bool addData(int i, sdev sd) = 0;
	virtual bool addData(int i, sqa sq) = 0;
	virtual bool addData(int i, sm smm) = 0;
	virtual bool ListData() = 0;
	virtual bool DeleteData(int id) = 0;
	virtual void saveData() = 0;
	virtual void Loadfromfile(string s) = 0;
	virtual map<int, employee*> SearchData(map<int, employee*>& m1, map<int, employee*>& m2,int i) = 0;

	map<int, employee*> mapData();
};

