#pragma once
#include "pch.h"
#include "employee.h"


class Manager : public employee
{
private:
	int noofprjt;
	int yofexp;
public:
	Manager()
	{

	}
	Manager(int id, string name, int age, string dept, int salary, int nfprjt, int yexp, int etype)
		:employee(id, name, age, dept, salary, etype), noofprjt(nfprjt), yofexp(yexp)
	{

	}
	~Manager()
	{

	}

	//Setters
	void setnfprjt(int nprjt);
	void setyexp(int ye);

	//Getters
	int getnfprjt();
	int getyexp();

};

