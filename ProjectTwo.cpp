//============================================================================
// Name        : ProjectTwo.cpp
// Author      : Antonio Bethune
//============================================================================

#include <iostream>
using namespace std;
#include "Data.h"


int main() {

	//sets up the variables to be used to store the user inputs for their data and application flow
	double iI;
	double mD;
	double aI;
	int nY;
	string check = "y";
	string pressed;


	//Prints out the format the user must follow showing them what data they will enter
	cout << "**Data Input Format**" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;
	cout << "Press any key then enter to start inputing values: " << endl;

	cin >> pressed;
	cout << "----------------------------"<<endl;

	//This block goes through each of the data entries, ensurung that the user enters a valid entry and then stores it in the aforementioned variables
	cout << "**Data Input**" << endl;
	cout << "Initial Investment Amount: " << endl;
	while (1) {
	  if (cin >> iI) {
	      // valid number
	      break;
	  } else {
	      // not a valid number
	      cout << "Invalid Input! Please input a double value." << endl;
	      cout << "Initial Investment Amount: " << endl;
	      cin.clear();
	      while (cin.get() != '\n') ; // empty loop
	  }
	}
	cout << "Monthly Deposit: " << endl;
	while (1) {
	  if (cin >> mD) {
	      // valid number
	      break;
	  } else {
	      // not a valid number
	      cout << "Invalid Input! Please input a double value." << endl;
	      cout << "Monthly Deposit: " << endl;
	      cin.clear();
	      while (cin.get() != '\n') ; // empty loop
	  }
	}
	cout << "Annual Interest: " << endl;
	while (1) {
	  if (cin >> aI) {
	      // valid number
	      break;
	  } else {
	      // not a valid number
	      cout << "Invalid Input! Please input a double value." << endl;
	      cout << "Annual Interest: " << endl;
	      cin.clear();
	      while (cin.get() != '\n') ; // empty loop
	  }
	}
	cout << "Number of years: " << endl;
	while (1) {
	  if (cin >> nY) {
	      // valid number
	      break;
	  } else {
	      // not a valid number
	      cout << "Invalid Input! Please input an integer value.\n"
	    	   <<"(Note if you put in a double value it will be rounded down)" << endl;
	      cout << "Number of years: " << endl;
	      cin.clear();
	      while (cin.get() != '\n') ; // empty loop
	  }
	}

	//Makes an instance of the Data class that contains the manipulation of the users data
	Data userData (iI, mD, aI, nY);


	//Shows the user the current data that they inputed
	cout << "**Data Input**" << endl;
	cout << "Initial Investment Amount: "<< userData.getInitialInvestment() << endl;
	cout << "Monthly Deposit: " << userData.getMonthtlyDeposit() << endl;
	cout << "Annual Interest: " << userData.getAnnualIntrest() << endl;
	cout << "Number of years: " << userData.getNumYears() << endl;

	//Prints out a chart of the users data in a chart form
	printData(userData);


	//This loop allows the user to change set parts of their previous data one at a time or terminates the program if not
	while (check == "y"){
		cout << "Would you like to edit a value? (y for yes OR any other entry will terminate the program)" << endl;
		cin >> check;
		if(check != "y")
			break;
		string change;
		cout << "Which value would you like to edit?\n"
				<< "i = Initial Deposit\n"
				<< "m = Monthly Deposit\n"
				<<"a = Annual Interest\n"
				<< "y = Number of Years"<< endl;
		cin >> change;

		if(change == "i"){
			cout << "Initial Investment Amount: " << endl;
			while (1) {
			  if (cin >> iI) {
			      // valid number
			      break;
			  } else {
			      // not a valid number
			      cout << "Invalid Input! Please input a double value." << endl;
			      cout << "Initial Investment Amount: " << endl;
			      cin.clear();
			      while (cin.get() != '\n') ; // empty loop
			  }
			}
			userData.setInitialInvestment(iI);
		}
		else if(change == "m"){
			cout << "Monthly Deposit: " << endl;
			while (1) {
			  if (cin >> mD) {
			      // valid number
			      break;
			  } else {
			      // not a valid number
			      cout << "Invalid Input! Please input a double value." << endl;
			      cout << "Monthly Deposit: " << endl;
			      cin.clear();
			      while (cin.get() != '\n') ; // empty loop
			  }
			}
			userData.setmonthtlyDeposit(mD);

		}
		else if(change == "a"){
			cout << "Annual Interest: " << endl;
			while (1) {
			  if (cin >> aI) {
			      // valid number
			      break;
			  } else {
			      // not a valid number
			      cout << "Invalid Input! Please input a double value." << endl;
			      cout << "Annual Interest: " << endl;
			      cin.clear();
			      while (cin.get() != '\n') ; // empty loop
			  }
			}
			userData.setAnnualIntrest(aI);
		}
		else if (change == "y"){
			cout << "Number of years: " << endl;
			while (1) {
			  if (cin >> nY) {
			      // valid number
			      break;
			  } else {
			      // not a valid number
			      cout << "Invalid Input! Please input an integer value.\n"
			    	   <<"(Note if you put in a double value it will be rounded down)" << endl;
			      cout << "Number of years: " << endl;
			      cin.clear();
			      while (cin.get() != '\n') ; // empty loop
			  }
			}
			userData.setNumYears(nY);
		}
		else{
			cout << "Invalid input, program terminating." << endl;
			break;
		}
		printData(userData);
	}
	return 0;
}
