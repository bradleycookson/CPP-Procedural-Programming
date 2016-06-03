/*

Author: Bradley Cookson
Date: 11/23/15
Description: This program simulates an ATM by prompting the user to create an account or login to their pre-existing account. Once they have logged in to their account, they can either deposit money, withdrawal money, or check their balance.  Also, at any point the user can exit the program.

Pseudocode: 1. Prompt the user to make a selection utilizing the main menu
                a. If the user decides to make a new account, call the new account function and write their username and password to credentials.txt.  Return to main menu after the new account is created.
                b. If the user decides to login, have them input their username and password, validate their credentials by cross-checking it against the saved credentials in credentials.txt.  If they don't match return to the main menu.  If they do match, call the banking menu function.
                    i. Prompt the user to make a selection utilizing the banking menu
                        1. If the user decides to deposit money, ask them for the amount and add it to their current balance.
                        2. If the user decides to withdrawal money, ask them for the amount, check that they have enough in their account.  If they have enough subtract that from their current balance and output their new balance.  If they do not have enough, output an insufficient funds message and return them to the banking menu.
                        3. If the user decides to check their balance, output a message containing their current balance.
                        4. If the user decides to quit the program from the banking menu, end the program.
                c. If the user decides to exit the program from the main menu, end the program.

*/



// Header files
#include <iostream>
#include <fstream>
#include <string>

// Namespace line
using namespace std;

// Function Prototypes
char mainMenu();
char bankingMenu();
void createAccount(string, string);
bool login(string, string);
void deposit(double&, double);
bool withdrawal(double&, double);
void displayBalance(double);

// Main function - initiates mainMenu function
int main(){
    char mainMenuChoice, bankingMenuChoice;
    string username, password;
    double amount, balance = 0;

    // Function call to main menu that assigns the return char value to mainMenuChoice
    mainMenuChoice = mainMenu();

    // Conditional statement to determine the path the user takes after selecting an option from the main menu
    if (mainMenuChoice == 'c' || mainMenuChoice == 'C') {
        cout << "Please enter you username: ";
        cin >> username;
        cout << "Please enter your password: ";
        cin >> password;
        createAccount(username, password);
        cout << "Thank you! We have created your new account.\n";
        mainMenuChoice = mainMenu();
    }

    if (mainMenuChoice == 'l' || mainMenuChoice == 'L') {
        cout << "Please enter your username: ";
        cin >> username;
        cout << "Please enter you password: ";
        cin >> password;
        if (login(username, password)) {

            cout << "Credentials Accepted\n";

            // Function call to bankingMenu that assigns the return char value to bankingMenuChoice
            bankingMenuChoice = bankingMenu();

            // Nested conditional statement to determine the path the user takes after selecting an option from the banking menu
            if (bankingMenuChoice == 'w' || bankingMenuChoice == 'W') {
                cout << "Enter amount of withdrawal: $";
                cin >> amount;

                if (!withdrawal(balance, amount)) {
                    cout << "The withdrawal amount exceeds the balance. You cannot withdrawal that amount at this time.\n";
                }

            } if (bankingMenuChoice == 'd' || bankingMenuChoice == 'D') {
                cout << "Enter amount of deposit: $";
                cin >> amount;
                deposit(balance, amount);
                cout << "$" << amount << " was deposited.\n";
            } if (bankingMenuChoice == 'b' || bankingMenuChoice == 'B') {
                displayBalance(balance);
            } if (bankingMenuChoice == 'q' || bankingMenuChoice == 'Q') {
                cout << "Thank you for choosing Future Programmer's Bank!\n";
            }
            return 0;

        } else {
            cout << "Login failed\n";
        }

    } if (mainMenuChoice == 'q' || mainMenuChoice == 'Q') {
        return 0;
    }

    return 0;
}

// createAccount function - takes userName and userPassword as arguments and writes to credentials.txt
void createAccount(string userName, string userPassword){

    ofstream outputFile;

    outputFile.open("credentials.txt", ios::out | ios::app);

    outputFile << userName << endl;
    outputFile << userPassword << endl;

    outputFile.close();
}

/* login function - takes userName and userPassword as arguments, reads from credentials.txt to compare input to userName and userPassword stored in credentials.txt, returns true or false */
bool login(string userName, string userPassword){

    ifstream inputFile;

    inputFile.open("credentials.txt");

    string input_name, input_password;

    inputFile >> input_name;
    inputFile >> input_password;

    if (userName == input_name && userPassword == input_password){
        inputFile.close();
        return true;
    } else {
        inputFile.close();
        return false;
    }
}

/* deposit function - takes balance and deposit_amount as arguments and adds the deposit_amount to the balance */
void deposit(double &balance, double deposit_amount){
    balance += deposit_amount;
}

/* withdrawal function - takes balance and withdrawal_amount as arguments, checks to see if the withdrawal_amount is greater than the balance, if it is not it subtracts the withdrawal_amount from the balance and returns true, otherwise, it returns false */
bool withdrawal(double &balance, double withdrawal_amount){
    if (balance >= withdrawal_amount){
        balance -= withdrawal_amount;
        return true;
    }
    else{
        return false;
    }
}

// dispalyBalance function - takes balance as an argument and outputs it to the console
void displayBalance(double balance){
    cout << "Your balance is $" << balance << ".\n";
}

/* bankingMenu funtion - displays the banking menu after the user credentials have been authenticated, checks whether their input is valid, and returns the char value for choice2 */
char bankingMenu(){
    char choice2;

    do{
        cout << "Please select an option from the menu below" << endl;
        cout << "W: Withdraw Money\n";
        cout << "D: Deposit Money\n";
        cout << "B: Request Balance\n";
        cout << "Q: Quit\n";
        cout << "What would you like to do?";

        cin >> choice2;

    } while (choice2 != 'W' && choice2 != 'w' && choice2 != 'D' && choice2 != 'd' && choice2 != 'B' && choice2 != 'b' && choice2 != 'Q' && choice2 != 'q');

    return choice2;
}

/* mainMenu funtion - displays the main menu, checks whether their input is valid, and returns the char value for choice2 */
char mainMenu(){
    char choice1;

    do{
        cout << "Hi! Welcome to future programmer ATM machine! Please select an option from the menu below:\n";
        cout << "C: Create New Account\n";
        cout << "L: Login\n";
        cout << "Q: Quit\n";
        cout << "What would you like to do? ";

        cin >> choice1;

    } while (choice1 != 'c' && choice1 != 'C' && choice1 != 'L' && choice1 != 'l' && choice1 != 'Q' && choice1 != 'q');

    return choice1;

}
