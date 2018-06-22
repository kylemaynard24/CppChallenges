// Section 9
// Challenge
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	
	//using a vector because it is dynamic
	vector <int> numbers{};
	
	//char because the choices are single characters
	char choice {};
	
	
	do {
		cout <<
		//"Welcome to my menu application"
		"Pick an option \n" 
		<< "\nP - Print numbers"
		<< "\nA - Add a number"
		<< "\nM - Display mean of the numbers"
		<< "\nS - Display the smallest number"
		<< "\nL - Display the Largest number"
		<< "\nC - Clear the data structure of all data"
		<< "\nQ - Quit \n"
		<< "\nEnter your choice:" << endl;
		cin >> choice;
		
		if (choice == 'P' || choice == 'p'){
				cout << "You have chosen to print the numbers" << endl;
				if (numbers.size() != 0) 
					{
						// the output should look like: [ 1 2 3 4 5]
						cout << "[ ";
						//warning on next line because numbers.size() can not have a negative or signed int
						for(unsigned int i = 0; i < numbers.size(); i++){
							cout << numbers.at(i);
							cout << " ";
						}
						cout << "]" << endl;
					}
				else 
					{
					cout << "[] - the list is empty \n" << endl;
					}
											}
		
		else if (choice == 'A' || choice == 'a'){
			cout << "You have chosen to add a number to the vector" << endl;
			int user_number {};
			cout << "what number would you like to add?" << endl;
			cin >> user_number;
			while(!cin)
					{
						cout << "Please enter a valid integer: ";
						cin.clear();
						cin.ignore();
						cin >> user_number;
					}
			numbers.push_back(user_number);
			cout << user_number << " added \n" << endl;
		}
		
		
		else if (choice == 'M' || choice == 'm'){
			// find the mean
			// add up all of the integers in the vector
			// divide by the number of integers in the vector
			// verify that there are values in the vector
			// variables: double mean, int total
			
			double mean{};
			int total{};
			
				if(numbers.size() != 0) {
					for (unsigned int i = 0; i < numbers.size(); i++){
						total += numbers.at(i);
					}
						mean = total/numbers.size();
						cout << "The mean of your data set is: " << mean << endl;
										}
				else {
					cout << "Unable to calculate the mean - no data" << endl;
				}
												}

		else if (choice == 'S' || choice == 's'){
			cout << "You have chosen to find the smallest number" << endl;
			if (numbers.size() != 0){
			for (unsigned int i = 0; i < numbers.size(); i++){
				if(numbers.at(0) > numbers.at(i)){
					numbers.at(0) = numbers.at(i);
				}
			}}
			else {
				cout << "Unable to determine the smallest number - list is empty" << endl;
				//continue brings back to the main menu
				continue;
			}
			cout << "The smallest number of the data set is: " << numbers.at(0) << endl;
		}
		
		
		else if (choice == 'L' || choice == 'l'){
			cout << "You have chosen to find the largest number" << endl;
			if (numbers.size() != 0){
			for (unsigned int i = 0; i < numbers.size(); i++){
				if(numbers.at(0) < numbers.at(i)){
					numbers.at(0) = numbers.at(i);
				}
			}}
			else {
				cout << "Unable to determine the largest number - list is empty" << endl;
				//continue brings back to the main menu
				continue;
			}
			cout << "The largest number of the data set is: " << numbers.at(0) << endl;
		}
		
		else if (choice == 'C' || choice == 'c'){
			numbers.clear();
		}
		
		//finished
		else if (choice == 'Q' || choice == 'q'){
			cout << "You have chosen to quit the program!" << endl;
		}
		
		else {
			cout << "\nUnknown selection, please try again \n" << endl;
		}
	}
	while (choice != 'q' && choice != 'Q');
	
	
	return 0;
}