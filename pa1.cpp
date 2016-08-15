//  pa1.cpp (Programming Assignment #1, "Magic Squares")
//  Created by Charles "Chandler" Griffin on 2/6/16
//  Turned in February 18th, 2016.

#include "pa1.h"

int main()  {
    double check = 0;
    int size = 0;
    int counter = 0;
    
    //Generally, this while loop checks for valid input and sets the input to size
    while(size < 3 || size > 15 || size%2 == 0)    {
        if(counter > 0)    {
            cout << endl << "Please enter an odd integer between 3 and 15!\n" << endl;
        }
            
        cout << "Enter the size of a magic square: ";
        cin >> check;
        
        //Checking invalid decimal input
        if(floor(check) == ceil(check))    {
            size = (int)check;
        }
        else    {
            size = 0;
        }
        
        //Checking invalid character input    
        if(cin.fail())  {
            cin.clear();
            //numeric_limits<streamsize>::max() to indicate the largest number possible
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        counter++;
    }
    
    //Creating array of pointers
    int** magicSquare = new int *[size];
    
    //Initializing the 2-d array
    for(int i = 0; i < size; i++)   {
        magicSquare[i] = new int[size];
    }
    
    //Setting the base value of each index to 0
    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++) {
            magicSquare[row][col] = 0;
        }
    }
    
    //Printing first magic square
    cout << "Magic Square #1 is:" << endl;
    create(magicSquare, size);
    count(magicSquare, size);
    
    //Printing second magic square
    cout << endl << "Magic Square #2 is:" << endl;
    firstFlip(magicSquare, size);
    count(magicSquare, size);
    
    //Printing third magic square
    cout << endl << "Magic Square #3 is:" << endl;
    secondFlip(magicSquare, size);
    count(magicSquare, size);
    
    return 0;
}

//The create function creates the first magic square.
void create(int** magicSquare, int size)   {
    int mid = (size - 1) / 2;
    int row = 0;
    int col = mid;
    int i = 2;
    //Set first case
    magicSquare[0][mid] = 1;
	
	//Siamese algorithm for odd magic squares
    while(i <= size*size) {
        int iRow = row;
        int iCol = col;
            
        if(col + 1 < size)  {
            col += 1;
        }
        else    {
            col = 0;
        }
            
        if(row - 1 >= 0) {
            row -= 1;
        }
        else    {
            row = size - 1;
        }
            
        if(magicSquare[row][col] == 0)  {
            magicSquare[row][col] = i;
        }
        else    {
            if(iRow + 1 < size)   {
                row = iRow + 1;
            }
            else    {
                row = 0;
            }
            
            col = iCol;
            magicSquare[row][col] = i;
        }
        
        i++;
    }
	
	//Prints Array
    for(int r = 0; r < size; r++)   {
        for(int c = 0; c < size; c++)   {
            cout << magicSquare[r][c] << "\t";
        }
        cout << endl;
    }
}

//The count function prints out the sums of the rows, columns, and diagonals.
void count(int** magicSquare, int size)    {
    int sum = 0;

    cout << "Checking the sums of every row: ";
    
    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++) {
            sum += magicSquare[row][col];
        }
        cout << sum << " ";
        sum = 0;
    }
    cout << endl;
    
    cout << "Checking the sums of every column: ";
    for(int col = 0; col < size; col++) {
        for(int row = 0; row < size; row++) {
            sum += magicSquare[row][col];
        }
        cout << sum << " ";
        sum = 0;
    }
    
    cout << endl;
    
    cout << "Checking the sums of every diagonal: ";
    for(int row = 0; row < size; row++) {
        sum += magicSquare[row][row];
    }
    cout << sum << " ";
    sum = 0;
    
    for(int row = size - 1; row >= 0; row--) {
        sum += magicSquare[row][row];
    }
    cout << sum << " ";
    sum = 0;
    cout << endl;
}

//The firstFlip function creates the second magic square by flipping over the diagonal [0][0] to [size-1][size-1]
void firstFlip(int** magicSquare, int size)  {
    int temp = 0;
    int col = 1;
    int n = 1;
    
    //Flips function over diagonal
    for(int row = 0; row < size; row++) {
        for(col = n; col < size; col++) {
            temp = magicSquare[row][col];
            
            magicSquare[row][col] = magicSquare[col][row];
            magicSquare[col][row] = temp;
        }
        n++;
    }
    
    //Prints Array
    for(int r = 0; r < size; r++)   {
        for(int c = 0; c < size; c++)   {
            cout << magicSquare[r][c] << "\t";
        }
        cout << endl;
    }
}

//The secondFlip function creates the third magic square by inverting the previous case so that the first row is now the last row in reverse order
void secondFlip(int** magicSquare, int size)  {
    int tempRow = 0;
    int tempCol = 0;
    int temp = 0;
    int last = size - 1;
    int col = 0;
    int n = 0;
    
    //Inverts previous 2d array from 0 to half of the size of the array including diagonal indices
    for(int row = 0; row < (size+1)/2; row++) {
        for(col = n; col < size; col++) {
            tempRow = last - row;
            tempCol = last - col;
            
            temp = magicSquare[tempRow][tempCol];
            magicSquare[tempRow][tempCol] = magicSquare[row][col];
            magicSquare[row][col] = temp;
        }
        n++;
    }
    
    n = 1;
    
    //Inverts the rest of the array not looping through diagonal indices
    for(int row = (size+1)/2; row < size; row++) {
        for(col = ((size+1)/2) + n; col < size; col++) {
            tempRow = last - row;
            tempCol = last - col;
            
            temp = magicSquare[tempRow][tempCol];
            magicSquare[tempRow][tempCol] = magicSquare[row][col];
            magicSquare[row][col] = temp;
        }
        n++;
    }
    
    //Prints Array
    for(int r = 0; r < size; r++)   {
        for(int c = 0; c < size; c++)   {
            cout << magicSquare[r][c] << "\t";
        }
        cout << endl;
    }
}




