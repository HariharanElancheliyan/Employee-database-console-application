#include "pch.h"
#include "EmployeeFileHandler.h"
#include "EmployeeHandler.h"
#include "SearchImplementation.h"

void printMap(map<int, employee*>& p_map)
{
    size_t sizeofmap = p_map.size();
    if (sizeofmap == 0)
    {
        cout << " No Records match with your criteria" << endl;
    }
    for (auto it : p_map)
    {
        cout << "Employee ID         : " << it.second->getempid() << endl;
        cout << "Employee Name       : " << it.second->getempname() << endl;
        cout << "Employee Age        : " << it.second->getempage() << endl;
        cout << "Employee Department : " << it.second->getempdept() << endl;
        cout << "Employee Salary     : " << it.second->getempsalary() << endl;
        cout << "-----Department Level Information------" << endl;
        employee* e_obj = it.second;
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

int main()
{
    int ii = 0;
    int id;
    string name;
    int age;
    string dept;
    int emptype = 0;
    double salary;
    string val1;
    string val2;
    string v;
    char yn;
    char s_yn;
    char search_yn;
    int dp_ch = 0;
    bool save_flag = false;
    //map<int, employee*>printmap;
    map<int, employee*>thirdmap;
    map<int, employee*>Current_map;
    map<int, employee*>Prev_map;
    EmployeeHandler* emp_handler = new EmployeeFileHandler("employee_db.txt");
    do
    {
        int ch;
        cout << "\n1.Add Employee Data\n2.List all Employee Data\n3.Delete Employee Data\n4.Normal Search\n5.Save to a File\n6.Multiple Filter Search" << endl;
        cout << "Enter your Choice:" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter ID:" << endl;
            for (;;)
            {
                if (cin >> id)
                {
                    break;
                }
                else
                {
                    cout << "Enter Valid ID" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            cout << "Enter Name:" << endl;
            cin >> name;

            cout << "Enter Age:" << endl;
            for (;;)
            {
                if (cin >> age)
                {
                    break;
                }
                else
                {
                    cout << "Enter Valid Age" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            cout << "Select your Department" << endl;
            cout << "1.Developer\n2.Quality Assurance\n3.Manager" << endl;
            cout << "Enter 1 or 2 or 3:";
            for (;;)
            {
                if (cin >> dp_ch)
                {
                    break;
                }
                else
                {
                    cout << "Enter Valid Choice :" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            cout << "Enter Salary:" << endl;
            for (;;)
            {
                if (cin >> salary)
                {
                    break;
                }
                else
                {
                    cout << "Enter Valid Salary" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            if (dp_ch == 1)
            {
                emptype = 1;
                dept = "Developer";
                cout << "Enter Programming Language :" << endl;
                cin >> val1;
                cout << "Enter Team name :" << endl;
                cin >> val2;
                sdev sd;
                sd.id = id;
                sd.name = name;
                sd.age = age;
                sd.dept = dept;
                sd.salary = salary;
                sd.plang = val1;
                sd.team = val2;
                emp_handler->addData(emptype, sd);
            }

            else if (dp_ch == 2)
            {
                emptype = 2;
                dept = "Quality_Assuarance";
                cout << "Enter Assigned Project :" << endl;
                cin >> val1;
                cout << "Enter technology/Tool Known :" << endl;
                cin >> val2;
                sqa sq;
                sq.id = id;
                sq.name = name;
                sq.age = age;
                sq.dept = dept;
                sq.salary = salary;
                sq.assprjt = val1;
                sq.tectool = val2;
                emp_handler->addData(emptype, sq);
            }
            else if (dp_ch == 3)
            {
                emptype = 3;
                dept = "Manager";
                cout << "Enter No.of Project :" << endl;
                cin >> val1;
                cout << "Enter Years of Experience:" << endl;
                cin >> val2;
                sm sman;
                sman.id = id;
                sman.name = name;
                sman.age = age;
                sman.dept = dept;
                sman.salary = salary;
                sman.noofprjt = stoi(val1);
                sman.yofexp = stoi(val2);
                emp_handler->addData(emptype, sman);

            }
            save_flag = false;
            break;
        case 2:
            if (emp_handler->ListData())
            {
                cout << "Listed Sucessfully" << endl;
            }
            else
            {
                cout << "No data Found" << endl;
            }
            break;
        case 3:
            int d_id;
            cout << "Enter ID to Delete :" << endl;
            cin >> d_id;
            if (emp_handler->DeleteData(d_id))
            {
                cout << "Deleted Sucessfully" << endl;
            }
            else
            {
                cout << "No records Found" << endl;
            }
            save_flag = false;
            break;
        case 4:
        {
            int e_option;
            int op{};
            int s_op{};
            E_details ed{};
            cout << "1.ID\n2.Name\n3.Age\n4.Department\n5.Salary" << endl;
            cout << "Select Option to Search:";
            cin >> e_option;
            cout << "Enter value to search:" << endl;
            cin >> v;
            //Enum for Field
            if (e_option == 1)
            {
                ed = e_id;
            }
            else if (e_option == 2)
            {
                ed = e_name;
            }
            else if (e_option == 3)
            {
                ed = e_age;
            }
            else if (e_option == 4)
            {
                ed = e_dept;
            }
            else if (e_option == 5)
            {
                ed = e_salary;
            }
            SearchInterface* s = new SearchImplementation();
            if (e_option == 1 || e_option == 3 || e_option == 5)
            {
                thirdmap = s->searchByInt(stoi(v), ed, equalto, emp_handler->mapData());
            }
            else
            {
                thirdmap = s->searchByString(v, ed, containss, emp_handler->mapData());
            }

            printMap(thirdmap);
            break;
        }
        case 5:
            save_flag = true;
            emp_handler->saveData();
            break;
        case 6:
            {
            int e_option;
            int op{};
            int s_op{};
            E_details ed{};
            I_operation io{};
            S_operation so{};
            cout << "1.ID\n2.Name\n3.Age\n4.Department\n5.Salary" << endl;
            cout << "Select Option to Search:";
            cin >> e_option;
            if (e_option == 1 || e_option == 3 || e_option == 5)
            {
                cout << endl;
                cout << "1.Greater than\n2.Lesser than\n3.Equals to\n4.Greater than or equals to\n5.Lesser than or equals to" << endl;
                cout << "Enter Operation to search:" << endl;
                cin >> op;
            }
            else if (e_option == 2 || e_option == 4)
            {
                cout << endl;
                cout << "1.Starts with\n2.Ends with\n3.Contains" << endl;
                cout << "Enter Operation to search:" << endl;
                cin >> s_op;
            }
            cout << "Enter value to search:" << endl;
            cin >> v;
            {
                //Enum for Field
                if (e_option == 1)
                {
                    ed = e_id;
                }
                else if (e_option == 2)
                {
                    ed = e_name;
                }
                else if (e_option == 3)
                {
                    ed = e_age;
                }
                else if (e_option == 4)
                {
                    ed = e_dept;
                }
                else if (e_option == 5)
                {
                    ed = e_salary;
                }

                //Enum for Integer Operation
                if (op == 1)
                {
                    io = grter;
                }
                else if (op == 2)
                {
                    io = lesser;
                }
                else if (op == 3)
                {
                    io = equalto;
                }
                else if (op == 4)
                {
                    io = grthanequal;
                }
                else if (op == 5)
                {
                    io = lessthaequal;
                }

                //Enum for String operation
                if (s_op == 1)
                {
                    so = startswith;
                }
                else if (s_op == 2)
                {
                    so = endswith;
                }
                else if (s_op == 3)
                {
                    so = containss;
                }
            }
            SearchImplementation* s = new SearchImplementation();
            if (e_option == 1 || e_option == 3 || e_option == 5)
            {
                Prev_map = s->searchByInt(stoi(v), ed, io, emp_handler->mapData());
            }
            else
            {
                Prev_map = s->searchByString(v, ed, so, emp_handler->mapData());
            }
            int secon_and_or;
            do
            {
                int e_option;
                int op{};
                int s_op{};
                E_details ed{};
                I_operation io{};
                S_operation so{};

                cout << "Operations :\n1.AND\n2.OR\n3.NOT " << endl;
                cin >> secon_and_or;

                
                cout << "1.ID\n2.Name\n3.Age\n4.Department\n5.Salary" << endl;
                cout << "Select Option to Search:";
                cin >> e_option;
                if (e_option == 1 || e_option == 3 || e_option == 5)
                {
                    cout << endl;
                    cout << "1.Greater than\n2.Lesser than\n3.Equals to\n4.Greater than or equals to\n5.Lesser than or equals to" << endl;
                    cout << "Enter Operation to search:" << endl;
                    cin >> op;
                }
                else if (e_option == 2 || e_option == 4)
                {
                    cout << endl;
                    cout << "1.Starts with\n2.Ends with\n3.Contains" << endl;
                    cout << "Enter Operation to search:" << endl;
                    cin >> s_op;
                }
                cout << "Enter value to search:" << endl;
                cin >> v;
                {
                    //Enum for Field
                    if (e_option == 1)
                    {
                        ed = e_id;
                    }
                    else if (e_option == 2)
                    {
                        ed = e_name;
                    }
                    else if (e_option == 3)
                    {
                        ed = e_age;
                    }
                    else if (e_option == 4)
                    {
                        ed = e_dept;
                    }
                    else if (e_option == 5)
                    {
                        ed = e_salary;
                    }

                    //Enum for Integer Operation
                    if (op == 1)
                    {
                        io = grter;
                    }
                    else if (op == 2)
                    {
                        io = lesser;
                    }
                    else if (op == 3)
                    {
                        io = equalto;
                    }
                    else if (op == 4)
                    {
                        io = grthanequal;
                    }
                    else if (op == 5)
                    {
                        io = lessthaequal;
                    }

                    //Enum for String operation
                    if (s_op == 1)
                    {
                        so = startswith;
                    }
                    else if (s_op == 2)
                    {
                        so = endswith;
                    }
                    else if (s_op == 3)
                    {
                        so = containss;
                    }
                }
                SearchImplementation* s = new SearchImplementation();
                if (e_option == 1 || e_option == 3 || e_option == 5)
                {
                    Current_map = s->searchByInt(stoi(v), ed, io, emp_handler->mapData());
                }
                else
                {
                    Current_map = s->searchByString(v, ed, so, emp_handler->mapData());
                }
                cout << "Do you want to add filter again ? y/n " << endl;
                cin >> search_yn;
                thirdmap = emp_handler->SearchData(Prev_map, Current_map, secon_and_or);
                
            } while (search_yn!='n');
            printMap(emp_handler->SearchData(thirdmap, Current_map, secon_and_or));
            break;
            }
        }
        cout << "Do you want to continue? y/n:" << endl;
        cin >> yn;
        if (yn == 'n' && save_flag == false)
        {
            cout << "Do you want to Save? y/n:" << endl;
            cin >> s_yn;
            if (s_yn != 'n')
            {
                emp_handler->saveData();
            }
        }
    } while (yn != 'n');
}

