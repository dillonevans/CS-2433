//Name:     Dillon Evans
//Course:   CS 2433
//Date:     January 29th, 2019
//Program:  Program Assignment IV
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Reads data from the input file, prints to the out file, and displays data from both
void print(); //Prototype

int main()
{
    print();
    system("pause");
    return 0;

}

void print()
{
    ifstream in;
    ofstream out;
    string first = " ", last = " ";
    string line = " ";
     
    //Opens the Input and Output Files
    in.open("indata4.txt");
    out.open("outdata4.txt");
    
    /**
     * Reads and Prints Data from the Input File, and writes to the Output while the current line
     * still has text 
     */
    cout << "In File Contents: " << endl;
    while (!in.eof())
    {
        in >> first >> last;
        cout << first << " " << last << endl;
        out << last << ", " << first << endl;
    }
    in.close();
    out.close();
    in.open("outdata4.txt");

    /**
     * Reads and Prints Data from the Output File while the current line
     * still has text 
     */    
    cout << "\nOut File Contents: " << endl;
    while (getline(in, line))
    {
        cout << line << endl;
    }
    in.close();
}