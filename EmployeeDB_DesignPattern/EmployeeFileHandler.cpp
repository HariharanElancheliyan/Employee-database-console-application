#include "pch.h"
#include "EmployeeFileHandler.h"
#include "Developer.h"
#include "qa.h"
#include "employee.h"
#include <algorithm>

bool EmployeeFileHandler::addData(int i, sdev d)
{
    developer* dev_obj = dynamic_cast<developer*>(Employeefactory::emp_factory(i));
    if (dev_obj == nullptr)
    {
        cout << "Null Pointer" << endl;
        return false;
    }
    else
    {
        dev_obj->setempid(d.id);
        dev_obj->setempname(d.name);
        dev_obj->setempage(d.age);
        dev_obj->setempdept(d.dept);
        dev_obj->setempsalary(d.salary);
        dev_obj->setplang(d.plang);
        dev_obj->settname(d.team);
        dev_obj->setemptype(1);
        m_emp.insert(pair<int, employee*>(d.id, dev_obj));
        return true;
    }
}

bool EmployeeFileHandler::addData(int i, sqa sq)
{
    qa* qa_obj = dynamic_cast<qa*>(Employeefactory::emp_factory(i));
    if (qa_obj == nullptr)
    {
        cout << "Null Pointer" << endl;
        return false;
    }
    else
    {
        qa_obj->setempid(sq.id);
        qa_obj->setempname(sq.name);
        qa_obj->setempage(sq.age);
        qa_obj->setempdept(sq.dept);
        qa_obj->setempsalary(sq.salary);
        qa_obj->setassprjt(sq.assprjt);
        qa_obj->settools(sq.tectool);
        qa_obj->setemptype(2);
        m_emp.insert(pair<int, employee*>(sq.id, qa_obj));
        return true;
    }
}

bool EmployeeFileHandler::addData(int i, sm smm)
{
    Manager* m_obj = dynamic_cast<Manager*>(Employeefactory::emp_factory(i));
    if (m_obj == nullptr)
    {
        cout << "Null Pointer" << endl;
        return false;
    }
    else
    {
        m_obj->setempid(smm.id);
        m_obj->setempname(smm.name);
        m_obj->setempage(smm.age);
        m_obj->setempdept(smm.dept);
        m_obj->setempsalary(smm.salary);
        m_obj->setnfprjt(smm.noofprjt);
        m_obj->setyexp(smm.yofexp);
        m_obj->setemptype(3);
        m_emp.insert(pair<int, employee*>(smm.id, m_obj));
        return true;
    }
}

bool EmployeeFileHandler::ListData()
{
    map<int, employee*> ::iterator it;
    size_t itc = m_emp.size();
    if (itc == 0)
    {
        cout << "No records found" << endl;
        return false;
    }
    cout << "ID \tName \t\tAge \tDepartment \t\tSalary\tProg.Language\tTeam Name   Assigned Project   Technologies/Tools   No.of Project  Years of Experience" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    
    for (it = m_emp.begin(); it != m_emp.end(); it++)
    {
        cout << it->second->getempid() << '\t' << it->second->getempname() << '\t' << '\t' << it->second->getempage() << '\t' << it->second->getempdept();
        employee* eobj = it->second;
        if (eobj->getempdept() == "Developer")
        {
            developer* devobj = dynamic_cast<developer*>(eobj);
            cout << "\t\t" << devobj->getempsalary() <<'\t' << devobj->getplang() << "\t\t" << devobj->gettname() << endl;
        }
        else if (eobj->getempdept() == "Quality_Assuarance")
        {
            qa* qaobj = dynamic_cast<qa*>(eobj);
            cout << '\t' << qaobj->getempsalary() <<'\t' << "-" << "\t\t" << '-' << "\t\t" << qaobj->getassprjt() << "\t\t" << qaobj->gettools() << endl;
        }
        else if (eobj->getempdept() == "Manager")
        {
            Manager* maobj = dynamic_cast<Manager*>(eobj);
            cout << "\t\t\t" << maobj->getempsalary() << '\t' << "-" << "\t\t" << '-' << "                                                      \0" << maobj->getnfprjt() << "             \0" << maobj->getyexp() << endl;
        }
    }
    return true;
}

bool EmployeeFileHandler::DeleteData(int id)
{
    auto it = m_emp.find(id);
    if (it == m_emp.end())
    {
        return false;
    }
    else
    {
        m_emp.erase(id);
        return true;
    }
}

void EmployeeFileHandler::saveData()
{
   
    size_t dbsize = m_emp.size();
    map<int, employee*> ::iterator it;

    ofstream file;
    file.open(filename, ofstream::out);
    if (dbsize == 0)
    {
        cout << "No records found" << endl;
    }
    else
    {
        for (it = m_emp.begin(); it != m_emp.end(); it++)
        {
            employee* e_obj = it->second;
            if (e_obj->getemptype() == 1)
            {
                developer* dobj = dynamic_cast<developer*>(e_obj);
                file << (*it).second->getempid() << " " << (*it).second->getempname() << " " << (*it).second->getempage() << " " << (*it).second->getempdept() << " " << (*it).second->getempsalary() << " " << dobj->getplang() << " " << dobj->gettname() << " " << dobj->getemptype() << endl;
            }
            else if (e_obj->getemptype() == 2)
            {
                qa* qaobj = dynamic_cast<qa*>(e_obj);
                file << (*it).second->getempid() << " " << (*it).second->getempname() << " " << (*it).second->getempage() << " " << (*it).second->getempdept() << " " << (*it).second->getempsalary() << " " << qaobj->getassprjt() << " " << qaobj->gettools() << " " << qaobj->getemptype() << endl;
            }
            else if (e_obj->getemptype() == 3)
            {
                Manager* maobj = dynamic_cast<Manager*>(e_obj);
                file << (*it).second->getempid() << " " << (*it).second->getempname() << " " << (*it).second->getempage() << " " << (*it).second->getempdept() << " " << (*it).second->getempsalary() << " " << maobj->getnfprjt() << " " << maobj->getyexp() << " " << maobj->getemptype() << endl;
            }
        }
    }
    file.close();
    cout << " Employee Details Saved Sucessfully !" << endl;

}

void EmployeeFileHandler::Loadfromfile(string s)
{
    int emp_id;
    char emp_name[30]{};
    int emp_age;
    char emp_dept[30]{};
    int emp_salary;
    char val1[30]{};
    char val2[30]{};
    int emptype;
    char file_name[20];

    strcpy(file_name, s.c_str());
    filee = fopen(file_name, "r");
    while (fscanf(filee, "%d %s %d %s %d %s %s %d", &emp_id, &emp_name[0], &emp_age, &emp_dept[0], &emp_salary, &val1[0], &val2[0], &emptype) != EOF)
    {
        if (emptype == 1)
        {
            sdev l_sd;
            l_sd.id = emp_id;
            l_sd.name = emp_name;
            l_sd.age = emp_age;
            l_sd.dept = emp_dept;
            l_sd.salary = emp_salary;
            l_sd.plang = val1;
            l_sd.team = val2;
            addData(emptype, l_sd);
        }
        else if (emptype == 2)
        {
            sqa l_sqa;
            l_sqa.id = emp_id;
            l_sqa.name = emp_name;
            l_sqa.age = emp_age;
            l_sqa.dept = emp_dept;
            l_sqa.salary = emp_salary;
            l_sqa.assprjt = val1;
            l_sqa.tectool = val2;
            addData(emptype, l_sqa);
        }
        else if (emptype == 3)
        {
            sm l_sm;
            l_sm.id = emp_id;
            l_sm.name = emp_name;
            l_sm.age = emp_age;
            l_sm.dept = emp_dept;
            l_sm.salary = emp_salary;
            l_sm.noofprjt = stoi(val1);
            l_sm.yofexp = stoi(val2);
            addData(emptype, l_sm);
        }
    }
    fclose(filee);
    cout << "Data Loaded Successfully" << endl;
}

map<int, employee*> EmployeeFileHandler::SearchData(int v, E_details ed, I_operation i_op, map<int, employee*>& _map)
{  
   return (s_i->searchByInt(v, ed, i_op, _map));
}

map<int, employee*> EmployeeFileHandler::SearchData(string v, E_details ed, S_operation s_op, map<int, employee*>& _map)
{
    return (s_i->searchByString(v, ed, s_op, _map));
}

map<int,employee*> EmployeeFileHandler::PerformSetOperation(map<int, employee*>& m1, map<int, employee*>& m2, Set_op s)
{
    map<int, employee*> final_map;
    if (s == _and) //set intersection operation - (and)
    {
        set_intersection(m1.begin(), m1.end(), m2.begin(),m2.end(), inserter(final_map, final_map.begin()));
    }
    else if (s == _or) //set union operation - (or)
    {
        set_union(begin(m1), end(m1), begin(m2), end(m2), inserter(final_map, end(final_map)));
    }
    else if (s == _not) //set  difference Not operation
    {
        set_difference(begin(m_emp), end(m_emp), begin(m1), end(m1), inserter(final_map, end(final_map)));
    }
   
    return final_map;
}

