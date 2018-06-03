//US dollars to Euros

#include <iostream>

//This will convert US dollars to Euros

using namespace std;

int main() {
	
	double us_dollars{0};
	double euros{0};
	
	cout << "How many US dollars do you have? " << endl;
	cin >> us_dollars;
	
	euros = us_dollars * .86;
	cout.precision(4);
	
	cout << "You currently have " 
	<< us_dollars 
	<< " and in euros that is equal to " 
	<< euros << endl;
	
	
	return 0;
}