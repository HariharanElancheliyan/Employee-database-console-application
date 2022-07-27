#pragma once
#include "pch.h"
#include "EmployeeHandler.h"
#include <fstream>
#include <mutex>


class EmployeeFileHandler : public EmployeeHandler
{
private:
	FILE* filee;
	string filename;

public:
	//Default Constructor
	EmployeeFileHandler():EmployeeHandler()
	{

	}

	EmployeeFileHandler(string f):EmployeeHandler()
	{
		filename = f;
		Loadfromfile(filename);
	}

	//Default Destructor
	~EmployeeFileHandler()
	{
		if (filee != nullptr)
		{
			delete filee;
		}
	}

	bool addData(int i, sdev d);
	bool addData(int i, sqa sq);
	bool addData(int i, sm smm);

	bool ListData();

	bool DeleteData(int id);

	void saveData();

	void Loadfromfile(string s);

	map<int, employee*> SearchData(int v, E_details ed, I_operation i_op, map<int, employee*>& _map);
	map<int, employee*> SearchData(string v, E_details ed, S_operation s_op, map<int, employee*>& _map);

	map<int, employee*> PerformSetOperation(map<int, employee*>& m1, map<int, employee*>& m2, Set_op s); //change as enum not int


};

