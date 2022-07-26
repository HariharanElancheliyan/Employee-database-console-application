#include "pch.h"
#include "employee.h"

void employee::setempid(int id)
{
	emp_id = id;
}

void employee::setempname(string name)
{
	emp_name = name;
}

void employee::setempage(int age)
{
	emp_age = age;
}

void employee::setempdept(string dept)
{
	emp_dept = dept;
}

void employee::setempsalary(int salary)
{
	emp_salary = salary;
}

void employee::setemptype(int t)
{
	empType = t;
}

int employee::getempid()
{
	return emp_id;
}

string employee::getempname()
{
	return emp_name;
}

int employee::getempage()
{
	return emp_age;
}

string employee::getempdept()
{
	return emp_dept;
}

double employee::getempsalary()
{
	return emp_salary;
}

int employee::getemptype()
{
	return empType;
}


