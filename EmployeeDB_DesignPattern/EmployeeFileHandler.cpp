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
    for (it = m_emp.begin(); it != m_emp.end(); it++)
    {
        employee* e_obj = it->second;
        {
            cout << "Employee ID         : " << e_obj->getempid() << endl;
            cout << "Employee Name       : " << e_obj->getempname() << endl;
            cout << "Employee Age        : " << e_obj->getempage() << endl;
            cout << "Employee Department : " << e_obj->getempdept() << endl;
            cout << "Employee Salary     : " << e_obj->getempsalary() << endl;
            cout << "-----Department Level Information------" << endl;
            if (e_obj->getemptype() == 1)
            {
                developer* dobj = dynamic_cast<developer*>(e_obj);
                if (dobj == nullptr)
                {
                    cout << "NULL" << endl;
                }
                else
                {
                    cout << "Employee Prog Lang  : " << dobj->getplang() << endl;
                    cout << "Employee Team Name  : " << dobj->gettname() << endl;
                    cout << "________________________________________________" << endl << endl;
                }
            }
            else if (e_obj->getemptype() == 2)
            {
                qa* qaobj = dynamic_cast<qa*>(e_obj);
                if (qaobj == nullptr)
                {
                    cout << "NULL" << endl;
                }
                else
                {
                    cout << "Assigned Project    : " << qaobj->getassprjt() << endl;
                    cout << "Employee Skill/Tool : " << qaobj->gettools() << endl;
                    cout << "________________________________________________" << endl << endl;
                }
            }
            else if (e_obj->getemptype() == 3)
            {
                Manager* ma_obj = dynamic_cast<Manager*>(e_obj);
                if (ma_obj == nullptr)
                {
                    cout << "NULL" << endl;
                }
                else
                {
                    cout << "No of Project       : " << ma_obj->getnfprjt() << endl;
                    cout << "Years of Experience : " << ma_obj->getyexp() << endl;
                    cout << "________________________________________________" << endl << endl;
                }
            }
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
    ofstream file;
    size_t dbsize = m_emp.size();
    map<int, employee*> ::iterator it;
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

map<int,employee*> EmployeeFileHandler::SearchData(map<int, employee*>& m1, map<int, employee*>& m2,int i)
{
    map<int, employee*> final_map;
    if (i == 1) //set intersection operation - (and)
    {
        set_intersection(m1.begin(), m1.end(), m2.begin(),m2.end(), inserter(final_map, final_map.begin()));
    }
    else if (i == 2) //set union operation - (or)
    {
        set_union(begin(m1), end(m1), begin(m2), end(m2), inserter(final_map, end(final_map)));
    }
    else if (i == 3) //Not operation
    {
        set_difference(begin(m1), end(m1), begin(m2), end(m2), inserter(final_map, end(final_map)));
    }
   
    return final_map;
}


