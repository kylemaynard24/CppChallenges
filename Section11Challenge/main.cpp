// Section 11
// Challenge 
/*
     Recall the challenge from Section 9 below.
    Your challenge for section 11 is to modularize your solution to the Section 9
    challenge by refactoring your solution so that it uses uses functions.
    
    You decide how to modularize the program.
    you can use my solution which is included in this file, or modularize your solution.
    
    Here are a few hints:
        - Create functions for each major function
        - Keep the functions small
        - Remember the Boss/Worker analogy
        - Keep the vector declaration in the main function and pass the vector object
          to any function that requires it

        DO NOT move the vector object outside main and make it a global variable.
    
        - You can start by defining a function that displays the menu
        - You can then define a function that reads the selection from the user and returns it in uppercase
        - Create functions for each menu option
        - Create functions that display the list of numbers, calculates the mean and so forth
        
    Take it one function at a time and take your time.
    If you get frustrated, take a break -- this isn't as easy as it looks the first time you do it!
    
    Finally,  don't forget to use function prototypes!
    
    Good luck -- I know you can do it!
*/
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

using namespace std;

char lower_selection (char &a);
void print_numbers(vector<int> &vector);
void add_numbers(vector<int> &vector);
void get_mean(vector<int> &vector);
void get_small(vector<int> &vector);
void get_large(vector<int> &vector);
void clear(vector<int> &vector);



int main() {
	vector <int> dataset{};
	char menu_choice {};
	do {
		cout << "\n P - Print numbers \n A - Add a number \n M - Display mean of the numbers \n S - Display the smallest number \n L - Display the largest number \n C - Clear dataset \n Q - Quit \n \n Make your selection:" << endl; 
		cin >> menu_choice;
		lower_selection(menu_choice);
		//running if, if else, else to figure out which function to run, KISS
		if (menu_choice == 'p')
			print_numbers(dataset); 
		else if(menu_choice == 'a')
			add_numbers(dataset);
		else if(menu_choice == 'm')
			get_mean(dataset);
		else if(menu_choice == 's')
			get_small(dataset);
		else if(menu_choice == 'l')
			get_large(dataset);
		else if(menu_choice == 'c')
			clear(dataset);
		else if(menu_choice == 'q')
			cout << "you selected q" << endl;
		else
			cout << "This option is not on the menu, \n Please Pick again!" << endl;
	}
	while (menu_choice != 'q');
	return 0;
}

char lower_selection (char &a){
	a = tolower(a);
	return a;
}

void print_numbers(vector<int> &vector){
	if(vector.size() != 0){
		cout << " [";
		for(unsigned int i = 0; i <= vector.size() - 1; i++){
			cout << vector.at(i);
			cout << " ";
		}
		cout << "]" << endl;
	}
	else{
		cout << "[] - the list is empty" << endl;
	}
}

void add_numbers(vector<int> &vector){
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
			vector.push_back(user_number);
			cout << user_number << " added \n" << endl;
}

void get_mean(vector<int> &vector){
	double mean{};
			int total{};
			
				if(vector.size() != 0) {
					for (unsigned int i = 0; i < vector.size(); i++){
						total += vector.at(i);
					}
						mean = total/vector.size();
						cout << "The mean of your data set is: " << mean << endl;
										}
				else {
					cout << "Unable to calculate the mean - no data" << endl;
				}
												}
												

void get_small(vector<int> &vector){
	cout << "You have chosen to find the smallest number" << endl;
			if (vector.size() != 0){
			for (unsigned int i = 0; i < vector.size(); i++){
				if(vector.at(0) > vector.at(i)){
					vector.at(0) = vector.at(i);
				}
			}}
			else {
				cout << "Unable to determine the smallest number - list is empty" << endl;
				//continue brings back to the main menu
				//continue;
			}
			cout << "The smallest number of the data set is: " << vector.at(0) << endl;
		}

void get_large(vector<int> &vector){
	cout << "You have chosen to find the largest number" << endl;
			if (vector.size() != 0){
			for (unsigned int i = 0; i < vector.size(); i++){
				if(vector.at(0) < vector.at(i)){
					vector.at(0) = vector.at(i);
				}
			}}
			else {
				cout << "Unable to determine the largest number - list is empty" << endl;
				//continue brings back to the main menu
				//continue;
			}
			cout << "The largest number of the data set is: " << vector.at(0) << endl;
		}
		
void clear(vector<int> &vector){
	vector.clear();
}