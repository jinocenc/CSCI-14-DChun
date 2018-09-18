/*
CSCI 14 | Lab Assignment 3 | Jerold Inocencio
Problems in computations include mathematical precision 
(i.e. double, float, long, integer) especially when using mixed mode arithmetic. 
An aspect of using an IF statement is to control what appears to the user.
Applications must also provide the data in a “useable” and readable format 
for the user hence formatting for any currency.
*/

#include <cstdio> // C I/O
#include <iostream> // .setf
#include <iomanip> // printf()
#include <cmath> // rounding - ceilf()

using namespace std;

float   input;
int     cents;
int     denomination[10] = {2000, 1000, 500, 100, 50, 25, 10, 5, 1};
char    categories[30][10] = {"twenties", "tens", "fives", "ones", "50-cents", "quarters", "dimes", "nickels", "pennies"};

int     main(void)
{   
    cout << "Please input a value to be categorized into denominations: $";
    cin>> input;
    cents = ceilf(input*100);
    cout << "$" << setprecision(2) << fixed << input << " is equvalent to " << cents << " pennies." << endl;
    cout << "------------------------" << endl << endl;
    cout << "This translates to:" << endl;

    int     quantity = 0;
    int     leftover = cents;
    
    for (int i = 0; i < 9; i++)
    {  
        quantity = leftover / denomination[i];
        leftover = leftover - quantity * denomination[i];
        if (quantity > 0)
        {
            printf("%d  %s\n", quantity, categories[i]);
            //cout << quantity << " " << leftover << endl;
        }
        else continue;
    }
    return 0;
}