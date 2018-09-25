/*
CSCI 14 | Assignment 3 | Jerold Inocencio
You are using the switch to calculate the quantity discount.
 Since the switch does not allow a range, you have to set a 
 “code” for the quantity range to use in the Switch such as 
 and integer code 1, 2, 3, or 4 or maybe a char ‘a’, ‘b’, ‘c’ or ‘d’. 
*/
#include <iostream>
#include <iomanip>

// Declare global constants =================================================================================
char    names[5][24] = {"Milk Chocolate", "Dark European Chocolate", "White Chocolate", "European Truffles"};
float   costs[5] = {8.50, 9.75, 10.50, 12.50};
float   shipping = .10; // 10% of subtotal

// Prototypes ===============================================================================================
int   which_discount(float  gross);
float   sum_arr(float array[]);
void    print_reciept(float pounds[], float purchase[], float discount );

// Functions ================================================================================================
int     main(void)
{   
    float   poundage[5] = {};
    float   order[5] = {};
    int     gross;
    float   discount;
    int     i = 0;

    while(i < 4) // loop will prompt user for their order
    {
        printf("How many pounds of %s -@ %.2f- would you like? \n", names[i], costs[i]); 
        std::cin >> poundage[i];
        order[i] = poundage[i]*costs[i];
        i++;
    }
   // gross = sum_arr(order);
     gross = which_discount(sum_arr(order));
    switch(gross) // declares the percentage of order to be discounted
    {
        case 1:
            discount = .10;
            print_reciept(poundage, order, discount);
            break;
        case 2:
            discount = .15;
            print_reciept(poundage, order, discount);
            break;
        case 3:
            discount = .20;
            print_reciept(poundage, order, discount);
            break;
        case 4:
            discount = .25;
            print_reciept(poundage, order, discount);
            break;
        default: 
            discount = 0;
            print_reciept(poundage, order, discount);
            break;
    }

}

float sum_arr(float array[])
{
    float val = 0;
    int i = 0;
    while(array[i] != '\0')
    {
        val = val + array[i];
        i++;
    }
    return val;
}

int   which_discount(float  gross) // returns an integer to be interpreted
{
    if(gross >= 20 && gross < 39.99)
    {
        return 1;
    }
    if(gross >= 40.00 && gross < 59.99)
    {
        return 2;
    }
    if(gross >= 60.00 && gross < 79.99)
    {
        return 3;
    }
    if(gross >= 80.00)
    {
        return 4;
    }
}

void    print_reciept(float pounds[], float purchase[], float discount )
{
    int i = 0;
    float order_total = sum_arr(purchase);
    float subtotal = sum_arr(purchase)*(discount+1);
    std::cout << "\n===============Invoice Order==================" << std::endl;
    while( i < 4)
    {
        if(pounds[i] != 0)
        {
            printf("%05.2f lbs of%24s @ %6.2f per lb: %11c%.2f\n", pounds[i], names[i], costs[i], '$', purchase[i]);
            i++;
        }
        else
        {
            i++;
            continue;
        }
    }
    printf("\nTotal order %53c%06.2f\nDiscount %56s%03.2f\n", '$', order_total, "-$", discount*order_total);
    printf("\nSubtotal %56c%.2f\n",'$', subtotal);
    printf("Shipping & Handling @ %.0f%% (based on $%.2f) %21c%05.2f", shipping*100, subtotal, '$', shipping*subtotal);
    printf("\n\nGrand total %53c%05.2f", '$', subtotal*(1+shipping));
}