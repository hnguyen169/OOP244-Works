//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Compeleted: 05/25/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_EMPLOYEE_H_
#define SENECA_EMPLOYEE_H_
#define DATAFILE "employees.csv"

namespace seneca {
    struct Employee {
        char* m_name;
        int m_empNo;
        double m_salary;
    };

    // sorts the dynamic array of employees based on the GPA of the employees.
    void sort();

    // loads an employee structure with its values from the file.
    bool load(Employee& emp);

    // allocates the dynamic array of employees and loads all the file records into the array.
    bool load();

    // displays an employee record on the screen.
    void display(const Employee& emp);

    // first sorts the employees then displays all the employees on the screen.
    void display();

    // first will deallocate all the names in the employee elements
    // then it will deallocate the employee array.
    void deallocateMemory();
}

#endif // SENECA_EMPLOYEE_H_