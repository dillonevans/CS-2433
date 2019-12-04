//Name:     Dillon Evans
//Course:   CS 2433
//Date:     March 5th, 2019
//Program:  Program Assignment VII
#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;


double computeJDN(int month, int day, int year);

string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "July", "Aug", "Sep", "Oct", "Nov", "Dec"};
string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


int main()
{
	ifstream in;	
	
	in.open("indata7.txt");
	
	//Computes the JDN
	int month = 0, day = 0, year = 0;
	while (in.eof() != true)
	{
		in >> month >> day >> year;
		double JDN = floor(computeJDN(month, day, year));
		JDN += 1;
		int DayOfWeek = (int(JDN) + 1) % 7;		
		cout << months[month - 1] << " " << day << " " << year << " was a " << days[DayOfWeek] << endl;

	}	
}


//Computes and returns the Julian Day for a given date.
double computeJDN(int month, int day, int year)
{
	double intRes1 = 0, intRes2 = 0, intRes3 = 0;	
	
	//Determines which calculation to use for the 
	//first intermediate result depeneding on 
	//the year.
	if (year > 1582)
	{
		intRes1 = 2 - year / 100 + year / 400;
	}
	else 
	{
		if (year == 1582 && day > 15 && month > 10)
		{
			intRes1 = 2 - year / 100 + year / 400;
		}
		else if (year == 1582 && day < 15 && month <= 10)
		{
			intRes1 = 0;
		}
		else
		{
			intRes1 = 0;
		}
	}
	
	//Calculates the second and third intermediate computations.
	intRes2 = static_cast<int>(365.25 * year);
	intRes3 = static_cast<int>(30.6001 * (month + 1));

	//Computes the JDN given the intermediate calculations.
	double JDN = intRes1 + intRes2 + intRes3 + day + 1720994.5;
	return JDN;
}
