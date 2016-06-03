/*
Program Name: "$ Fortune Teller"
Programmer: Bradley Cookson
Date: 9-28-15
Lab Section: 01
Purpose: The purpose of this program is to take a user's name and birth date information as input and use that information to calculate how old they are in days and to generate a "secret number," "magic number," and a value for "lucky money."
Algorithm: Inputs - first_name, last_name, birth_year, birth_month, birth_day;
           Processes - yearstodays = (2015-birth_year)*year;
                       monthstodays = (9-birth_month)*month;
                       days = (21-birth_day);
                       daysOld = yearstodays + monthstodays + days;
                       secretNumber = (rand()% cycle_number)+1;
                       magicNumber = daysOld % secretNumber;
                       luckyMoney = magicDollar*magicNumber;
           Outputs -   $ Fortune Teller for first_name last_name
                       Birthdate
                       Days Old
                       Secret Number
                       Magic Number
                       Lucky Money
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    //declare variables
    string first_name, last_name;
    int daysOld, secretNumber;
    const int cycle_number = 7;
    double birth_year, birth_month, birth_day, yearstodays, monthstodays, days, magicNumber, luckyMoney;
    const double year = 365.25, month = 30.4375, magicDollar = 25.25;
    //request user input
    cout << "What is your first name?" <<endl;
    cin >> first_name;
    cout << "What is your last name?" <<endl;
    cin >> last_name;
    cout << "What year were you born (enter 4 digit for year)?" <<endl;
    cin >> birth_year;
    cout << "What month were you born (enter 1-12)?" <<endl;
    cin >> birth_month;
    cout << "What day of the month were you born (enter 1-31)?" <<endl;
    cin >> birth_day;
    //processes
    yearstodays = (2015-birth_year)*year;
    monthstodays = (9-birth_month)*month;
    days = (21-birth_day);
    daysOld = yearstodays + monthstodays + days;
    secretNumber = (rand()% cycle_number)+1;
    magicNumber = daysOld % secretNumber;
    luckyMoney = magicDollar*magicNumber;
    // output information to the user
    cout << "$ Fortune Teller for " << first_name << " " << last_name <<endl;
    cout << "Birthdate: " << birth_month << "/" << birth_day << "/" << birth_year <<endl;
    cout << "Days Old: " << daysOld <<endl;
    cout << "Secret Number: " << secretNumber <<endl;
    cout << "Magic Number: " << magicNumber <<endl;
    cout << "Lucky Money: $" << luckyMoney <<endl;
    return 0; //end of main function
}
