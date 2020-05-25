// NAME: Stephen McDonald
// Summary: Final Project - Theatre Menu
// The most difficult aspect of this was the scope of the project as well as working with two-dimensional arrays.
// It took approximately 7 hours in total to write the code.
// 2020-04-17 Revision A - Constants, Function Prototypes, Do-While Loop for main loop
// 2020-04-20 Revision B - Functions and Arrays
// 2020-04-30 Revision C - Testing and Documentation
// 2020-05-08 Final Revision - Cleanup and Header

/*
Code Header:
Test Scenario
  1. On open, press 1 to display seats and ensure all display the '#'' symbol.
  2. Press 2 to display prices. If using included prices.txt files, Row 1-5 are $8.00, Rows 6-10 are $10.00 and Rows 11-15 are $12.00.
  3. To check three, make a change to prices.txt; for example, change the first entry to 9.00 and then use function #3.
  4. Purchase tickets (#4) for Seats 1-1, 6-1, and 11-1.
  5. This should result in total sales of $30.00 for function #5 (or $31.00 if you changed Row 1's price).
  6. Check function 1 again to ensure Seats 1-1, 6-1, and 11-1 now read taken, i.e. '*'.
  7. Check quit function to quit.
*/



#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

// constant declaration
const int NUMROWS = 15; //theatre has 15 rows
const int NUMCOLS = 30; //theatre has 30 seats per row
const char SEATTAKEN = '*'; //seat taken
const char SEATEMPTY = '#'; //seat available


//prototypes
void displayMenu();
int getChoice();
void displaySeats(char [][NUMCOLS]);
void displayPrices(double[]);
void updatePrices(double[]);
void displaySales(double);
void purchaseTicket(char[][NUMCOLS], double[], double&);

int main()
{
  //initial run of program lists all seats as SEATEMPTY
  char seatArray[NUMROWS][NUMCOLS];
  for (int i = 0; i < NUMROWS; i++)
  {
    for (int j = 0; j < NUMCOLS; j++)
    {
      seatArray[i][j] = SEATEMPTY;
    }
  }

  //set initial price list
  double priceList[NUMROWS];
  updatePrices(priceList);

  //start sales at zero
  double totalSales = 0;
  int choice; //user input variable

    do
    {
        displayMenu(); //calls menu function
        cin >> choice; //user input for switch statement

        switch(choice) //cases per menu option numbers
        {
            case 1:
              {
                displaySeats(seatArray);
                break;
              }
            case 2:
            {
              displayPrices(priceList);
              break;
            }
            case 3:
              {
                updatePrices(priceList);
                break;
              }
            case 4:
              {
                purchaseTicket(seatArray, priceList, totalSales);
                break;
              }
            case 5:
              {
                displaySales(totalSales);
                break;
              }
            case 6:
              {
                choice = 6;
                break;
              }
        }
    } while(choice != 6); //quits if user enters 6
}


// function to display main menu
void displayMenu()
{
  cout << "Theatre Menu:"<<endl;
  cout << "-----------------------------------------" << endl;
  cout << "\t1. View Available Seats" << endl;
  cout << "\t2. View Seating Prices" << endl;
  cout << "\t3. Update Seating Prices" << endl;
  cout << "\t4. Purchase a Ticket" << endl;
  cout << "\t5. View Total Ticket Sales" << endl;
  cout << "\t6. Quit" << endl;
  cout << "-----------------------------------------" << endl;
  cout << endl;
  cout << "Please enter a choice (1-6): ";
}

// displays seating chart
// n.b. the formatting is still somewhat janky, working on a solution
void displaySeats(char seatArray[][NUMCOLS])
{
  cout << "Seat    ";
  for(int i = 0; i < NUMCOLS; i++)
  {
    cout << i+1 << " - ";
  }
  cout << endl;
  for(int j = 0; j < NUMROWS; j++)
  {
    cout << "Row " << j+1 << ":  ";
    for (int k = 0; k < NUMCOLS; k++)
    {
      cout << seatArray[j][k] << " - ";
    }
    cout << endl;

  }
  cout << endl;
  cout << endl;
}


// function to display prices to the user
void displayPrices(double priceList[])
{
    cout << "Row" << "\t" <<"Price"<< endl; //prints header
    cout << "----------------------" << endl; //
    for(int i = 0; i < NUMROWS; i++)
    {
      cout<<"Row " << i+1 << "\t" << "$" << fixed << setprecision(2) << priceList[i] << endl; //output with $ formatting
    }
      cout << endl;
      cout << endl;
}

// function to update price array and the text file
void updatePrices(double priceList[])
{
  ifstream input;
  input.open("prices.txt");
  for (int k = 0; k < NUMROWS; k++)
  {
    input >> priceList[k];
  }
  input.close();
}

//this function displays total sales figures since the file was opened
void displaySales(double totalSales)
{
    cout << "Total sales are: $" << fixed << setprecision(2) << totalSales << endl;
    cout << endl;
}

//function for purchasing tickets and
void purchaseTicket(char seatArray[][NUMCOLS], double priceList[], double& totalSales)
{
  string flagLoop; //flag to loop
  int userRow, userCol; //holders for input

  cout << "Enter row number (1-15): ";
  cin >> userRow; //user row input

    // ensures correct row number
    while(userRow < 1 || userRow > 15)
    {
        cout << "Invalid row number selected." << endl; //error message
        cout << "Please try again: ";
        cin >> userRow;
    }
    cout << "Please seat number (1-30): ";
    cin >> userCol; //user seat input

    // ensures correct seat (column) number
    while(userCol < 1 || userCol > 30)
    {
        cout << "Invalid seat number selected." << endl; //error message
        cout << "Please try again: ";
        cin >> userCol;
    }
    // check for seat availability
    if(seatArray[userRow-1][userCol-1] == SEATTAKEN)
    {
        cout << "Sorry! That seat is already booked." << endl;
        purchaseTicket(seatArray, priceList, totalSales); //calls function again, attempt for a valid seat
    }
    // else book the seat and display the price
    else
    {
        seatArray[userRow-1][userCol-1] = SEATTAKEN; //reserves seat in char array
        cout << "Your seat has been reserved" << endl;
        double soldSeat = priceList[userRow-1]; //placeholder for seat cost
        cout << "The cost of the ticket is: $" << setprecision(2) << priceList[userRow-1] << endl; //displays ticket cost
        cout << endl;
        totalSales = totalSales + soldSeat; //adds price to total sales
        soldSeat = 0; // resets placeholder for seat price
        cout << "Would you like to reserve another seat? Please select (Y/N): "; //loop question
        cin >> flagLoop; // loop input

        if(flagLoop == "y" || flagLoop == "Y")
        {
          purchaseTicket(seatArray, priceList, totalSales); //calls function again if user wants
        }
    }

}
