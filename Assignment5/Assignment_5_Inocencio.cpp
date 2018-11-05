#include <iostream>
#include <fstream>
#include <iomanip>

/*
CSCI 14 | Assignment 5 | Jerold Inocencio
Using the data file capabilities of C++, 
create a Personnel file, personnel.dat on your drive 
and the C++ program that will write employee data to that file.
Your file will contain six employees.
REQUIREMENTS:
•	Format Yankee dollars
•	Based on what is in the field, perform the calculations. Data fields are more than just write ‘em, read ‘em.
•	Allow user to run application repeatedly
*/ 

using namespace std;

bool    run  = true; // keeps my program running!
//fstream data ("personnel.dat"); //initialize stream object
// makes printing easier
string info[6] = {"Employee ID", "Last Name", "First Name", "Hours Works", "Pay Rate", "Tax Rate"};

// prototypes
void    write_record(void);
void    get_record(void);
float   calculate_gross(string h, string p);
float   calculate_taxes(string g, string r);
float   calculate_net(string g, string t);

int     main(void)
{  
    char    response;
    while (run)
    {
        cout << "Main Menu" << endl;
        cout << "--------- \n";
        cout << "(1)   Write new Record to the Data file\n";
        cout << "(2)   Display Records from the Data file to the Screen\n";
        cout << "(3)   QUIT\n";
        cin >> response;
        switch (response)
        {
            case '1':
                write_record();
                break;
            case '2':
                get_record();
                break;
            case '3':
                run = false;
                break;
            default:
                cout << "\nPlease try again\n\n";
                continue;
                break;
        }
    }
}
void    write_record(void)
{
    ofstream data ("personnel.dat", ios::app);
    data.setf(std::ios::showpoint | std::ios::fixed);
    float   gross, taxes, net;
    string  items[6];

    data << endl;
    for(int i = 0; i <= 5; i++) // quicksave
    {
        cout << "Please enter " << info[i] <<": \n";
        cin >> items[i];
    }
    gross = calculate_gross(items[3], items[4]);
    taxes = calculate_taxes(to_string(gross), items[5]);
    net = calculate_net(to_string(gross), to_string(taxes));
    for(int i = 0; i <= 2; i++)
    {
        data << items[i] << " ";
    }
    string f1 = items[3], f2 = items[4], f3 = items[5]; //formatting
    data << setprecision(2) << atof(f1.c_str()) << " ";
    data << setprecision(2) << atof(f2.c_str()) << " ";
    data << setprecision(2) << gross << " ";
    data << setprecision(2) << taxes << " ";
    data << setprecision(2) << net << " ";
    data << setprecision(2) << atof(f3.c_str()) << " ";
    data << setprecision(2) << atof(f3.c_str()) << " ";
    data.close();
}

void    get_record(void)
{
    ifstream data ("personnel.dat");
    string token[10]; // {id, last, first, hours, pay, gross, taxes, net, tax}
    string buffer;
    size_t next = 0;

    for(int c = 1; getline(data, buffer); c++) //runs through each line in the file
    {
        for(int i = 0; (next = buffer.find(" ")) != string::npos; i++)
        {
            token[i] = buffer.substr(0, next); //saves each element from file
            buffer.erase(0, next + 1);
        }
        // print
        cout.setf(std::ios::showpoint | std::ios::fixed);
        printf("\n%11s #%d\n", "Record", c);
        cout << "Employee ID: " << token[0] << endl;
        cout << "Last name: " << token[1];
        cout << "   First Name: " << token[2] << endl;
        string f1 = token[3], f2 = token[4], f3 = token[8]; //formatting
        cout << "Hours worked: " << setprecision(2) << atof(f1.c_str());
        cout << "   Pay per Hour: $" << setprecision(2) << atof(f2.c_str());
        cout << "   Gross Pay: $" << token[5] << endl;
        cout << "Taxes: $" << token[6];
        cout << "   Net Pay: $" << token[7] << endl;
        cout << "Employee Tax Rate: " << setprecision(2) << atof(f3.c_str()) << endl;
    }
    data.close();
    cout << endl;
}

float   calculate_gross(string h, string p)
{   
    float hours = atof(h.c_str());
    float pay_rate = atof(p.c_str());
    float gross = hours*pay_rate;
    return gross;
}
float   calculate_taxes(string g, string r)
{   
    float gross = atof(g.c_str());
    float tax_rate = atof(r.c_str());
    float taxes = gross*tax_rate;
    return taxes;
}
float   calculate_net(string g, string t)
{   
    float gross = atof(g.c_str());
    float taxes = atof(t.c_str());
    float net = gross - taxes;
    return net;
}