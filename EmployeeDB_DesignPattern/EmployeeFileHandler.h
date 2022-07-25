#pragma once
#include "pch.h"
#include "EmployeeHandler.h"
#include <fstream>


class EmployeeFileHandler : public EmployeeHandler
{
private:
	FILE* filee;
	string filename;
public:
	//Default Constructor
	EmployeeFileHandler()
	{
	}

	EmployeeFileHandler(string f)
		:filename(f)
	{
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
	map<int, employee*> SearchData(map<int, employee*>& m1, map<int, employee*>& m2, int i);

};

