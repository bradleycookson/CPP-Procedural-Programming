/*
Program: C-P-P Fast Food
Author: Bradley Cookson
Date: 10/26/2015
Lab Section: 01
Purpose: The purpose of this program is to recreate a fast food menu and to print a receipt to the user.
Algorithm:
*/

#include <iostream>

using namespace std;

int menu();

float findSubTotal(int, float);

float applyDiscounts(float);

void showReceipt(string, float, int, bool, float);

int main()
{
    int choice, choiceQuantity, itemPrice, subTotal;
    const float burger_price = 4.50, fries_price = 1.25, chicken_price = 3.5, salad_price = 3.0, drink_price = 1.0;
    float subTotalWithDiscounts;


    choice = menu();

    while (choice < 1 || choice > 5) {
        cout << "Please input a valid choice from the menu." << endl;
        choice = menu();
    }

    if (choice == 1) {
        itemPrice = burger_price;
    } else if (choice == 2) {
        itemPrice = fries_price;
    } else if (choice == 3) {
        itemPrice = chicken_price;
    } else if (choice == 4) {
        itemPrice = salad_price;
    } else if (choice == 5) {
        itemPrice = drink_price;
    }

    cout << "How many of the item would you like?: " << endl;

    cin >> choiceQuantity;

    subTotal = findSubTotal(choiceQuantity, itemPrice);

    subTotalWithDiscounts = applyDiscounts(subTotal);

    return 0;
}

int menu() {

int user_choice;

cout << "1. Burger $4.50" << endl;
cout << "2. Fries $1.25" << endl;
cout << "3. Chicken $3.50" << endl;
cout << "4. Salad $3" << endl;
cout << "5. Drink $1" << endl;
cout << "Which item would you like to purchase?: " << endl;

cin >> user_choice;

return user_choice;

}

float findSubTotal (int quantity, float price) {

float sub_total;

sub_total = quantity * price;

return sub_total;

}

float applyDiscounts(float total){

    bool membership, coupon;
    float couponValue, totalWithMemberDiscount, totalWithDiscounts;

    cout << "Are you a rewards member? (Enter 1 for Yes and 0 for No)" << endl;

    cin >> membership;

    if (membership == 1) {

        totalWithMemberDiscount = (total * 0.9);

    } else if (membership == 0) {

        totalWithMemberDiscount = total;

    }

    cout << "Do you have the coupon? (Enter 1 for Yes and 0 for No)" << endl;

    cin >> coupon;

    if (coupon == 1) {

        cout << "What is the value of the coupon?" << endl;

        cin >> couponValue;

        totalWithDiscounts = totalWithMemberDiscount - couponValue;

    } else if (coupon == 0) {

        totalWithDiscounts = totalWithMemberDiscount;

    }
    return totalWithDiscounts;
}

void showReceipt(string item, float itemPrice, int quantity, bool membership, float coupon) {

cout << "The item you selected: " << endl;
cout << "The price of the item: " << endl;
cout << "Quantity: " << endl;
cout << "Subtotal: " << endl;
cout << "Subtotal with your discounts: " << endl;
cout << "Final Price: " << endl;


}

