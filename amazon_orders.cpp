/*********************************************************************************************************
Dominic Robbins
Due Date: 09/09/19
Course: COP3014
Assignment: Assignment 2
Professor: Dr. Bullard

This program will process faux Amazon purchase orders from a data file

last updated 08/29/19
***********************************************************************************************************/

//preprocessor directives

#include<iostream>
#include<string>
#include <fstream>
using namespace std;

class order_record
{
public:
	string cell_number, item_number;
	double quantity, price, tax_rate;
	double order_tax, net_cost, total_cost;
	int processing_plant;
};

//Function prototypes


void input(ifstream &, order_record &);

void process(order_record &);

void output(const order_record &);

int main()
{ 
	order_record customer_record;

	ifstream in; //declared input file stream
	in.open("Purchase_data_Assignment2.txt");

	if (in.fail())
	{
		cout << "Input file failed to open \n";
	}
	else
	{
		while (!in.eof())
		{
			input(in, customer_record);
			process(customer_record);
			output(customer_record);
		}
	}

	in.close();
	return 0;
}

//Function implementation

///****************************************************************************************
// Name : input
//Precondition: Formal parameters have not been intialized
//Postcondition: Fromal parameters (cell_number, item_number, quantity, price, processing plant) have been initalized
	// with data from purchase_data._Assignment1.txt
//Description: This function will read data from record file and intialkize it to formal parameters.
//Purpose: To show knowledge in reading input and using call by value input and output parameters.

void input(ifstream& in, order_record& p_record)
{
	in >> p_record.cell_number;
	in >> p_record.item_number;
	in >> p_record.quantity;
	in >> p_record.price;
	in >> p_record.processing_plant;

}

///*****************************************************************************************

///****************************************************************************************
// Name : process
//Precondition: Formal parameters have not been intialized
//Postcondition: Fromal parameters (net_cost, order_tax, and total cost) will be intialized
	// with arithmatic calculations using data from input
//Description: Will use data from input to calculate input for formal parameters
//Purpose: To show knowledge in reading input and using call by value input and output parameters and using arithmatic statments

void process(order_record& p_record)
{
	if (p_record.processing_plant >= 0 && p_record.processing_plant <= 50)
		p_record.tax_rate = 0.06;
	if (p_record.processing_plant >= 51 && p_record.processing_plant <= 110)
		p_record.tax_rate = 0.07;
	if (p_record.processing_plant >= 111 && p_record.processing_plant <= 200)
		p_record.tax_rate = 0.08;
	if (p_record.processing_plant >= 201 && p_record.processing_plant <= 500)
		p_record.tax_rate = 0.09;
	if (p_record.processing_plant > 500)
		p_record.tax_rate = 0.11;

	p_record.order_tax = p_record.quantity * p_record.price * p_record.tax_rate;
	p_record.net_cost = p_record.quantity * p_record.price;
	p_record.total_cost = p_record.net_cost + p_record.order_tax;

}

///*****************************************************************************************

///****************************************************************************************
// Name : output
//Precondition: Formal parameters have been intialized
//Postcondition: Fromal parameters from input and process will be displayed to user
//Description: Will display data from record and data from calculations to user.
//Purpose: To show knowledge in reading input and using call by value input and output parameters and standard IO

void output(const order_record& p_record)
{
	cout.setf(ios::showpoint); 
	cout.precision(2); 
	cout.setf(ios::fixed);

	cout << p_record.cell_number << "\t" << p_record.item_number << "\t" << p_record.quantity << "\t"
		<< p_record.price << "\t" << p_record.processing_plant << "\t" << p_record.tax_rate << "\t"
		<< p_record.order_tax << "\t" << p_record.net_cost << "\t" << p_record.total_cost << endl;

}
///*****************************************************************************************