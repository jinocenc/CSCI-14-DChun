#include <iostream>
#include <iomanip>
#include <cstdio>
/*
CSCI 14 | Assignment 4 | Jerold Inocencio
This program will compute the ticket price and profit for each group of passengers
starting at N to a user-fielded stopping point. #never exceeding 500
*/
using namespace std;

int     main(void)
{
    int     absolute_capacity = 500;
    int     NP, MP, i;
    float   TP, expense, cost, profit, discount;
    bool run = true;

    float    Pmax = 0;
    float TPmax = 0;
    int MPmax = 0;

    while(run)
    {
        cout << "Please input the minimum number of passengers: ";
        cin >> NP;
        cout << "Please input the maximum number of passengers: ";
        cin >> MP;
        cout << "Please input a ticket price for each passenger: ";
        cin >> TP;
        cout << "Please enter the total cost of the cruise: ";
        cin >> expense;
        cout << "At what rate would you like to discount groups of 10 after minimum? ";
        cin >> discount;
        cout << "Number   Passenger    Ticket Price    Gross    Fixed Cost    Profit" << endl;
        
        for(int n = MP; MP < NP; n+=10)
        {  
            cost = TP - (((NP - n) /10) * discount);
            profit = (n * cost) - expense;
            float spent = n*cost;
            printf("%d %4s%.2f %4s%.2f %4s%.2f %4s%.2f", n, '$', cost, '$', spent , '$', TP, '$', profit);
            //cout << n << end << cost << endl << n*cost << endl << expense << endl << profit << endl;
            if(profit > Pmax)
            {
                Pmax = profit;
                TPmax = cost;
                MPmax = n;
            }
        }

        printf("Maximum profit is %4s%f", '$', Pmax);
        printf("\n Ticket Cost to generate Max Profit is %4s$f", '$', TPmax);
        printf("\n Passengers needed to generate Max Profit is %4d\n", MPmax);

        cout << "\nTo run the program again, please press 1"<< endl;
        cout << "otherwise, press any key to exit."<< endl;
        cin >> i;

        if (i = 1) run = false;
        else continue;
        
    }

    return 0;
}