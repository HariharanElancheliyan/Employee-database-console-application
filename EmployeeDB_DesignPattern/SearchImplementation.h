#include "pch.h"
#include "SearchInterface.h"

class SearchImplementation : public SearchInterface
{	
public:

	//Default Constructor
	SearchImplementation()
	{
		
	}

	//Default Destructor
	~ SearchImplementation()
	{

	}

	map<int, employee*> searchByInt(int value, E_details e, I_operation i_o, map<int, employee*>& m_emp);
	map<int, employee*> searchByString(string value, E_details e, S_operation s_o, map<int, employee*>& m_emp);

	bool ends_With(string const& str, string const& suffix);

};

