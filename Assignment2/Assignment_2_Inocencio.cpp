/*
CSCI 14 | Assignment 2 | Jerold Inocencio
Write  the  program  logic  that  will  compute  the  paycheck  of  an  employee.
This  is  as  much  an  exercise  in designing your logic as much as a programming 
exercise in the grammar and syntax.
*/

#include <iostream> // std:: I/O functions
#include <iomanip> // setprecision()
using namespace std;

char    lastname[20];
char    firstname[20];
char    employee_id[5];
float   workhour_total;
float   pay_rate;
float   fed_rate = .20; // tax rate
float   state_rate = .05; // tax rate

void   paycheck(void);

int     main(void)
{
    cout << "To being computing your paycheck-" << endl << "Please enter your Last name: ";
    cin >> lastname;
    cout << "Please enter your First name: ";
    cin >> firstname;
    cout << "Please enter your employee ID: ";
    cin >> employee_id;
    cout << "\nEnter total hours worked: ";
    cin >> workhour_total;
    cout << "Enter pay rate: ";
    cin >> pay_rate;

    if (pay_rate < 0 || workhour_total < 0)
    {
        cout << "\nSorry, you entered a negative value and your paycheck cannot be computed." << endl;
        return 0;
    }
    if (pay_rate < 10.75) pay_rate = 10.75;
    if (pay_rate > 100) pay_rate = 100;
    if (workhour_total > 60) workhour_total = 60;

    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout << "----------------------" << endl << endl;
    cout << "Employee ID: " << employee_id << endl;
    cout << "Employee: "<< firstname << " " << lastname << endl;
    cout << "Total Hours Worked: " << setprecision(2) << workhour_total << endl << endl;
    paycheck();
    return 0;
}

void   paycheck(void)
{
    float   reg_pay, over_pay, gross_pay, net_pay;
    float   fed_tax, state_tax;
    float   overtime = workhour_total - 40;
    if(overtime <= 0)
    {
        // no overtime
        gross_pay = workhour_total * pay_rate; 
        fed_tax = gross_pay * fed_rate;
        state_tax = gross_pay * state_rate;
        net_pay = gross_pay - fed_tax - state_tax;

        cout << "Hours worked (" << workhour_total << ") @ $" << pay_rate << endl;
        cout << setw(5) << "Regular Pay: $" << gross_pay << endl << endl;
        cout << "Employee Gross Pay: " << setw(18) << "$" << gross_pay << endl;
        cout << "Federal Taxes Withheld @ 20.00\%: " << setw(5) << "$" << fed_tax << endl;
        cout << "State Taxes Withheld @ 5.00\%: " << setw(8) << "$" << state_tax << endl << endl;
        cout << "Employee Net Pay: " << setw(20) << "$" << net_pay << endl;
    }
    else
    {
        // overtime
        reg_pay = 40 * pay_rate; 
        over_pay = overtime * 2 * pay_rate;
        gross_pay = reg_pay + over_pay;
        fed_tax = gross_pay * fed_rate;
        state_tax = gross_pay * state_rate;
        net_pay = gross_pay - fed_tax - state_tax;
        
        cout << "Hours worked (40.00) @ $" << pay_rate << endl;
        cout << "Regular Pay: $" << reg_pay << endl;
        cout << "Overtime Hours worked (" << overtime << ") @ $" << 2*pay_rate << endl;
        cout << "Overtime Pay: $" << over_pay << endl << endl;
        cout << "Employee Gross Pay: " << setw(18) << "$" << gross_pay << endl;
        cout << "Federal Taxes Withheld @ 20.00\%: " << setw(5) << "$" << fed_tax << endl;
        cout << "State Taxes Withheld @ 5.00\%: " << setw(8) << "$" << state_tax << endl << endl;
        cout << "Employee Net Pay: " << setw(20) << "$" << net_pay << endl;
    }
}