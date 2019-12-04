//Name:     Dillon Evans
//Course:   CS 2433
//Date:     January 29th, 2019
//Program:  Program Assignment VIII
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>
#include <set>
using namespace std;

/**
 * Performs the selection sort algorithm for 
 * the passed array.
 */
void selectionSort(int array[], int n); //Protoype

/**
 * Populates the passed Array with 
 * unique numbers ranging from 1 to 1000.
 */
void populate(int array[], int n); //Prototype

/**
 * Prints the Sorted Array to an Outfile 
 * and States Whether or not the number 
 * 13 is present
 */
void print(int array[], int n); //Prototype
const int N = 50;
int main()
{
    
    int nums [N];
    populate(nums, N);
    selectionSort(nums, N);
    print(nums, N);    
    system("pause");
    return 0;  
}

void selectionSort(int array[], int n) //Definition for selctionSort method
{
    int j = 0, i = 0, min = 0;

    //Sorts the array from 0 to n
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        j = i+1;

        for (j = i+1; j < n; j++)
        {
            //If the j position is less than the minimum, min assumes its value.
            if (array[j] < array[min])
            {
                min = j;
            } 
        }
        //Swap the minimum array value with the current i position
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

void populate(int nums[], int n) //Definition for populate method
{
    set<int> mySet;
    int index = 0;
    
    //Allows for randomly generated numbers to change on each execution
    srand(time(0));

    //Generates 50 distinct random integers and inserts them into the set
    while (mySet.size() < n)
    {
        mySet.insert(rand() % 1000 + 1);
    }

    //Populates the Array with Numbers Generated
    for (int i : mySet)
    {
        nums[index] = i;
        index++;
    }
}

//Print the results
void print(int nums[], int n) 
{   
    bool found = false;
    int num = 0;
    ofstream out;
    out.open("output.txt");

    //Search the Nums[] Array for the number 13 and prints the sorted array.
    for (int i = 0; i < n; i++)
    {
        num = nums[i];
        if (num == 13)
        {
            found = true;
        }
        out << num;
        cout << num;
        
        //Appends a new line or a comma for formatting purposes
        if (i % 10 == 0 && i > 0)
        {
            out << "\n";
            cout << "\n";
        }
        else
        {
            if (i!= n - 1 )
            {
                out << ", ";
                cout << ", ";
            }
        } 
    }

    //States whether or not the number 13 is present in the array and prints the result
    if (found)
    {
        out << "\n" << "The number 13 is present " << endl;
        cout << "\n" << "The number 13 is present " << endl;
    }
    else
    {
        out << "\n" << "The number 13 is not present " << endl;
        cout << "\n" << "The number 13 is not present " << endl;
    }
}