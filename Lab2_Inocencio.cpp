/*
CSCI 14 | Lab Assignment 2 | Jerold Inocencio
*/
#include <iostream>
using namespace std;

float   your_num_1;
float   your_num_2;

float add(void);
float subtract(void);
float multiply(void);
float divide(void);
float mod(void);

int     main(void)
{
    cout << "Please input two numbers to be calculated." << endl;
    cout << "Your first number: ";
    cin >> your_num_1;
    cout << "Your second number: ";
    cin >> your_num_2;
    add();
    subtract();
    multiply();
    divide();
    mod();
}

float add(void)
{
    float   sum = your_num_1 + your_num_2;
    cout << your_num_1 << " + " << your_num_2 << " = " << sum << endl;
    return sum;
}

float subtract(void)
{
    float   diff = your_num_1 - your_num_2;
    cout << your_num_1 << " - " << your_num_2 << " = " << diff << endl;
    return diff;
}

float multiply(void)
{
    float   prod = your_num_1 * your_num_2;
    cout << your_num_1 << " * " << your_num_2 << " = " << prod << endl;
    return prod;
}

float divide(void)
{
    float   rate = your_num_1 / your_num_2;
    cout << your_num_1 << " / " << your_num_2 << " = " << rate << endl;
    return rate;
}

float mod(void)
{
    float   remainder = (int)your_num_1 % (int)your_num_2;
    cout << your_num_1 << " % " << your_num_2 << " = " << remainder << endl;
    return remainder;
}