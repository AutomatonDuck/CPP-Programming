/************************************************************************************************************************

Name:  Dominic Robbins                               	Z23496617
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:   10/07/19
Total Points: 10
Assignment #: 6

Description: Using data from a file to extract to parameters in a record array and outputing to a file

*************************************************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Global variable for array count
const int  SIZE = 50;

class order_record
{
public:
	string cell_number, item_number;
	int quantity, processing_plant;
	double cost, tax_rate, order_tax, net_cost, total_cost;

};

//Function prototypes

void input(order_record, int&);
void process(order_record, const int);
void output(const order_record, const int);
double tally_inventory(const order_record, const int);

//Function implementation

///****************************************************************************************
// Name : input
//Precondition: Formal parameters have not been intialized
//Postcondition: Fromal parameters (cell_number, item_number, quantity, price, processing plant) have been initalized
	// with data from purchase_data.txt
//Description: This function will read data from record file and intialize it to an record array.
//Purpose: Will initalize paramters with data from input file

void input(order_record INV[], int& count)
{
	ifstream input;
	input.open("purchase_data.txt");
	if (input.fail())
	{
		cout << "File Failed to open, Program will now end \n\n";
		exit(1);
	}
	while (!input.eof() && count < SIZE)
	{
		
		
			input >> INV[count].cell_number;
			input >> INV[count].item_number;
			input >> INV[count].quantity;
			input >> INV[count].cost;
			input >> INV[count].processing_plant;

			count++;
		
	}
	input.close();
}

///*****************************************************************************************


///****************************************************************************************
// Name : process
//Precondition: Formal parameters have not been intialized
//Postcondition: Fromal parameters (net_cost, order_tax, and total cost) will be intialized
	// with arithmatic calculations using data from input
//Description: Will use data from input to calculate input for formal parameters
//Purpose: Will compute variables and intialize parameters with computed data

void process(order_record INV[], const int count)
{
	for (int i = 0; i < count; i++) {
		if (INV[i].processing_plant >= 0 && INV[i].processing_plant <= 50)
			INV[i].tax_rate = 6;
		if (INV[i].processing_plant >= 51 && INV[i].processing_plant <= 110)
			INV[i].tax_rate = 7;
		if (INV[i].processing_plant >= 111 && INV[i].processing_plant <= 200)
			INV[i].tax_rate = 8;
		if (INV[i].processing_plant >= 201 && INV[i].processing_plant <= 500)
			INV[i].tax_rate = 9;
		if (INV[i].processing_plant > 500)
			INV[i].tax_rate = 11;

		INV[i].order_tax = INV[i].quantity * INV[i].cost * (INV[i].tax_rate / 100);
		INV[i].net_cost = INV[i].quantity * INV[i].cost;
		INV[i].total_cost = INV[i].net_cost + INV[i].order_tax;
	}
}

///*****************************************************************************************

///****************************************************************************************
// Name : output
//Precondition: Formal parameters have been intialized
//Postcondition: Fromal parameters from input and process will be displayed on an ouput file
//Description: Will display data from record and data from calculations to an output file
//Purpose: Will output to output file

void output(const order_record INV[], const int count)
{
	ofstream output;
	output.open("purchase_results5.txt");
	
	//magic formula
	output.setf(ios::showpoint);
	output.setf(ios::fixed);
	output.precision(2);

	for (int i = 0; i < count; i++) {
		output << INV[i].cell_number << '\t' << INV[i].item_number << '\t' << INV[i].quantity << '\t' << INV[i].cost << '\t'
			<< INV[i].processing_plant << '\t' << static_cast <int> (INV[i].tax_rate) << '\t' << INV[i].order_tax << '\t'
			<< INV[i].net_cost << '\t' << INV[i].total_cost << endl;
		
	}

	output.close();
}
///*****************************************************************************************

///****************************************************************************************
// Name : tally_inventory
//Precondition: Formal parameters have been intialized
//Postcondition: total order cost average will be calculated
//Description: Will calculate the average of the total order cost
//Purpose: calcualte the average of a formal parameter

double tally_inventory(const order_record INV[], const int count)
{
	int i;
	double avg =0.0;
	for (i = 0; i < count; i++)
	{
		avg += INV[i].total_cost;
	}
	//cout << i << endl; // checking to make sure i value is correct quiotient for avg calculation
	avg = avg / (i);

	return avg;
}
///*************************************************************************************







int main()
{
	int count = 0;
	order_record INV[SIZE];

	input(INV, count);
	process(INV, count);
	output(INV, count);

	cout << "The average total order cost = " << tally_inventory(INV, count) << endl;



	return 0;
}