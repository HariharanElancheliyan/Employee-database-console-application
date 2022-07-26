#include "pch.h"
#include "employee.h"


enum E_details {e_id,e_name,e_age,e_dept,e_salary};
enum I_operation {grter , lesser , equalto, grthanequal, lessthaequal };
enum S_operation {startswith,endswith,containss};


class SearchInterface 
{
public:
	SearchInterface()
	{

	}

	virtual ~SearchInterface()
	{

	}

	virtual map<int, employee*> searchByInt(int value, E_details e, I_operation i_o, map<int, employee*>& m_emp) = 0;
	virtual map<int, employee*> searchByString(string value, E_details e, S_operation s_o,  map<int, employee*>& m_emp) = 0;
};

