/*
 Author: Bradley Cookson
 Date: 12/9/15
 Description: this is a search and sorting program that simulates a potential customer/user searching a bookstore's inventory by an ID number for information about the book's name
 price and how much their total will be based on the quantity that they would like to purchase. This program also uses sorting functions to sort through an array
 of 1000 numbers and output them to the user in ascending order.
 */

// Header Files
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <chrono>

// Namespace Line
using namespace std;

// Function Prototypes
int menu();
void display(string[], int[], double[]);
void linearSearch(string[], int[], double[], int);
void binarySearch(string[], int[], double[], int);
void bubbleSort();
void selectionSort();

// Main Function
int main()
{
    // Initialization of the random number generator
    srand((uint)time(NULL));

    // Variables and Arrays
    clock_t start, finish;
    double time;
    int choice, numElements = 10;
    string bookTitle[] = {"Starting out with C++", "Java Programming", "Software Structures", "Design and Analysis of Algorithms", "Computer Graphics", "Artificial Intelligence: A Modern Approach", "Probability and Statistics", "Cognitive Science", "Modern Information Retrieval", "Speech and Language Processing"};
    int bookID[] = {1101, 1211, 1333, 1456, 1567, 1642, 1699, 1755, 1800, 1999};
    double bookPrice[] = {112.32, 73.25, 54.00, 67.32, 135.00, 173.22, 120.00, 42.25, 32.11, 123.75};

    // Call menu function for user to select what they want to do.  Loops back through the menu until the user asks to quit.
    do
    {
        // Call the menu function
        choice = menu();

        // While loop for input validation of the menu selection
        while (choice < 1 || choice > 5)
        {

            // Message informing the user that they have made an invalid selection
            cout << "That is an invalid entry." << endl << endl;
            // Call the menu function again if the user makes an invalid selection
            choice = menu();

        }
        // If Else statement that controls the flow to various funciton calls based on the user's selection
        if (choice == 1)
        {
            // Call to the linear search funciton with a timer to check the execution time of the function
            start = clock();
            linearSearch(bookTitle, bookID, bookPrice, numElements);
            finish = clock();

            time = (double(finish) - double(start))/CLOCKS_PER_SEC;
            // Output line to show how long the function took to execute
            cout << "Time elapsed: " << time << " seconds" << endl << endl;

        }
        else if (choice == 2)
        {
            // Call to the binary search funciton with a timer to check the execution time of the function
            start = clock();
            binarySearch(bookTitle, bookID, bookPrice, numElements);
            finish = clock();

            time = (double(finish) - double(start))/CLOCKS_PER_SEC;
            // Output line to show how long the function took to execute
            cout << "Time elapsed: " << time << " seconds" << endl << endl;

        }
        else if (choice == 3)
        {
            // Call to the bubble sort funciton with a timer to check the execution time of the function
            start = clock();
            bubbleSort();
            finish = clock();

            time = (double(finish) - double(start))/CLOCKS_PER_SEC;
            // Output line to show how long the function took to execute
            cout << endl << endl;
            cout << "Time elapsed: " << time << " seconds" << endl << endl;
        }
        else if (choice == 4)
        {
            // Call to the selectionSort function with a timer to check the execution time of the function
            start = clock();
            selectionSort();
            finish = clock();

            time = (double(finish) - double(start))/CLOCKS_PER_SEC;
            // Output line to show how long the function took to execute
            cout << endl << endl;
            cout << "Time elapsed: " << time << " seconds" << endl << endl;
        }
    }
    while (choice != 5);

    // Output message to indicate to the user that they have exited the program
    cout << "Thank you for searching our inventory! Please come back soon." << endl;

    // End of main function
    return 0;

}

// Menu Function - Called to prompt the user to make a selection
int menu()
{
    int userChoice;

    cout << "Please choose from the following options: " << endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;
    cout << "3. Bubble Sort" << endl;
    cout << "4. Selection Sort" << endl;
    cout << "5. Quit" << endl << endl;

    cin >> userChoice;

    return userChoice;
}

// Display Function - Outputs the bookstore inventory information in a tabular format
void display(string booktitle[], int bookid[], double bookprice[])
{
    cout << setw(42) << "Inventory" << endl;

    for (int x = 0; x < 76; x++)
    {
        cout << "_";
    }

    cout << endl << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << setw(42) << left << booktitle[i] << " " << " Book ID: " <<  bookid[i] << "\t" << " Price: $" << bookprice[i] << endl << endl;
    }
}

// Linear Search Function - The linear search function is passed the bookTitle, bookID, bookPrice arrays and searches through the data linearly based on a user query
void linearSearch(string booktitle[], int bookid[], double bookprice[], int numelements)
{
    int searchID, quantity;
    bool found = false;

    display(booktitle, bookid, bookprice);

    do
    {
        // User Query
        cout << "Please enter the ID of the book you would like to purchase:" << endl;
        cin >> searchID;
        cout << endl;
        cout << "Please enter the quantity:" << endl;
        cin >> quantity;
        cout << endl;

        // Linear search algorithm
        for (int y = 0; y < numelements; y++)
        {
            if (bookid[y] == searchID)
            {
                found = true;
                cout << "Book ID: " << bookid[y] << " Book Title: " << booktitle[y] << " Quantity: " << quantity << " Total Price: $" << (quantity * bookprice[y]) << endl << endl;
            }
        }
    }
    while (found != true);
}

// Binary Search Function - The binary search function is passed the bookTitle, bookID, and bookPrice arrays and performs a binary search on the bookID array based on a user query
void binarySearch(string booktitle[], int bookid[], double bookprice[], int numelements)
{

    int searchID, quantity;
    bool found = false;
    int first = 0;
    int last = numelements - 1;

    display(booktitle, bookid, bookprice);

    // User Query
    cout << "Please enter the ID of the book you would like to purchase:" << endl;
    cin >> searchID;
    cout << endl;
    cout << "Please enter the quantity:" << endl;
    cin >> quantity;
    cout << endl;

    // Binary search algorithm
    do
    {
        int middle = (first + last)/2;
        if (bookid[middle] == searchID)
        {
            found = true;
            cout << "Book ID: " << bookid[middle] << " Book Title: " << booktitle[middle] << " Quantity: " << quantity << " Total Price: $" << (quantity * bookprice[middle]) << endl << endl;
        }
        else if (bookid[middle] > searchID)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    while (found != true);
}

// Bubble Sort Function - This function creates 1000 random numbers, stores them in an array and outputs them.  Then it performs a bubble sort on the array and outputs the array values in ascending order.
void bubbleSort()
{
    int bubbleSortArray[1000];
    bool swap;
    int temp;

    // Input random numbers into the array
    for(int i = 0; i < 999; i++)
    {
        bubbleSortArray[i] = 1 + (rand() % 500);
    }

    // Output the unsorted array
    cout << "Unsorted Array: " << endl;

    for(int x = 0; x < 999; x++)
    {
        cout << bubbleSortArray[x] << " ";
    }

    cout << endl << endl;

    cout << "Sorted Array: " << endl;

    // Bubble sort algorithm
    do
    {
        swap = false;
        for (int y = 1; y < 1000; y++)
        {
            for (int count = 0; count < 999 - y; count++)
            {
                if (bubbleSortArray[count] > bubbleSortArray[count + 1])
                {
                    temp = bubbleSortArray[count];
                    bubbleSortArray[count] = bubbleSortArray[count + 1];
                    bubbleSortArray[count + 1] = temp;
                    swap = true;
                }
            }
        }
    }
    while (swap != true);

    // Output the sorted array
    for(int a = 0; a < 999; a++)
    {
        cout << bubbleSortArray[a] << " ";
    }
}

// Selection Sort Function - This function creates 1000 random numbers, stores them in an array and outputs them.  Then it performs a selection sort on the array and outputs the array values in ascending order.
void selectionSort()
{
    int selectionSortArray[1000];
    int startScan, minIndex, minValue;

    // Input random numbers into the array
    for(int i = 0; i < 999; i++)
    {
        selectionSortArray[i] = 1 + (rand() % 500);
    }

    cout << "Unsorted Array: " << endl;

    // Output the unsorted array
    for(int x = 0; x < 999; x++)
    {
        cout << selectionSortArray[x] << " ";
    }

    cout << endl << endl;

    cout << "Sorted Array:" << endl;

    // Selection sort algorithm
    for (startScan = 0; startScan < 999; startScan++)
    {
        minIndex = startScan;

        minValue = selectionSortArray[startScan];

        for (int index = startScan + 1; index < 1000; index++)
        {
            if (selectionSortArray[index] < minValue)
            {
                minValue = selectionSortArray[index];
                minIndex = index;
            }
        }
        selectionSortArray[minIndex] = selectionSortArray[startScan];
        selectionSortArray[startScan] = minValue;
    }

    // Output the sorted array
    for(int a = 0; a < 999; a++)
    {
        cout << selectionSortArray[a] << " ";
    }

}
