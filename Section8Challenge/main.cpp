// Section 8 Challenge
/*
	For this program I will be using US dollars and cents.
	
    Write a program that asks the user to enter the following:
	An integer representing the number of cents 
    	
	You may assume that the number of cents entered is greater than or equal to zero
    
	The program should then display how to provide that change to the user.
	
	In the US:
		1 dollar is 100 cents
		1 quarter is 25 cents
		1 dime is 10 cents
		1 nickel is 5 cents, and
		1 penny is 1 cent.
		
	Here is a sample run:
	
	Enter an amount in cents :  92
	
	You can provide this change as follows:
	dollars    : 0
	quarters : 3
	dimes     : 1
	nickels   : 1
	pennies  : 2
	
	Feel free to use your own currency system.
	Also, think of how you might solve the problem using the modulo operator.

	Have fun and test your program!!

*/

//Create it without using % and one with
#include <iostream>

using namespace std;

int main() {
	//not using %
	
	const int dollar = {100};
	const int quarter {25};
	const int dime {10};
	const int nickel {5};
	const int penny {1};
	int user_amount {};
	
	
	cout << "How many cents are there in change? " << endl;
	cin >> user_amount;
//	
//	//to figure out how many times dollar goes into cents
//	int dollar_multiplier = user_amount/dollar;
//	
//	//to figure out what is left after taking out the dollars
//	int remainder_after_dollar = user_amount - (dollar * dollar_multiplier);
//	
//	//to figure out how many times quarter go into remaining cents
//	int quarter_multiplier = remainder_after_dollar/quarter;
//	
//	//to figure out what is left after taking out the quarters
//	int remainder_after_quarter = remainder_after_dollar - (quarter * quarter_multiplier);
//	
//	//to figure out how many dimes go into remaining cents
//	int dime_multiplier = remainder_after_quarter/dime;
//	
//	//to figure out what is left after taking out the dimes
//	int remainder_after_dime = remainder_after_quarter - (dime * dime_multiplier);
//	
//	//to figure out how many nickels go into remaining cents
//	int nickel_multiplier = remainder_after_dime/nickel;
//	
//	//to figure out what is left after taking out the nickels
//	int remainder_after_nickel = remainder_after_dime - (nickel * nickel_multiplier);
//	
//	
//	//to figure out how many pennies go into remaining cents
//	int penny_multiplier = remainder_after_nickel/penny;
//	
//	//to figure out what is left after taking out the pennies
//	int remainder_after_penny = remainder_after_penny - (penny * penny_multiplier);
//	
//	
//	//how much of each:
//	cout << "dollars: " << dollar_multiplier << endl;
//	cout << "quarters: " << quarter_multiplier << endl;
//	cout << "dimes: " << dime_multiplier << endl;
//	cout << "nickels: " << nickel_multiplier << endl;
//	cout << "pennies: " << penny_multiplier << endl;
	
	
	// using %;
	
	//already have the user_amount
	
	// get the remainder using mod, subtract from left total, divide by currency
	
	int remainder_after_dollar = user_amount % dollar;
	int num_of_dollars = (user_amount - remainder_after_dollar)/dollar;
	
	
	int remainder_after_quarter = remainder_after_dollar % quarter;
	int num_of_quarters = (remainder_after_dollar - remainder_after_quarter)/quarter;
	
	int remainder_after_dime = remainder_after_quarter % dime;
	int num_of_dimes = (remainder_after_quarter - remainder_after_dime)/dime;
	
	int remainder_after_nickel = remainder_after_dime % nickel;
	int num_of_nickels = (remainder_after_dime - remainder_after_nickel)/nickel;
	
	int remainder_after_penny = remainder_after_nickel % penny;
	int num_of_pennies = (remainder_after_nickel - remainder_after_penny)/penny;
	
	cout << "dollars: " << num_of_dollars << endl;
	cout << "quarters: " << num_of_quarters << endl;
	cout << "dimes: " << num_of_dimes << endl;
	cout << "nickels: " << num_of_nickels << endl;
	cout << "pennies: " << num_of_pennies << endl;
	
	
	return 0;
}