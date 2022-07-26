#pragma once
#include "pch.h"

using namespace std;

class employee
{
private:
	int emp_id;
	string emp_name;
	int emp_age;
	string emp_dept;
	int emp_salary;
	int empType;

public :
	
	//Default Constructor
	employee()
	{

	}

	//Parameterized Constructor
	employee(int id, string name, int age, string dept, int salary,int e)
		: emp_id(id), emp_name(name), emp_age(age), emp_dept(dept), emp_salary(salary),empType(e)
	{
	}

	//Default Destructor
	virtual ~ employee()
	{
		
	}

	//setters
	void setempid(int id);
	void setempname(string name);
	void setempage(int age);
	void setempdept(string dept);
	void setempsalary(int salary);
	void setemptype(int t);


	//getters
	int getempid();
	string getempname();
	int getempage();
	string getempdept();
	double getempsalary();
	int getemptype();

};