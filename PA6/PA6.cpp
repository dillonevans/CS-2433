//Name:     Dillon Evans
//Course:   CS 2433
//Date:     January 29th, 2019
//Program:  Program Assignment VI
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int grade = 60;
	char letter = 'D';
	int count = 0, total = 0;
	int min = 999; int max = 0;
	
	ifstream in("indata6.txt");

	//While the file still has data to pull
	while (!in.eof())
	{	
		in >> grade;
		if (grade >= 0 && grade <= 100)
		{
			switch(grade)
			{
				case 90 ... 100: letter = 'A';
				break;
				case 80 ... 89:  letter = 'B';
				break;
				case 70 ... 79:  letter = 'C';
				break;
				case 60 ... 69:  letter = 'D';
				break;
				default: letter = 'F';
			}
			cout << grade << ": " <<  letter << endl;
			count ++;
			total += grade;
			if (grade > max)
			{
				max = grade;
			}
			if (grade < min)
			{			
				min = grade;
			}
		}
		else
		{
			cout << "Max: " << max << endl;
			cout << "Min: " << min << endl;
			cout << "Average Score: " << total / count << endl;
			cout << "Number of Tests: " << count << endl;
			break; //Terminate the loop on a negative test score
		}
	}
	system("pause");
	return 0;
	
}