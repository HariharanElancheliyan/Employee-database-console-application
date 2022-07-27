#include "pch.h"
#include "SearchImplementation.h"

bool SearchImplementation::ends_With(string const& str, string const& suffix)
{
    if (str.length() < suffix.length())
    {
        return false;
    }
    else
    {
        return str.rfind(suffix) == str.size() - suffix.size();
    }
}

map<int, employee*> SearchImplementation::searchByInt(int value, E_details e, I_operation i_o, map<int, employee*>& m_emp)
{
    map<int, employee*> temp_map;

    map<int, employee*> ::iterator it;
    switch (e)
    {
    case e_id:
        for (it = m_emp.begin(); it != m_emp.end(); it++)
        {
            employee* eobj = it->second;
            if (i_o == 0)
            {
                if (value < eobj->getempid())
                {
                    temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
            else if (i_o == 1)
            {
                if (value > eobj->getempid())
                {
                    temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
            else if (i_o == 2)
            {
                if (value == eobj->getempid())
                {
                    temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
            else if (i_o == 3)
            {
                if (value <= eobj->getempid())
                {
                    temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
            else if (i_o == 4)
            {
                if (value >= eobj->getempid())
                {
                    temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
        }
        break;

    case e_age:
        for (it = m_emp.begin(); it != m_emp.end(); it++)
        {
            employee* eobj = it->second;
            if (i_o == 0)
            {
                if (value < eobj->getempage())
                {
                    temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
            else if (i_o == 1)
            {
                if (value > eobj->getempage())
                {
                    temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
            else if (i_o == 2)
            {
                if (value == eobj->getempage())
                {
                    temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
            else if (i_o == 3)
            {
                if (value <= eobj->getempage())
                {
                    temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
            else if (i_o == 4)
            {
                if (value >= eobj->getempage())
                {
                    temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
        }
        break;

    case e_salary:
        for (it = m_emp.begin(); it != m_emp.end(); it++)
        {
            employee* eobj = it->second;
            if (i_o == 0)
            {
                if (value < eobj->getempsalary())
                {
                    temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
            else if (i_o == 1)
            {
                if (value > eobj->getempsalary())
                {
                    temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
            else if (i_o == 2)
            {
                if (value == eobj->getempsalary())
                {
                    temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
            else if (i_o == 3)
            {
                if (value <= eobj->getempsalary())
                {
                    temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
            else if (i_o == 4)
            {
                if (value >= eobj->getempsalary())
                {
                    temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
        }
        break;
    }
    return temp_map;
}

map<int, employee*> SearchImplementation::searchByString(string value, E_details e, S_operation s_o, map<int, employee*>& m_emp)
{
    map<int, employee*> s_temp_map;

    map<int, employee*> ::iterator it;
    switch (e)
    {
    case e_name:
        for (it = m_emp.begin(); it != m_emp.end(); it++)
        {
            employee* eobj = it->second;
            string str = eobj->getempname();
            if (s_o == startswith)
            {
                if (str.rfind(value, 0) == 0)
                {
                    s_temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
            else if (s_o == endswith)
            {
                if (ends_With(str, value))
                {
                    s_temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
            else if (s_o == containss)
            {
                if (str.find(value) != string::npos)
                {
                    s_temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
        }
        break;
    case e_dept:
        for (it = m_emp.begin(); it != m_emp.end(); it++)
        {
            employee* eobj = it->second;
            string str = eobj->getempdept();
            if (s_o == startswith)
            {
                if (str.rfind(value, 0) == 0)
                {
                    s_temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
            else if (s_o == endswith)
            {
                if (ends_With(str, value))
                {
                    s_temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
            else if (s_o == containss)
            {
                if (str.find(value) != string::npos)
                {
                    s_temp_map.insert(pair<int, employee*>(it->second->getempid(), it->second));
                }
            }
        }
        break;
    }
    return s_temp_map;
}

