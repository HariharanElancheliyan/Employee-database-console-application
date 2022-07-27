#include "pch.h"
#include "EmployeeFileHandler.h"
#include "EmployeeHandler.h"


void printMap(map<int, employee*>& p_map)
{
    system("CLS");
    
    size_t sizeofmap = p_map.size();
    map<int, employee*> ::iterator it;
    
    
    if (sizeofmap == 0)
    {
        cout << " No Records match with your criteria" << endl;
    }


    cout << "ID \tName \t\tAge \tDepartment \t\tSalary\tProg.Language\tTeam Name   Assigned Project   Technologies/Tools   No.of Project  Years of Experience" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    
    
    for (it = p_map.begin(); it != p_map.end(); it++)
    {
        cout << it->second->getempid() << '\t' << it->second->getempname() << '\t' << '\t' << it->second->getempage() << '\t' << it->second->getempdept();
        employee* eobj = it->second;
        if (eobj->getempdept() == "Developer")
        {
            developer* devobj = dynamic_cast<developer*>(eobj);
            cout << "\t\t" << devobj->getempsalary() << '\t' << devobj->getplang() << "\t\t" << devobj->gettname() << endl;
        }
        else if (eobj->getempdept() == "Quality_Assuarance")
        {
            qa* qaobj = dynamic_cast<qa*>(eobj);
            cout << '\t' << qaobj->getempsalary() << '\t' << "-" << "\t\t" << '-' << "\t\t" << qaobj->getassprjt() << "\t\t" << qaobj->gettools() << endl;
        }
        else if (eobj->getempdept() == "Manager")
        {
            Manager* maobj = dynamic_cast<Manager*>(eobj);
            cout << "\t\t\t" << maobj->getempsalary() << '\t' << "-" << "\t\t" << '-' << "                                                      \0" << maobj->getnfprjt() << "             \0" << maobj->getyexp() << endl;
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
    int salary;
    string val1;
    string val2;
    string v;

    char yn;
    char s_yn;
    char search_yn;
    int dp_ch = 0;

    bool save_flag = false;
    int arn = 0;

    map<int, employee*>p_map;
    map<int, employee*>Current_map;
    map<int, employee*>Prev_map;


    EmployeeHandler* emp_handler = new EmployeeFileHandler("employee_db.txt");
    do
    {
        int ch;
        cout << "\n1.Add Employee Data\n2.List all Employee Data\n3.Delete Employee Data\n4.Search\n5.Save to a File" << endl;
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

            save_flag = true;

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

            save_flag = true;

            break;
        case 4:
            {
                do
                {
                    int e_option;
                    int op{};
                    int s_op{};
                    E_details ed{};
                    I_operation io{};
                    S_operation so{};
                    map<int, employee*>SourceMap = emp_handler->mapData();
                    
                    if (arn != 3)
                    {
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

                        {
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

                        cout << "Enter value to search:" << endl;
                        cin >> v;

                        if (arn == 0 || arn == 2)
                        {
                            if (e_option == 1 || e_option == 3 || e_option == 5)
                            {
                                Current_map = emp_handler->SearchData(stoi(v), ed, io, SourceMap);
                            }
                            else if (e_option == 2 || e_option == 4)
                            {
                                Current_map = emp_handler->SearchData(v, ed, so, SourceMap);
                            }
                            if (arn == 2)
                            {
                                Current_map = emp_handler->PerformSetOperation(Prev_map, Current_map, _or);
                            }
                        }
                        else if (arn == 1)
                        {
                            if (e_option == 1 || e_option == 3 || e_option == 5)
                            {
                                Current_map = emp_handler->SearchData(stoi(v), ed, io, Prev_map);
                            }
                            else if (e_option == 2 || e_option == 4)
                            {
                                Current_map = emp_handler->SearchData(v, ed, so, Prev_map);
                            }

                            Current_map = emp_handler->PerformSetOperation(Prev_map, Current_map, _and);
                        }

                        printMap(Current_map);
                    }
                    else if (arn == 3)
                    {
                        Current_map = emp_handler->PerformSetOperation(Prev_map, Current_map, _not);
                        printMap(Current_map);
                    }


                    cout << "Do you want to add filter? y/n" << endl;
                    cin >> s_yn;


                    if (s_yn == 'y')
                    {
                        Prev_map = Current_map;
                        cout << "Operations :\n1.AND\n2.OR\n3.NOT " << endl;
                        cin >> arn;
                    }

                } while (s_yn != 'n');
            }
            break;
        case 5:

            save_flag = false;
            emp_handler->saveData();
            break;

        default:

            cout << "Enter a Valid Choice" << endl;
            break;
        }

        cout << "Do you want to continue? y/n:" << endl;
        cin >> yn;

        if (yn == 'n' && save_flag == true)
        {
            cout << "Do you want to Save? y/n:" << endl;
            cin >> s_yn;
            if (s_yn != 'n')
            {
                emp_handler->saveData();
            }
        }

    }while (yn != 'n');

}