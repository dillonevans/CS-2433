//Name:     Dillon Evans
//Course:   CS 2433
//Date:     March 5th, 2019
//Program:  Program Assignment X
#include <iostream>
#include <fstream>
using namespace std;

//Student class used to instantiate Student objects
class Student
{
    public: 
    double GPA;
    int id;
    string first, last, major;

    //Default student constructor
    Student()
    {
        GPA = 0;
        id = 0000;
        first = " ";
        last = " ";
        major = " ";
    }
    
    //Overloaded Constructor
	Student(string firstName, string lastName, string selectedMajor, int studentID, double studentGPA)
	{
		first = firstName;
        last = lastName;
        major = selectedMajor;
        id = studentID;
        GPA = studentGPA;
	}
    
    //Sets the major of the student
    void setMajor(string newMajor)
    {
        major = newMajor;
    }

    //Sets the GPA of the student
    void setGpa(double newGPA)
    {
        GPA = newGPA;
    }
};

//Creates the Student Node to be implemented in a linked list.
class StudentNode
{
    public: //Specify the access level
    
    //Default Constructor
    StudentNode()
    {
        //Do nothing
    }
    
    //Overloaded Constructor
	StudentNode(Student s, StudentNode* n) 
	{		
		student = s;	
		next = n;
	}
    
    //Returns the next student object of the list
    StudentNode* getNext() 
    {
	    return next;
    }
    
    //Gets the student at the current node of the list
    Student getStudent()
    {
        return student;
    }
    
    //Sets the next student element of the list.
    void setNext(StudentNode* n) 
    {  
	    next = n;	
    }

    private:
	Student student;
    StudentNode *next;
};

//Function Definitions
void add(StudentNode* &head, Student value); 
void print(StudentNode* head);

int main()
{
    ifstream in("indata10.txt");
    StudentNode* head = NULL;
    string majors[5] = {"Computer Science", "Engineering", "Art", "Physics", "Mathematics"};
    string first, last, major;
    double gpa[5] = {1.5, 3.0, 4.6, 0.2, 2.1};
    double GPA;
    int id, r1, r2, integer = 0;

    cout << "The Original Student List:" << endl;
    //While the file still has text to be read
    while(!in.eof())
    {
        in >> first >> last >> id >> major >> GPA; //Read in the data for each student
        cout << first << " " << last << " " << id << " " << major << " " << GPA << endl; //Print the data of the student
        Student student(first, last, major, id, GPA);
        integer++;
        if (integer <= 10)
        {
            //Generate random numbers in order to alter GPA and Major
            r1 = rand() % 4 + 1;
            r2 = rand() % 4 + 1;
            
            student.setGpa(gpa[r1]);
            student.setMajor(majors[r2]);
            add(head, student);
        }

    }
    //Print the linked list starting from the head of the list to the tail
    print(head);
    return 0;
}

//Add a student to the linkedlist
void add(StudentNode* &head, Student value) 
{
	StudentNode* current = head;	

	if (current == NULL) 
	{
		head = new StudentNode(value, NULL);	
		return;
	}
	
	while (current->getNext() != NULL) 
	{
		current = current->getNext();
	}
    current->setNext(new StudentNode(value, NULL));
}	

//Prints each element of the list
void print(StudentNode* head) 
{
	StudentNode* current = head;	
    cout << "\nAltered Student List:" << endl;
	while (current != NULL) //While the current position of the list has a node 
	{
        Student temp = current->getStudent();		
		cout << temp.first << " " << temp.last << " " << temp.id << " " << temp.major << " " << temp.GPA <<  "\t" << endl;
		current = current->getNext();
	}
	cout << endl;
}
