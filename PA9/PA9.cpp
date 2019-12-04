//Name:     Dillon Evans
//Course:   CS 2433
//Date:     March 5th, 2019
//Program:  Program Assignment IX
#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
#include <algorithm>
using namespace std;

//The struct used for student objects
struct Student
{
    string firstName = " ", lastName = " ", state = " ", homeTown = " ", major = " ";
    int year = 0;
   
    bool operator () (const Student& a, const Student& b) 
    {
        return a.lastName > b.lastName;
    }
};


int main()
{
    ifstream in("indata9.txt");
    ofstream out("out.txt");
    string firstName = " ", lastName = " ", state = " ", homeTown = " ", major = " ", line;
    int year, index;
    Student students[18];
    index = 0;

    while (!in.eof()) //While the file is still being read, extract data
    {
        in >> firstName >> lastName >> homeTown >> state >> year >> major;
        Student s = {firstName, lastName, state, homeTown, major, year};
        Student newStudent = s;
        s.major = major;
        students[index] = s;
        index++;
    }
   
    int n = sizeof(students)/sizeof(students[0]); 
    sort(students, students + n, Student()); //Sort the students by last name
    
    for (Student s : students) //For each Student object in the array, print to the file and screen
    {
        out << s.lastName << ", " << s.firstName << ", " << s.homeTown << ", " << s.state << ", " << s.major << ", " << s.year << endl;
        cout << s.lastName << ", " << s.firstName << ", " << s.homeTown << ", " << s.state << ", " << s.major << ", " << s.year << endl;
    }
    return 0;
}
