// NAME: Stephen McDonald
// Summary: Exercise 4.23 This code is meant to create a menu of geometry formulae, allow the user to select a formula, input values, and then calculate the formula; also to quit the program.
// The most difficult aspect of this was deciding the way to approach the menu feature, as it can be done multiple ways, either with do-while loops or switch statements.
// I opted for switch statements because those are more germane to Chapter 4.
// It took approximately 45 minutes to write the code.
// 2020-03-10 Revision A

#include <iostream>
using namespace std;

int main()

{
int choice = 0;

// prints opening menu:
cout << "Geometry Calculator" << endl;
cout << "\t1. Calculate the Area of a Circle." << endl;
cout << "\t2. Calculate the Area of a Rectangle." << endl;
cout << "\t3. Calculate the Area of a Triangle." << endl;
cout << "\t4. Quit." << endl;
// end of menu
cout << "\n \n Please enter your choice (1, 2, 3, or 4): "; //prompts user for choice
cin >> choice; //assigns user input to choice variable

// switch statement based on user input:
switch(choice)
  {
    case 1:
      {
        cout << "Circle:" << endl;
        double radius;
        cout << "Please enter the radius of your circle: " << endl; //prompt for radius
        cin >> radius; // assigns user input
          if (radius > 0) //tests for positive radius
          {
            double area, pi = 3.14159; //declares formula variables, assigns value to pi
            area = pi * radius * radius; //area calculuation
            cout << "The area of your circle is " << area << endl;
          }
          else
          {
            cout << "Your input is invalid, please try again." << endl; //error message for invalid radius value
          }
      } break;
    case 2:
      {
        cout << "Rectangle:" << endl;
        double length, width;
        cout << "Please enter the length of your rectangle: " << endl; // prompt for length
        cin >> length; // reads in length
        cout << "Please enter the width of your rectangle: " << endl; // prompt for width
        cin >> width; // reads in width
          if (length > 0 && width > 0) //test for positive length/width
          {
            double area = length * width; // area calculation
            cout << "The area of your rectangle is " << area << endl;
          }
          else
          {
            cout << "One or more of your inputs is invalid, please try again." << endl; //error message for invalid length/width
          }
      } break;
      case 3:
        {
          cout << "Triangle:" << endl;
          double base, height;
          cout << "Please enter the base of your triangle: " << endl; // prompt for base
          cin >> base; // reads in base
          cout << "Please enter the height of your triangle: " << endl; // promppt for height
          cin >> height; // reads in height
            if (base > 0 && height > 0) //test for positive base/height
            {
              double area = base * height * 0.5; // area calculation
              cout << "The area of your triangle is " << area << endl;
            }
            else
            {
              cout << "One or more of your inputs is invalid, please try again." << endl; //error message for invald base/height
            }
        } break;
        case 4:
          {
            cout << "Goodbye!" << endl; //goodbye message
            return 0;
          }
        default:
          {
            cout << "Your choice must be either 1, 2, 3, or 4." << endl; // error message for invalid menu input
            cout << "Please try again." << endl;
          }
  }
}
