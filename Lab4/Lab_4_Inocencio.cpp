/*
CSCI 14 | Lab 3 | Jerold Inocencio
This Lab exercise demonstrates the use of the 
“For Loop”, a standard loop in all programming languages. 
*/

#include <iostream>
using namespace std;

int     main(void)
{
    int     N;
    int     sum;

    sum = 0;
    cout << "Please input a number of time to run the For Loop: ";
    cin >> N;

    for (int n = 1; n <= N; n++)
    {
        sum += n;
        cout << n;
        if (n < N)
        {
            cout << " + ";
        }
        else 
        {
            cout << " = " << sum << endl;
        }
    }
    cout << "You ran the 'For Loop' " << N << " times.";
    return 0;
}