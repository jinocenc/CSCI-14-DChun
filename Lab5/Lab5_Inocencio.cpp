#include <cstdlib>
#include <time.h>
#include <iostream>

/*
CSCI 14 | Lab Assignment 5 | Jerold Inocencio
1.	Load a single dimensional array of size 100 with a random number
2.	The random number will range from 1 to 1,000 (you may have duplicate values)
3.	Find the highest value and the index location that it was in
4.	Find the smallest value and the index location that it was in
5.	Display the array’s contents.
6.	Display the highest value and its index location
7.	Display the lowest value and its index location
8.	Allow the user to execute this application multiple times (some sort of loop?)
*/ 

char run = '1';
using namespace std;

int     main (void)
{
    srand((unsigned)time(NULL));
    while(run - '0')
    {
        int     myarr [100];
        int     max = 0;
        int     min = 1000;
        int     i_max, i_min;

        // load array
        for(int i = 0; i < 100; i++)
        {
            myarr[i] =  rand() % 1000 + 1; 
        }
        
        // print and search array
        for(int i = 0; i < 100; i++)
        {
            cout << "Index# " << i << " => " << myarr[i] << endl; 
            if(myarr[i] > max)
            {
                max = myarr[i];
                i_max = i;
            }
            if(myarr[i] < min)
            {
                min = myarr[i];
                i_min = i;
            }
        }    
        cout << "\n\nHighest value is " << max << " @ Index# " << i_max << endl;
        cout << "Lowest value is " << min << " @ Index# " << i_min << endl;
        cout << "\nEnter any key to run again.\nOtherwise enter '0' to exit: ";
        cin >> run;
    }
}