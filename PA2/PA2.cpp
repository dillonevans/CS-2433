//Name:     Dillon Evans
//Course:   CS 2433
//Date:     January 17th, 2019
//Program:  Program Assignment II
#include <iostream>
#include <math.h>
using namespace std;

//Function Prototypes
void circle_arithmetic_cm(double n);
void circle_arithmetic_inches(double n);
void spherical_arithmetic(double inches, double cm);
void square_arithmetic_inches(double n);
void square_arithmetic_cm(double n);
void cubic_arithmetic_inches(double n);
void cubic_arithmetic_cm(double n);
void perform_computations();

//Pi Constant for Geometric Calculations
const double PI = 3.1415926;

//The Main Method
int main()
{
    //Calls the Operations Function for Calculating Geometry
    perform_computations();   
    system("pause");
    return 0;
}

//Carries out the Main Calculations Needed for the Assignment
void perform_computations()
{
    //Measurements used for n
    double nCm = 17.3;
    double nInches = 17.3 / 2.54;
    
    //Circular Arithmetic 
    cout <<"Circular Arithmetic:\n"<< endl;
    circle_arithmetic_cm(nCm);
    circle_arithmetic_inches(nInches);

    //Spherical Arithmetic 
    cout<<"\nSpherical Arithmetic:\n"<<endl;
    spherical_arithmetic(nInches, nCm);

    //Square Arithmetic
    cout<<"\nSquare Arithmetic:\n"<<endl;
    square_arithmetic_cm(nCm);
    square_arithmetic_inches(nInches);

    //Cubic Arithmetic
    cout<<"\nCubic Arithmetic:\n"<<endl;
    cubic_arithmetic_inches(nInches);
    cubic_arithmetic_cm(nCm);
}

//Calculate the Area and Circumference of a Circle in Centimeters
void circle_arithmetic_cm(double n)
{
    double radius = n;
    double area = PI * pow(radius, 2);
    double circumference = 2 * PI * radius;
    cout << "The Circumference of a Circle with a Radius of " << radius << " cm is " << to_string(circumference) << " cm"<< endl;
    cout << "The Area of a Circle with a Radius of " << radius << " cm is " << to_string(area) << " square centimeters"<< endl;
}

//Calculate the Area and Circumference of a Circle in Inches
void circle_arithmetic_inches(double n)
{
    double radius = n;
    double area = PI * pow(radius, 2);
    double circumference = 2 * PI * radius;
    cout << "The Circumference of a Circle with a Radius of " << radius << " inches is " << to_string(circumference) << " inches"<< endl;
    cout << "The Area of a Circle with a Radius of " << radius << " inches is " << to_string(area) << " square inches"<< endl;
}

//Computes the Volume of a Sphere in Inches and Centimeters
void spherical_arithmetic(double inches, double cm)
{
    double radiusInches = inches;
    double radiusCm = cm;
    double volumeInches = 4.0/3.0 * PI * pow(radiusInches, 3);
    double volumeCm = 4.0/3.0 * PI * pow(radiusCm, 3);
    cout << "The Volume of a Sphere with a Radius of " << radiusInches << " inches is " << to_string(volumeInches) << " cubic inches" << endl;
    cout << "The Volume of a Sphere with a Radius of " << radiusCm << " centimeters is " << to_string(volumeCm) << " cubic centimeters" << endl;
}

//Calculate the Area and Permieter of a Square in Inches
void square_arithmetic_inches(double n)
{
    double length = n;
    double width = n;
    double perimeter = (2 * length) + (2 * width);
    double area = length * width;
    cout << "The Area of a Square with a Side Length of " << length << " inches is " << to_string(area) << " square inches"<< endl;
    cout << "The Perimeter of a Square with a Side Length of " << length << " inches is " << to_string(perimeter) << " inches"<< endl;
}

//Calculate the Area and Permieter of a Square in Centimeters
void square_arithmetic_cm(double n)
{
    double length = n;
    double width = n;
    double perimeter = (2 * length) + (2 * width);
    double area = length * width;
    cout << "The Area of a Square with a Side Length of " << length << " centimeters is " << to_string(area) << " square centimeters"<< endl;
    cout << "The Perimeter of a Square with a Side Length of " << length << " centimeters is " << to_string(perimeter) << " centimeters"<< endl;
}

//Calculate the Surface Area and Volume of a Cube in Inches
void cubic_arithmetic_inches(double n)
{
    double length = n;
    double width = n;
    double height = n;
    double surfaceArea = (2 * length * width) + (2 * length * height) + (2 * height * width);
    double volume = length * width * height;
    cout << "The Surface Area of a Cube with a Side Length of " << length << " inches is " << to_string(surfaceArea) << " square inches"<< endl;
    cout << "The Total Volume of a Cube with a Side Length of " << length << " inches is " << to_string(volume) << " cubic inches"<< endl;
}

//Calculate the Surface Area and Volume of a Cube in Centimeters
void cubic_arithmetic_cm(double n)
{
    double length = n;
    double width = n;
    double height = n;
    double surfaceArea = (2 * length * width) + (2 * length * height) + (2 * height * width);
    double volume = length * width * height;
    cout << "The Surface Area of a Cube with a Side Length of " << length << " centimeters is " << to_string(surfaceArea) << " square centimeters"<< endl;
    cout << "The Total Volume of a Cube with a Side Length of " << length << " centimeters is " << to_string(volume) << " cubic centimeters"<< endl;
}

