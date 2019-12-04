//Name:     Dillon Evans
//Course:   CS 2433
//Date:     January 22nd, 2019
//Program:  Program Assignment III
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Prints formatting lines.
void printLines();

//Prints the table of data.
void printTable(string first, string last, string idString, string wageString, string hoursString);

//Prints the table's column headings.
void printHeader();


int main()
{
    ifstream inData;
    ofstream outData;
    string last = " ", first = " ", idString = " ", wageString = " ", hoursString = " ";
    printHeader();
    
    //Open and read data from the file.
    inData.open("indata3.txt");
    while (!inData.eof())
    {
        inData >> first >> last >> idString >> hoursString >> wageString;
        printTable(first, last, idString, wageString, hoursString);
    }
    system("pause");
    return 0;
}

void printLines()
{
    for (int i = 0; i < 107; i++)
    {
        cout <<"-";
    }
    cout << endl;
}

void printHeader()
{
    printLines();
    cout << setw(10) << "First" ;
    cout << setw(10) << "Last";
    cout << setw(9) << "ID";
    cout << setw(14) << "Wage";
    cout << setw(14) << "Hours";
    cout << setw(15) << "Gross Pay";
    cout << setw(17) << "Deductions";
    cout << setw(15) << "Net Pay" << endl;
    printLines();
}

void printTable(string first, string last, string idString, string wageString, string hoursString)
{

    double wage = 0.00, grossPay = 0.00, netPay = 0.00, deductions = 0.00, socialSecurity = 0.0625, tax = 0.17;
    int id = 0, hours = 0;
    wage = stod(wageString);
    id = stoi(idString);
    hours = stoi(hoursString);
        
    //Calculate the Gross and Net Pay, as well as deductions;
    grossPay = (double)hours * wage;
    deductions = (grossPay * tax) + (grossPay * socialSecurity);
    netPay = grossPay - deductions;

    //Display the report for each employee
    cout << setw(10) << first;
    cout << setw(10) << last;
    cout << setw(11) << to_string(id);
    cout << setw(8) << "$" << fixed << setprecision(2) <<  wage  << "\t"; 
    cout << setw(7) << hours; 
    cout << setw(10) <<"$"<< setprecision(2) << grossPay << "\t"; 
    cout << setw(9) << "$" << deductions;
    cout << setw(12) <<"$"<< netPay << "\t"; 
    cout << "\n";
}
