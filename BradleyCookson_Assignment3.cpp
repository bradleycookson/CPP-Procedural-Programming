/* Author: Bradley Cookson
   Date: 11-3-15
   Description: A magic square is a matrix where the sum of the elements in each of the rows, columns, and
   diagonals are all the same. The purpose of this program is to fill a two dimensional array with unique
   random variables until a magic square is created. The program will output each two dimensional array that
   is created and will state whether the program is a magic square or not.

   Pseudocode: 1. Create 3 x 3 two-dimensional array and initialize it to zero
               2. Generate random numbers and assign them to the array, but first check to make sure each
                  one is unique by calling a checkUnique function
                    a. The checkUnique function should return a bool value that is true if the value is already
                       included in the array and false if it is unique
               3. Output the array once it is filled with unique values
               4. Check to see if the array is a magic square by calling a function called magicSquare.
                  Output a message that states whether each array is a magic square or not
                    b. The magicSquare function should return a bool value that is false if the sum of
                       the diagonals, rows, or columns are not all equal.  Otherwise, it will return true.
               5. Loop through the program until a magic square is generated
               6. Once a magic square is generated, end the program
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Function prototypes

bool checkUnique(int a[][3], int r);
bool magicSquare(int a[][3]);

int main()
{

    srand((uint)time(NULL));

    //Declare a 3 x 3 array

    int magicArray[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    int random, i, j, x, y;

    //Fill the 3 x 3 array with unique random values

    do
    {

        //Zero out the array with each loop iteration

        for (i = 0; i < 3; i++)
        {

            for (j = 0; j < 3; j++)
            {

                magicArray[i][j] = 0;

            }

        }

        //Assign unique random values to the array

        for (i = 0; i < 3; i++)
        {

            for (j = 0; j < 3; j++)
            {

                do
                {

                    random = 1 + (rand() % 9);

                }
                while (checkUnique(magicArray, random));

                magicArray[i][j] = random;

            }

        }

        // Output the 3 x 3 array in the form of a square

        for (x = 0; x < 3; x++)
        {

            for (y = 0; y < 3; y++)
            {

                cout << magicArray[x][y] << " ";

            }

            cout << endl;

        }

        // Check if the array creates a magic square or not by calling the magicSquare funciton

        if (!magicSquare(magicArray))
        {

            cout << "Not a Magic Square! \n";

        }

    }
    while (!magicSquare(magicArray));

    // Ouput that the program found a magic square

    cout << "The program created a Magic Square! \n";

    // End of Main Function

    return 0;

}

//Function of type bool that returns true if the random value generated is unique before assigning it to the magicArray

bool checkUnique(int a[][3], int r)
{

    bool included = false;
    int i, j;

    for (i = 0; i < 3; i++)
    {

        for (j = 0; j < 3; j++)
        {

            //Check if an element is equal to the random value

            if (a[i][j] == r)

                included = true;

        }


    }

    return included;

}

//Function of type bool that returns true if the array is a magicSquare

bool magicSquare(int a[][3])
{

    //Check the sum of the first diagonal

    int sumDiagonals = 0, row, col;

    for (row = 0; row < 3; row++)
    {

        for (col = 0; col < 3; col++)
        {

            if (row == col)
            {

                sumDiagonals += a[row][col];


            }

        }

    }

    //Check the sum of the second diagonal against the sum of the first diagonal

    if (a[0][2] + a[1][1] + a[2][0] != sumDiagonals)
    {

        return false;

    }

    //Check the sum of the rows

    for (row = 0; row < 3; row++)
    {

        int sumRows = 0;

        for (col = 0; col < 3; col++)
        {

            sumRows += a[row][col];

        }

        if (sumDiagonals != sumRows)
        {

            return false;

        }

    }

    //Check the sum of the columns

    for (row = 0; row < 3; row++)
    {

        int sumColumns = 0;

        for (col = 0; col < 3; col++)
        {

            sumColumns += a[col][row];

        }

        if (sumDiagonals != sumColumns)
        {

            return false;

        }

    }

    //The function returns true if the array is a magic square

    return true;

}
