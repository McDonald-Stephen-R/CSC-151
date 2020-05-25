// NAME: Stephen McDonald
// Summary: Exercise 3.20 This code is meant to calculate the area and then slices of pizza.
// The most difficult aspect of this was finding out how to get C++ installed and which IDE worked on a Macbook. (Done concurrently with P2.17)
// It took approximately 20 minutes to write the code.
// 2020-02-03 Revision A

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
  // declaring constants
  const double pi = 3.14159;
  const double slice_area = 14.125;

  // initializing variables
  double diameter, radius, area, slices;

  // user input
  cout << "What diameter pizza does the customer want? ";

  // assigning user input to variable
  cin >> diameter;

  //mathematical calculations
  radius = diameter / 2.0; // finds radius
  area = pi * pow(radius, 2.0); // area calculation 
  slices = area / slice_area; // slice calculation

  // print statement of solution
  cout << "A pizza of diameter " << diameter << " inches can be cut into " << setprecision(2) << showpoint << slices << " slices.";

  return 0;
}
