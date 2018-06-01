#include <iostream>
//Section 6
//Challenge

/*
 * Frank's Carpet Cleaning Service
 * Charges:
 * $25 per small room
 * $35 per large room
 * sales tax is 6%
 * Estimates are valid for 30 days
 * 
 * Prompt the user for the number of small and large rooms they would like 
 * cleaned and provide and estimate such as:
 * 
 * Estimate for carpet cleaning service
 * Number of small rooms: 3
 * Number of large rooms: 1
 * Price per small room: $25
 * Price per large room: $35
 * 
 * Cost: $110
 * Tax: $6.6
 * ===================================
 * Total Estimate: $116.60
 * This estimate is valid for 30 days
 */


using namespace std;

int main() {
	
	/*
	 * find out how many small rooms
	 * find out how many large rooms
	 * Prices:
	 * small rooms = 25
	 * large rooms = 35
	 * Then add small_rooms * 25 + large_rooms * 35;
	 * sales tax: .06 of cost
	 * total estimate = total of price for rooms + sales tax
	 * Estimate is valid for 30 days
	 */ 
	
	int num_small_rooms {0};
	const double price_small_room {25};
	int num_large_rooms {0};
	const double price_large_room {35};
	const double tax {.06};
	const int expire_day {30};
	
	
	cout << "Welcome to Frank's Carpet Cleaning Service" << endl;
	cout << "\nHow many small rooms would you like to have cleaned?" << endl;
	cin >> num_small_rooms;
	
	cout << "\nHow many large rooms would you like to have cleaned?" << endl;
	cin >> num_large_rooms;
	
	cout << "Estimate for carpet cleaning service" << endl;
	cout << "Number of small rooms:" << num_small_rooms << endl;
	cout << "Number of large rooms:" << num_large_rooms << endl;
	
	cout << "Price per small room: $" << price_small_room << endl;
	cout << "Price per large room: $" << price_large_room << endl;
	
	double cost_before_tax = (num_small_rooms * price_small_room) + (num_large_rooms * price_large_room);
	
	cout << "Cost: $" << cost_before_tax << endl;
	
	double sales_tax = cost_before_tax * tax;
	
	cout << "Tax: $" << sales_tax << endl; 
	
	double total_cost = cost_before_tax + sales_tax;
	
	cout << "\n=============================================";
	
	cout << "\nTotal Estimate: $" << total_cost << endl;
	cout << "This estimate is valid for " << expire_day << " days" << endl; 
	
	
	
	
	return 0;
}