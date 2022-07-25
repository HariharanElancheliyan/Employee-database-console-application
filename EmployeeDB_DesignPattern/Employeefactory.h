#pragma once
#include "employee.h"
#include "Developer.h"
#include "qa.h"
#include "Manager.h"

class Employeefactory
{
public:
	static employee* emp_factory(int num);
};

