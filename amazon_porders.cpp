/************************************************************************************************************************

Name:  Dominic Robbins                               	Z23496617
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:   9/30/19
Total Points: 10
Assignment #: 5

Description: Using data from a file to extract to parameters and and ouputing them to a output file

*************************************************************************************************************************/

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class p_record
{
public:

	string cell_number, item_number;
	int quantity, processing_plant;
	double price, tax_rate, order_tax, total_cost, net_cost;


};

void input(ifstream&, p_record&);
void process(p_record&);
void output(ofstream&, const p_record&);

//Function implementation

///****************************************************************************************
// Name : input
//Precondition: Formal parameters have not been intialized
//Postcondition: Fromal parameters (cell_number, item_number, quantity, price, processing plant) have been initalized
	// with data from purchase_data.txt
//Description: This function will read data from record file and intialkize it to formal parameters.
//Purpose: Will initalize paramters with data from input file

void input(ifstream& in, p_record& o_record)
{
	in >> o_record.cell_number;
	in >> o_record.item_number;
	in >> o_record.quantity;
	in >> o_record.price;
	in >> o_record.processing_plant;

}

///*****************************************************************************************


///****************************************************************************************
// Name : process
//Precondition: Formal parameters have not been intialized
//Postcondition: Fromal parameters (net_cost, order_tax, and total cost) will be intialized
	// with arithmatic calculations using data from input
//Description: Will use data from input to calculate input for formal parameters
//Purpose: Will compute variables and intialize parameters with computed data

void process(p_record& o_record)
{
	if (o_record.processing_plant >= 0 && o_record.processing_plant <= 50)
		o_record.tax_rate = 6;
	if (o_record.processing_plant >= 51 && o_record.processing_plant <= 110)
		o_record.tax_rate = 7;
	if (o_record.processing_plant >= 111 && o_record.processing_plant <= 200)
		o_record.tax_rate = 8;
	if (o_record.processing_plant >= 201 && o_record.processing_plant <= 500)
		o_record.tax_rate = 9;
	if (o_record.processing_plant > 500)
		o_record.tax_rate = 11;

	o_record.order_tax = o_record.quantity * o_record.price * (o_record.tax_rate/100);
	o_record.net_cost = o_record.quantity * o_record.price;
	o_record.total_cost = o_record.net_cost + o_record.order_tax;

}

///*****************************************************************************************

///****************************************************************************************
// Name : output
//Precondition: Formal parameters have been intialized
//Postcondition: Fromal parameters from input and process will be displayed on an ouput file
//Description: Will display data from record and data from calculations to an output file
//Purpose: Will output to output file

void output(ofstream& outf, const p_record& o_record)
{
	outf.setf(ios::showpoint);
	outf.precision(2);
	outf.setf(ios::fixed);

	outf << o_record.cell_number << "\t" << o_record.item_number << "\t" << o_record.quantity << "\t"
		<< o_record.price << "\t" << o_record.processing_plant << "\t" << static_cast <int> (o_record.tax_rate) << "\t"
		<< o_record.order_tax << "\t" << o_record.net_cost << "\t" << o_record.total_cost << endl;

}
///*****************************************************************************************


int main(void)
{
	cout << "This program will read data from an input file,\n"
		<<"store it in a record,\n" 
		<< "calculate taxes and costs,\n" 
		<< "and print to an output file\n\n";

	p_record o_record;

	ifstream in;
	in.open("purchase_data.txt");
	if (in.fail())
	{
		cout << "Error: Input file failed to open!!\n"
			<< "Closing program\n\n";
		exit(1);
	}

	ofstream outf;
	outf.open("amazon_inventory_092019.txt");

	while (!in.eof())
	{
		input(in, o_record);
		process(o_record);
		output(outf, o_record);
	}
	
	cout << "Data has been recorded into output file.\n";
	in.close();
	outf.close();

	return 0;
}