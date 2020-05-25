// NAME: Stephen McDonald
// Summary: Exercise 5.21 This code random number guessing game. It also keeps track of how many guesses it took the player.
// The most difficult aspect of this assignment was understanding how the random number generator aspects worked, and getting the 'correct' boolean flag to work correctly to exit the loop.
// It took approximately 60 minutes to write the code.
// 2020-03-12 Revision A

#include <iostream>
#include <cstdlib> // required for random number
#include <ctime> // required for time fuction

using namespace std;

int main()

{

  bool correct = false; //declares correct flag
  int guesses = 0, random_number, user_guess; // guess counter and variables for number and user input
  unsigned seed = time(0); // initializes seed for random number
  srand(seed); //seeds random number
  random_number = rand() % 100 + 1; // forces random number between 1 and 100.

  cout << "Please guess a number between 1 and 100: "; //initial prompt
  cin >> user_guess; //initial user guess

  while (correct == false)
  {
    if(user_guess == random_number) //correct guess check
    {
      guesses++; //guess counter
      correct = true; //flips correct flag to true
      break; //makes sure to escape the loop
    }
    else if (user_guess < random_number) // guess lower than answer check
    {
      guesses++; //guess counter
      cout << "Your guess was too low." << endl;
      cout << "Please try again: ";
      cin >> user_guess; //next user input
    }
    else if (user_guess > random_number) // guess greater than answer check
    {
      guesses++; //guess counter
      cout << "Your guess was too high." << endl;
      cout << "Please try again: ";
      cin >> user_guess;  //next user input
    }
  }

cout << "Congratulations, you guessed correctly, the random number was " << random_number << "." << endl; //shows 'victory' message, and actual number
cout << "It took you " << guesses << " guesses." << endl; //displays guess counter

return 0;

}
