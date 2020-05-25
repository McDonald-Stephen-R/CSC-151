// NAME: Stephen McDonald
// Summary: Exercise 2.17 This code is meant to calculate stock price and commission.
// The most difficult aspect of this was finding out how to get C++ installed and which IDE worked on a Macbook.
// It took approximately 20 minutes to write the code.
// 2020-02-03 Revision A

#include <iostream>
using namespace std;

int main()
{
  // declaring variables
  int shares = 750;
  double price = 35.00, commission_pct = 0.02, total, commission, total_with_commission;

  //mathematical calculations
  total = shares * price; // calculates total price of shares
  commission = total * commission_pct; // calculates stockbroker's commission
  total_with_commission = total + commission; // sums value of stock and commission

  // print statement of solution
  cout << "Kathryn paid $" << total << " for the shares of stock and $" << commission << " to the stockbroker" << " for a total of $" << total_with_commission << ".";

  return 0;
}
