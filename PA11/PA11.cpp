//Name:     Dillon Evans
//Course:   CS 2433
//Date:     March 5th, 2019
//Program:  Program Assignment XI
#include <iostream>
#include <inttypes.h>
#include <math.h>
#include <fstream>
using namespace std;

long long fib(long long n); //The fibonacci function
const int n = 90; //The limit for n for fib(n)
long long memo[n+1]; //Stores results to avoid redundant computation

int main()
{
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;
    fib(n);
    ofstream out("fibSequence.txt");
    
    for (int i = 0; i < n + 1; i++)
    {
        out << "Fib(" << i << ") = " << memo[i] << endl;
        cout << "Fib(" << i << ") = " << memo[i] << endl;
    }
    cout << "\nThe 50th Fibonacci Value is " << memo[50] << endl;
    out.close();
    return 0;
}

//Recursive, memoized fib sequence from F(0) to F(n)
long long fib(long long n)
{
    if (n <= 1)
    {
        return n;
    }
    if (memo[n] != 0)
    {
        return memo[n];
    }
    else
    {
       //fk = f(k - 1) + f(k - 2)
       memo[n] = fib(n - 1) + fib(n - 2);
       return memo[n];
    }
}