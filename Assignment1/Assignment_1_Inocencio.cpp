/*
 CSCI 14 | Assignment 1 | Jerold Inocencio
 Write a C++ application that will calculate AND print the customer's
 bill for mail order delivered machine parts
 from Shodd Dee Manufacturing.
*/
#include <iostream> //  for I/O functions
#include <cmath> //     for floor() function
#include <cstdio> //    for printf() function
#include <cstring> //   for strlen() function
using namespace std;

char    item [5][10] {"Whizbangs","Gizmos","Widgets","Wabbits","Elmers"}; // items for sale
float   prices [5] {5.00, 10.15, 5.99, 7.75, 9.50}; // prices of items for sale
float   tax = .0995; // Percent of subtotal
float   fee = .10; // Percent of subtotal

int     is_int(float test_num) // tests if argument is an integer
{
    if (test_num >= 0)
    {
        if (test_num == floor(test_num))
        {
            return 1;
        }
        else return 0;
    }
    else return 0;
}

int     main()
{
    char    r = '1'; // loop initialization

    while (r -'0')
    {
        float   quantity [5]{}; // save # of respective parts
        char    cust_acct [5]{}; // saves account number
        int     i = 0;
        float   sum = 0;
        // collect purchase information
        cout << "Please input your Customer ID to begin transaction: ";
        cin >> cust_acct;
        if (strlen(cust_acct) != 5)
        {
            cout << "Please input a valid 5-character Customer ID\n\n";
            continue;
        }
        do
        {
            printf("How many %s would you like to purchase? ", item[i]);
            cin >> quantity[i];
            if (!is_int(quantity[i]))
            {
                printf("You have input an invalid number of %s \nPlease try again.\n\n", item[i]);
                break;
            }
        }
        while(++i < 5);
        // print order receipt
        i = 0;
        cout << endl << "---------------------------------------";
        printf("\n%31s\n","SHODD DEE MANUFACTURING");
        printf("\nCustomer Account Number: %s\n", cust_acct);
        while (i < 5)
        {
            float total  = quantity[i]*prices[i];
            printf("\nNumber of %9s: %4.0fX $%5.2f %5s%5.2f",item[i],quantity[i],prices[i],"$",total);
            i++;
            sum += total;
        }
        float sales_tax = sum*tax;
        float ship_hand = sum*fee;
        float grand_total = ship_hand + sales_tax + sum;
        printf("\n\nSubtotal %30s%.2f","$",sum);
        printf("\nSales Tax (@ %.2f%%)%20s%.2f",tax,"$",sales_tax);
        printf("\nShipping & Handling (@ %.2f%%)%10s%.2f",fee,"$",ship_hand);
        printf("\n%43s\n","=====");
        printf("Grand Total:%27c%.2f\n",'$',grand_total);
        // loop reinit
        cout << endl << "---------------------------------------";
        cout << "\nEnter any key to begin another transaction.\nOtherwise enter '0' to exit: ";
        cin >> r;
        cout << endl;
    }

}
