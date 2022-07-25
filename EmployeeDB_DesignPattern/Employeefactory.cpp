#include "pch.h"
#include "Employeefactory.h"


employee* Employeefactory::emp_factory(int num)
{
    if (num == 1)
    {
        return new developer();
    }
    else if (num == 2)
    {
        return new qa();
    }
    else if (num == 3)
    {
        return new Manager();
    }
    else
    {
        cout << "Invalid Choice of Department" << endl;
        return { nullptr };
    }
}
