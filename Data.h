/*
 * Data.h
 *
 *  Created on: Feb 6, 2021
 *      Author: antoniobethune
 */

#ifndef DATA_H_
#define DATA_H_

#include <iostream>
#include <iomanip>

class Data{
private:
	double initialInvestment;
	double monthtlyDeposit;
	double annualIntrest;
	int numYears;

public:
	Data(double iI, double mD, double aI, int nY){
		initialInvestment = iI;
		monthtlyDeposit = mD;
		annualIntrest = aI;
		numYears = nY;
	}

	double getInitialInvestment(){
		return initialInvestment;
	}

	double getMonthtlyDeposit(){
		return monthtlyDeposit;
	}

	double getAnnualIntrest(){
		return annualIntrest;
	}

	double getNumYears(){
		return numYears;
	}

	void setmonthtlyDeposit(double x){
		monthtlyDeposit = x;
	}

	void setAnnualIntrest(double x){
		annualIntrest = x;
	}

	void setInitialInvestment(double x){
		initialInvestment = x;
	}

	void setNumYears(int x){
		numYears = x;
	}

};

void printData(Data userData){
	double begginingBal = userData.getInitialInvestment();
	double currentInterest = 0;
	double currentTotal = 0;


	//Prints the values for interest overtime using monthly deposits
	//Shows Year, The Interest Earned and the Total Balance
	cout << "This is your data without a \n"
			<< "monthly deposit of " << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "   Year    Interest Earned     Year End Balance\n"
		 << "----------------------------------------------------"<< endl;
	for(int j = 1; j <= userData.getNumYears(); j++){
		currentInterest = (begginingBal * (userData.getAnnualIntrest()/100));
		currentTotal = begginingBal + currentInterest;

		cout << setprecision(2) << fixed;
		cout << setw(5) << j << setw(15) << currentInterest << setw(20) << currentTotal << endl;

		begginingBal = currentTotal;
	}

	begginingBal = userData.getInitialInvestment();
    currentInterest = 0;
	currentTotal = 0;

	//Prints the values for interest overtime using monthly deposits
	//Shows Year, The Interest Earned and the Total Balance
	cout << "This is your data including your \n"
			<< "monthly deposit of $" << userData.getMonthtlyDeposit() << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "   Year    Interest Earned     Year End Balance\n"
		 << "----------------------------------------------------"<< endl;
	for(int i = 1; i <= userData.getNumYears(); i++){
		currentInterest = ((begginingBal + userData.getMonthtlyDeposit()) * ((userData.getAnnualIntrest()/100)/12));
		currentTotal = begginingBal + userData.getMonthtlyDeposit() + currentInterest;

		cout << setprecision(2) << fixed;
		cout << setw(5) << i << setw(15) << currentInterest << setw(20) << currentTotal << endl;

		begginingBal = currentTotal;
	}
}






#endif /* DATA_H_ */
