/************************************************************************************************************************

Name:  Dominic Robbins                               	Z23496617
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:   09/16/19                  
Total Points: 20
Assignment #: 3

Description: Using data from a file to extract to parameters and display data on screen, without using a class

*************************************************************************************************************************/

//Include the following

#include <iostream>
#include <string>
#include <fstream> 
#include <windows.h>
using namespace std;



// Function Prototypes

void input(ifstream&, string&, string&, double&, double&, int&);
void output(string, string, double, double, int, double, double, double, double);
void process(double, double, int, double&, double&, double&, double&);

//Function Implementations

///*************************************************************************************
//Name:  input
//Precondition: Formal parameters have not been initalized
//Postcondition: Parameters cell_number, item_number, quantity, price processing_plant will be intialized
//Description: Get input (values of cell_number, item_number, quantity, price, processing_plant ) 
//from data file.
//Purpose: Reads data from purchase_data and intializes it to parameters

//*************************************************************************************

void input(ifstream& in, string& cell_number, string& item_number, double& quantity, double& price, int& processing_plant) // example using the call by reference mechanism in C++ -- call record is passed by reference --note & operator
{
	in >> cell_number;
	in >> item_number;
	in >> quantity;
	in >> price;
	in >> processing_plant;

}

///*************************************************************************************
//Name:  output
//Precondition: All parameters are intialized.
//Postcondition: Parameters are printed to console.
//Description:  Prints data stored in parameters to screen.
//Purpose: To display data in parameters to console
//*************************************************************************************


void output(string cell_number, string item_number, double quantity, double price, int processing_plant, double tax_rate, double order_tax, double net_cost, double total_cost)
{
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	/********************************************/
	

	cout << cell_number << "\t" << item_number << '\t' << static_cast <int> (quantity) << '\t' << price << '\t' << processing_plant << '\t'
		<< static_cast <int> (tax_rate) << '\t' << order_tax << '\t' << net_cost << '\t' << total_cost << endl;


	


}

///*************************************************************************************
//Name:  process
//Precondition: Some parameters are initalized
//Postcondition:All parameters are inialized
//Description:  Calculates data for tax_rate, order_tax, net_cost, total_cost using data stored from process()
//Purpose: To calculate data for parameters using parameters from input.
//*************************************************************************************


void process(double quantity, double price, int processing_plant, double& tax_rate, double& order_tax, double& net_cost, double& total_cost)
{
	if (processing_plant >= 0 && processing_plant <= 50)
		tax_rate = 6.0;
	if (processing_plant >= 51 && processing_plant <= 110)
		tax_rate = 7.0;
	if (processing_plant >= 111 && processing_plant <= 200)
		tax_rate = 8.0;
	if (processing_plant >= 201 && processing_plant <= 500)
		tax_rate = 9.0;
	if (processing_plant > 500)
		tax_rate = 11.0;

	order_tax = quantity * price * (tax_rate/100);
	net_cost = quantity * price;
	total_cost = net_cost + order_tax;

}

int main()
{
	
	string cell_number;
	string item_number;
	double quantity;
	double price;
	int processing_plant;
	double tax_rate;
	double order_tax;
	double net_cost;
	double total_cost;

	ifstream in;    //declaring an input file stream
	in.open("purchase_data.txt");

	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		
		while (!in.eof())
		{

			input(in, cell_number, item_number, quantity, price, processing_plant);
			process(quantity, price, processing_plant, tax_rate, order_tax, net_cost, total_cost);
			
			output(cell_number, item_number, quantity, price, processing_plant, tax_rate,order_tax,net_cost,total_cost);
		}
	}

	in.close();

	return 0;
}


