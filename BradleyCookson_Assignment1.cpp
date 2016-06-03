/*

Program Name: Programming Assignment 1

Programmer: Bradley Cookson

Date: 10-16-15

Purpose: The purpose of this program is to create a Rock/Paper/Scissors game and a Dice Roll game.  The program is designed to have a main menu where the user
selects the game they want to play or decides to exit the program.  If the user decides to play one of the games, one of two sub-menus will be displayed
depending on the user's selection that will give the user the game's rules and selection options.  The program ends after it runs one time or the user decides
to exit.

Algorithm: Inputs - menu1_choice, menu2_choice, menu3_choice;

           Process Functions -  rockPaperScissors: Generates a random number from 1 to 3 that corresponds with a computer generated selection of Rock, Paper
                                                   or Scissors.

                                rollDice1: Generates a random number from 1 to 6 that corresponds with the roll of one dice.

                                rollDice2: Generates a random number from 1 to 6 that corresponds with the roll of one dice. (Only used when a user selects to
                                           roll two dice at once.)

           Menu Functions -     Menu1:  1. Play Rock/Paper/Scissor Game
                                        2. Play Dice Role Game
                                        3. Exit (if any other input)
                                        Enter your choice:

                                Menu2:  Rock/Paper/scissors game
                                        The rules are:
                                            Rock beats scissors.
                                            Scissors beats Paper.
                                            Paper beats rock.

                                        Game Choices: 1. Rock
                                            2. Paper
                                            3. Scissors
                                            4. Quit, exit the program
                                        Please enter your choice:

                                Menu3:  Role Dice game.
                                        The rules are:
                                            You get 10 points if you get two dice and get a 7.
                                            You get 5 if you role two dice and get identical numbers.
                                            You get 3 points if you role one dice and get 4.

                                        Game Choices:
                                            1. Roll only one dice
                                            2. Roll two dice
                                            3. Quit, exit the program
                                        Please enter your choice:

                Pseudocode - 1. The program calls menu1
                             2. User enters a choice from menu1
                             3. Depending on the choice, the program will:
                                a. Call menu2
                                    i. User enters a choice from menu2
                                    ii. The program calls rockPaperScissors to generate a random number from 1 to 3 that corresponds to rock, paper, or scissors
                                    iii. Depending on the user choice and the computer generated random number, the program will either:
                                        I. Ouput that the user won and end the program
                                        II. Ouput that the user lost and end the program
                                        III. Output that the game was a tie and end the program
                                        IV. Exit the program
                                b. Call menu3
                                    i. User enters a choice from menu3
                                    ii. Depending on the user choice, the program will either:
                                        I. Call rollDice1 to generate a random number from 1 to 6
                                            1. If the result is a 4, the program outputs that the user earned 3 points and ends the program
                                            2. If the result is not a 4, the program outputs that the user did not earn any points and ends the program
                                        II. Call both rollDice1 and rollDice2 in order to generate two random numbers each from 1 to 6
                                            1. If the sum of the two dice rolls is 7, the program outputs that the user earned 10 points and ends the program
                                            2. If the two dice rolls are equivalent, the program outputs that the user earned 5 points and ends the program
                                            3. If the two dice rolls are neither equivalent nor sum to 7, the program outputs that the user did not earn any
                                               points and ends the program
                                        III. Exit the program
                                c. Exit the program
*/

#include <iostream>
#include <cstdlib>

using namespace std;

//Function Prototypes

int menu1(); // This is the menu1 function prototype.

int menu2(); // This is the menu2 function prototype.

int menu3(); // This is the menu3 function prototype.

int rockPaperScissors(); // This is the rockPaperScissors function prototype.

int rollDice1(); // This is the rollDice1 function prototype.

int rollDice2(); // This is the rollDice2 function prototype.

//The program starts here.

int main() { // This is the menu1 function prototype.

    int menu1_choice, menu2_choice, computer_choice, menu3_choice, roll_result1, roll_result2; // These are the variables for the main function.

    menu1_choice = menu1(); // The program calls menu1.

    if (menu1_choice == 1) { // The user selects the Rock/Paper/Scissors game.

        menu2_choice = menu2(); // The program calls the menu2 functions and assigns the return value to the menu2_choice variable.

        computer_choice = rockPaperScissors(); // The program calls the rockPaperScissors function, generates a random computer choice, and assigns it to the computer_choice variable.

            if (menu2_choice == 1) { // The user selects Rock.

                if (computer_choice == 1){ // The computer randomly selects Rock.

                    cout << "The computer picked Rock. You Tied!" << endl; // The outcome is a tie game.

                } else if (computer_choice == 2) { // The computer randomly selects Paper.

                    cout << "The computer picked Paper. You Lose." << endl; // The outcome is that the user loses the game.

                } else { // The computer randomly selects Scissors.

                    cout << "The computer picked Scissors. You Win!" << endl; // The outcome is that the user wins the game.

                }

            } else if (menu2_choice == 2) { // The user selects Paper.

                if (computer_choice == 1){ // The computer randomly selects Rock.

                    cout << "The computer picked Rock. You Win!" << endl; // The outcome is that the user wins the game.

                } else if (computer_choice == 2) { // The computer randomly selects Paper.

                    cout << "The computer picked Paper. You Tied!" << endl; // The outcome is a tie game.

                } else { // The computer randomly selects Scissors.

                    cout << "The computer picked Scissors. You Lose." << endl; // The outcome is that the user loses the game.

                }

            } else if (menu2_choice == 3) { // The user selects Scissors.

                if (computer_choice == 1){ // The computer randomly selects Rock.

                    cout << "The computer picked Rock. You Lose." << endl; // The outcome is that the user loses the game.

                } else if (computer_choice == 2) { // The computer randomly selects Paper.

                    cout << "The computer picked Paper. You Win!" << endl; // The outcome is that the user wins the game.

                } else { // The computer randomly selects Scissors.

                    cout << "The computer picked Scissors. You Tied!" << endl; // The ourcome is a tie game.

                }

            } else { // The user decides to exit the program or inputs an invalid entry.

                return 0; //The user decides to exit the program.

            }

    } else if (menu1_choice == 2) { // The user selects the Dice Roll Game.

        menu3_choice = menu3(); // The program calls menu3 and returns the user selection to menu3_choice.

            if (menu3_choice == 1) { // This is the start of a conditional statement for the Roll Dice Game where the user selects option 1 from menu2.

                roll_result1 = rollDice1(); // The program calls RollDice1 and assigns it to the roll_result1 variable.

                    if (roll_result1 == 4) { // Nested conditional branch that displays the reults of one roll of the dice

                        cout << "You earned 3 points!" << endl; // Output line

                    } else {

                        cout << "You didn't earn any points this round." << endl; // Output line

                    }

            } else if (menu3_choice == 2) { // The user selects option 2 to roll two dice.

                roll_result1 = rollDice1(); // The program calls rollDice1 and assigns the return value to roll_result1 variable.

                roll_result2 = rollDice2(); // The program calls rollDice2 and assigns the return value to the roll_result2 variable

                    if ((roll_result1 + roll_result2) == 7) { //  This is a Nested conditional branch that displays the results of both rolls of the dice.

                        cout << "You earned 10 points!" << endl;

                    } else if (roll_result1 == roll_result2) {

                        cout << "You earned 5 points!" << endl;

                    } else {

                        cout << "You didn't earn any points this round." << endl;

                    }

            } else {

                return 0; //The user decides to exit the program.

            }

    } else { // The user decides to exit the program

        return 0; // The user decides to exit the program.

    }

    return 0; // This is the end of the main function.

}

//Menus

int menu1() { // This menu provides options for the initial menu that the user will see at the start of the program.

    int user_choice1;

    cout << "1. Play Rock/Paper/Scissor Game" << endl;
    cout << "2. Play Dice Roll Game" << endl;
    cout << "3. Exit(if any other input)" << endl;
    cout << "                           " << endl;
    cout << "Enter your choice: " << endl;

    cin >> user_choice1;

    return user_choice1;

}

int menu2() { // This menu provides options for the rock/paper/scissors game.

    int user_choice2;

    cout << "Rock/Paper/Scissors game" << endl;
    cout << "The Rules are: " << endl;
    cout << "     Rock beats scissors" << endl;
    cout << "     Scissors beats Paper" << endl;
    cout << "     Paper beats rock" << endl;
    cout << "                     " << endl;
    cout << "Game Choices: " << endl;
    cout << "     1. Rock " << endl;
    cout << "     2. Paper " << endl;
    cout << "     3. Scissors " << endl;
    cout << "     4. Quit, exit the program " << endl;
    cout << "Please enter your choice: " << endl;

    cin >> user_choice2;

    return user_choice2;

}

int menu3() { // This menu provides options for the roll dice Game.

    int user_choice3;

    cout << "Roll Dice Game" << endl;
    cout << "The Rules are: " << endl;
    cout << "     You get 10 points if you roll two dice and get a 7." << endl;
    cout << "     You get 5 if you roll two dice and get identical numbers." << endl;
    cout << "     You get 3 points if you roll one dice and get a 4." << endl;
    cout << "                     " << endl;
    cout << "Game Choices: " << endl;
    cout << "     1. Roll only one dice " << endl;
    cout << "     2. Roll two dice " << endl;
    cout << "     3. Quit, exit the program " << endl;
    cout << "Please enter your choice: " << endl;

    cin >> user_choice3;

    return user_choice3;

}

//Processes

int rockPaperScissors() { // This is a function that generates a random number from 1 to 3 to simulate a computer generated version of rock/paper/scissors.
    int x;
    x = (rand() % 3) + 1;
    return x;
}

int rollDice1() { // This is a roll dice function to generate a random number from 1 to 6.
    int a;
    a = (rand() % 6) + 1;
    return a;
}

int rollDice2() { // This is a second roll dice function to generate a random number form 1 to 6.
    int b;
    b = (rand() % 6) + 1;
    return b;
}
