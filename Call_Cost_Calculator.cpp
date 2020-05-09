/*********************************************************************************************************
Dominic Robbins
Due Date: 09/02/19
Course: COP3014
Assignment: Assignment 1
Professor: Dr. Bullard

This program will calculate the net cost of a call, the tax on a call, and the total cost of that call taking relays,
and length of call

last updated 08/29/19
***********************************************************************************************************/

//preprocessor directives

#include <iostream>
#include <string>
using namespace std;

int main() {
	string cell_num, user_response;
	double net_cost, call_tax, total_cost, tax_rate;
	int relays, call_length;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "This program will calculate the total cost of a telephone call" << endl;
	cout << "while taking taxes into account" << endl;

	do 
	{
		
		cout << "Enter a cell phone number: ";
		cin >> cell_num;

		//loop with a conditional statment to prevent an invalid size phone number
		//This is not taking international phone numbers into account.
		//We can remove this if need be
		do {
			if (cell_num.length() != 10) {
				cout << "Entered invalid cell phone number" << endl << "Number must be 10 digits" << endl;
				cout << "Enter a cell phone number: ";
				cin >> cell_num;
			}
		} while (cell_num.length() != 10);
			
		cout << "Enter the length of the call in minutes: ";
		cin >> call_length;
		cout << "How many relays will the call pass through: ";
		cin >> relays;
		
		//if statements to control tax rate for number of relays
		if (relays >= 1 && relays <= 5)
			tax_rate = 0.01;

		if (relays >= 6 && relays <= 11)
			tax_rate = 0.03;

		if (relays >= 12 && relays <= 20)
			tax_rate = 0.05;

		if (relays >= 21 && relays <= 50)
			tax_rate = 0.08;

		if (relays > 50)
			tax_rate = 0.12;

		//conditional statements should user enter 0 for number of relays
		if (relays == NULL) {
			cout << "Invalid number of relays entered" << endl;
			tax_rate = 0.00;
		}
		

		net_cost = (relays / 50.0 * 0.40 * call_length);
		call_tax = net_cost * tax_rate;
		total_cost = net_cost + call_tax;

		cout << endl; //whitespace

		cout << "The cell number entered was:" << "\t" << cell_num << endl;
		cout << "# of relays:" << "\t" << relays << endl;
		cout << "Call length:" << "\t" << call_length << endl;
		cout << "Net cost:" << "\t" << "$"<< net_cost << endl;
		cout << "Tax rate:" << "\t" << "$" << tax_rate << endl;
		cout << "Call tax:" << "\t" << "$" << call_tax << endl;
		cout << "Total cost:" << "\t" << "$" << total_cost << endl;

		cout << endl; //whitespace



		cout << "Would you like to perform another calculation? Press y if yes. Any other key will leave program: ";
		cin >> user_response;
	} while (user_response == "Y" || user_response == "y");

	cout << "Thank you for using this program" << endl;
	return 0;
}