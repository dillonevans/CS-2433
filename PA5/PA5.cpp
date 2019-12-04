//Name:     Dillon Evans
//Course:   CS 2433
//Date:     February 12th, 2019
//Program:  Program Assignment V
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


void printLines();
void print();

double calculateAmount(double denomination, int amount);

ofstream out;

int main()
{
	print();
	system("pause");
	return 0;
}

void printLines()
{
	
	for (int i = 0; i < 50; i++)
	{
		cout << "-";
		out << "-";
	}
	cout << endl;
	out << endl;
}

double calculateAmount(double denomination, int amount)
{
	return denomination * amount;
}

void print()
{
	double denomination = 0, amount = 0, sum = 0;
	int number = 0;
	out.open("outdata.txt");
	
	ifstream in;
	in.open("indata5.txt");
	
	cout << "Denomination" << setw(15) << "Number" << setw(20) << "Amount" << endl;
	out << "Denomination" << setw(15) << "Number" << setw(20) << "Amount" << endl;
	printLines();
	while (!in.eof())
	{
		in >> denomination>> number;
		amount = calculateAmount(denomination, number);
		sum += amount;
		cout << fixed << setprecision(2) << setw(5) << denomination << setw(20) << number << setw(22) << amount << endl;
		out << fixed << setprecision(2) << setw(5) << denomination << setw(20) << number << setw(22) << amount << endl;
	}
	printLines();
	
	cout << "Total" << setw(35) << "$" << sum << endl;
	out << "Total" << setw(35) << "$" << sum << endl;
	out.close();
	in.close();
	
	
}