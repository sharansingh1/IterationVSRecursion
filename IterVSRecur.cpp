#include <iostream>
using namespace std;

/*NAME BLOCK
Name: Sharanjeet Singh and Miguel Comonfort
Lab 01, Team 10
Purpose:To show the difference of iteration vs recursion, using botht o check if an array is prime or not
*/

/*
Pre: element - value to be checked if its prime
     i - number between 1 and element used to see if element is prime
Post: "Entering isPrimeRecur" and "Leaving isPrimeRecur"
Return: true or false

Psuedocode:
IsPrimeRecur(int element, int i = 2)

print the enter statement
element == 1:
make the base cases of 1 and return false with exit code
element == 2:
make base case of 2 and return true with exit code

(element % i == 0):
check if element is prime by seeing remainder and returning  true with exit code

element % i == 0:
check if element is less that i squared and print exit code with return true

apply recursion:
IsPrimeRecur(element, i + 1); 
incrementing the the number to be compared with element


*/
bool IsPrimeRecur(int element, int i = 2)
{
    cout << "Entering isPrimeRecur\n ";
    //set base cases 
    if (element == 1)         // end program if 1 because not prime
    {
        cout << "Leaving isPrimeRecur\n ";
        return false;
    }
    if (element == 2)         // end program if 2 because thats starting value
    {
        cout << "Leaving isPrimeRecur\n ";
        return true;
    }
    if (element % i == 0)         //compare element with number between it and 1 
    {
        cout << "Leaving isPrimeRecur\n ";
        return false;
    }
    if (i * i > element)      //compare if i squared is bigger than element
    {
        cout << "Leaving isPrimeRecur\n ";
        return true;
    }
    //comment exit code and do recursion, increment the element
    cout << "Leaving isPrimeRecur\n "; 
    return IsPrimeRecur(element, i + 1);
}

/*
Pre: array - array of elements chosen by user
    arraysize - size of array chosen by the user
Post: "Entering IsArrayPrimeRecur" and "Leaving IsArrayPrimeRecur"
Return: true or false

Psuedocode:
isArrayPrimeRecur(int* array, int arraysize)
arraysize == 0:
make base case and return true with exit code

IsPrimeRecur() == true:
call the IsPrimeRecur to check if the number is prime, starting with end of array and going back

return isArrayPrimeRecur();:
do recursion and go down the array from end to front

print exit code and return false


*/
bool isArrayPrimeRecur(int* array, int arraysize)
{
    cout << "Entering IsArrayPrimeRecur\n";
    //base case end if size is 0
    if (arraysize == 0)
    {
        cout << "Leaving IsArrayPrimeRecur\n";
        return true;
    }
    //call other function to see if prime and do recursion, decrement
    if ((IsPrimeRecur(array[arraysize - 1]) == true))
    {
        return isArrayPrimeRecur(array, arraysize - 1);
    }

    //comment exit code
    cout << "Leaving IsArrayPrimeRecur\n";
    return false;
}

/*
Pre: array - array of elements chosen by user
    arraysize - size of array chosen by the user
Post: "Entering isArrayPrimeIter" and "Leaving isArrayPrimeIter"
Return: true or false

Puedocode:
 IsArrayPrimeIter(int *array, int arraysize)

 outerloop:
 iterate through array and show 1 is not prime

 innerloop iterate from numbers between 1 and the element in array 
 check if there is remainder
 if remainder then not prime

 return true or false accordingly with exit code

*/
bool IsArrayPrimeIter(int *array, int arraysize)
{
//print enter message
    cout << "Entering isArrayPrimeIter\n ";
//loop through array
    for (int i = 0; i < arraysize; i++)
    {
        if (array[i] == 1)      //make sure 1 is not prime 
        {
            cout << "Leaving isArrayPrimeIter\n ";
            return false;
         }
        for (int j = 2; j < array[i]; j++)      //nexted loop from values between 1 and element
        {
            if (array[i] % j == 0) //if no remainder than it is not prime
            {
                // cout << "notprime";
                cout << "Leaving isArrayPrimeIter\n ";
                return false;
            }
        }
        //cout << "prime";
        //print exit message
        cout << "Leaving isArrayPrimeIter\n ";
       
    }
    return true;

}


int main()
{
    //declare variables 
    const int SORT_MAX_SIZE = 16;
    int arraysize;
    
    //prompt user for array size and elements
    cout << "Enter the size of the array:\n";
    cin >> arraysize;
    //check if arraysize is too large
    if (arraysize > SORT_MAX_SIZE)
    {
        cout << "Size is too large" << endl;
        exit(0);
    }
    
    int* array = new int[arraysize];    //make array with user size
    cout << "Enter the elements of the array:\n";

    for (int i = 0; i < arraysize; i++)   //use for loop to add needed amount of elements
    {
        cin >> array[i];
        //check if elements are within limit
        if (array[i] > 9999 || array[i] < 1)
        {
            cout << "Element is outside of range" << endl;
            exit(0);
        }

    }

    
    //call primary iter func and pass array and size
    //print message if array is prime or not using iter
     if (IsArrayPrimeIter(array, arraysize) == true)
     {
         cout << "Prime Array using iteration \n";
     }
     else
     {
         cout << "Not a Prime Array using iteration\n";
     }
     //call primary recur func and pass array and size
    //print message if array is prime or not using recur
     if (isArrayPrimeRecur(array, arraysize) == true)
     {
         cout << "Prime Array using recursion\n";
     }
     else
     {
         cout << "Not a Prime Array using recursion\n";
     }
    
   
   //delete memory
    delete[] array;
    //add pause
    system("pause");
}


