// NAME: Stephen McDonald
// Summary: Exercise 7.14 This code simulates a five digit lottery.
// The most difficult aspect of this assignment was making sure to enter the parameters in the function calls as I wrote the functions. 20 minutes wasted checking subfunction code when I should have just been more meticulous.
// It took approximately 90 minutes to write the code.
// 2020-04-12 Revision A

#include <iostream>
#include <cstdlib> // required for random number
#include <ctime> // required for time fuction
using namespace std;

//function prototypes
void generateNumbers(int[], int);
void getUserNumbers(int[], int);
void displayValues(int[], int[], int);
int findMatches(int[], int[], int);

int main()
{
  const int SIZE = 5; //array size
  unsigned seed = time(0); // initializes seed for the random number
  srand(seed); //seed for random number
  int lottery[SIZE];
  int userNumbers[SIZE];
  int matches;

  cout << "Welcome to the Lottery!" << endl;

  generateNumbers(lottery, SIZE);

  getUserNumbers(userNumbers, SIZE);

  displayValues(userNumbers, lottery, SIZE);

  matches = findMatches(userNumbers, lottery, SIZE);

  cout << "\n \n";

  if(matches == 5)
  {
    //grand prize message
    cout << "Congratulations, you win the grand prize!" << endl;
  }
  else
  {
    //consolation message
    cout << "Sorry, you only matched " << matches << " number(s)." << endl;
    cout << "Better luck next time!" << endl;
  }

}

void generateNumbers(int lottery[],int SIZE)
{
  for (int i = 0; i < SIZE; i++)
  {
    lottery[i] = rand() % 10; //mod 10 so we get 9 too

  }
}

void getUserNumbers(int userNumbers[], int SIZE)
{ cout << "Please enter 5 numbers for your lottery choices when prompted." << endl;
  for (int i = 0; i < SIZE; i++)
  {
    cout << "Please enter a number 0-9" << endl;
    cin >> userNumbers[i]; //takes user input
  }
}

void displayValues(int userNumbers[], int lottery[], int SIZE)
{
  cout << "Your numbers were: ";
  for (int i = 0; i < SIZE; i++)
  {
    cout << userNumbers[i] << " ";
  }
  cout << " and the winning numbers were: ";
  for (int i = 0; i < SIZE; i++)
  {
    cout << lottery[i] << " ";
  }
}

int findMatches(int userNumbers[], int lottery[], int SIZE)
{ int matches = 0;
  for (int i = 0; i < SIZE; i++)
  {
    if(userNumbers[i] == lottery[i]) // compared value by value
    {matches++;} //increments matches for a match
  }
  return matches;
}
