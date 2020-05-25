// NAME: Stephen McDonald
// Summary: Exercise 6.24 This code plays Rocks, Paper, Scissors with the end user.
// The most difficult aspect of this assignment was segmenting everything properly into the correct subfucntions and getting the main variables to read the subfunction variables.
// It took approximately 90 minutes to write the code.
// 2020-04-09 Revision A

#include <iostream>
#include <cstdlib> // required for random number
#include <ctime> // required for time fuction
using namespace std;

// function prototypes
int getUserChoice();
int getComputerChoice();
void displayChoice(int);
void determineWinner(int, int);

int main()
{
  //main variables
  unsigned seed = time(0); // initializes seed for the random number
  srand(seed); //seed for random number
  int computerChoice;
  int userChoice;
  int matches;
  int count = 0;

  //begin output
  cout << "Hello! Welcome to Rock, Paper, Scissors!.\n \n" << endl;
  cout << "How many matches would you like to play?" << endl;
  cin >> matches;

  do
  {
    computerChoice = getComputerChoice(); //calls Computer Choice function

    userChoice = getUserChoice(); //calls User Choice subfunctions

    displayChoice(computerChoice); //calls Display function

    determineWinner(userChoice, computerChoice); // calls Winner function

    count++; // increments count variable for do-while loop
  } while(count <= matches);
}

//subfunctions
int getUserChoice()
{
  int fnUserChoice;
  cout << "Please choose:" << endl;
  cout << "\t 1. Rock" << endl;
  cout << "\t 2. Paper" << endl;
  cout << "\t 3. Scissors" << endl;
  cin >> fnUserChoice;
  return fnUserChoice;
}

int getComputerChoice()
{
  int fnComputerChoice;
  fnComputerChoice = rand() % 3 + 1; // forces numbers between 1 and 3
  return fnComputerChoice;
}

void displayChoice(int computerChoice)
{
  if (computerChoice == 1)
  {cout << "The computer chose rock!" << endl;}
  else if (computerChoice == 2)
  {cout << "The computer chose paper!" << endl;}
  else if (computerChoice == 3)
  {cout << "The computer chose scissors!" << endl;}
}

void determineWinner(int userChoice, int computerChoice)
{
  if (userChoice == 1 && computerChoice == 1)
  {
    cout << "A tie! Time for a rematch!" << endl;
  }
  else if (userChoice == 1 && computerChoice == 2)
  {
    cout << "Paper covers rock! Computer wins." << endl;
  }
  else if (userChoice == 1 && computerChoice == 3)
  {
    cout << "Rock smashes scissors! Player wins." << endl;
  }
  else if (userChoice == 2 && computerChoice == 2)
  {
    cout << "A tie! Time for a rematch!" << endl;
  }
  else if (userChoice == 2 && computerChoice == 1)
  {
    cout << "Paper covers rock! Player wins." << endl;
  }
  else if (userChoice == 2 && computerChoice == 3)
  {
    cout << "Scissors cuts paper! Computer wins." << endl;
  }
  else if (userChoice == 3 && computerChoice == 3)
  {
    cout << "A tie! Time for a rematch!" << endl;
  }
  else if (userChoice == 3 && computerChoice == 1)
  {
    cout << "Rock smashes scissors! Computer wins." << endl;
  }
  else if (userChoice == 3 && computerChoice == 2)
  {
    cout << "Scissors cuts paper! Player wins." << endl;
  }
}
