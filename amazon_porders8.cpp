/************************************************************************************************************************

Name:  Dominic Robbins                               	Z23496617
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:   10/07/19
Total Points: 10
Assignment #: 8

Description: Reads data from an input file and will read to output file using dyanmic arrays, new and delete functions

*************************************************************************************************************************/

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class order_record
{
public:
	string cell_number, item_number;
	double quantity, price, tax_rate, order_tax, net_cost, total_cost;
	int processing_plant;
};

//Function prototypes
void initialize(order_record*&, int&, int&);
bool is_Empty(int);
bool is_full(int, int);
int search(order_record*, int&, string);
void add(order_record*&, int&, int&);
void remove(order_record*, int&, const string);
void double_size(order_record*&, int, int&);
void process(order_record*, int);
void print(const order_record*, const int);
void destroy_INV(order_record*&, int&, int&);

//Function implementation

///****************************************************************************************
// Name : initialize
//Precondition: parameters are uninitialized
//Postcondition: parameters, cell_nuber, item_number, quantity, price, and processing_plant
//will be intialized
//Description: will intialize parameters in order record with data from input file
//Purpose: to intialize parameters

void initialize(order_record*& INV, int&count, int&size)
{
	ifstream input;
	input.open("purchase_data8.txt");

	if (input.fail())
	{
		cout << "*************************************************************" << endl;
		cout << "Error: Input file could not be found \nProgram will now end" << endl;
		cout << "*************************************************************" << endl;
		exit(1);
	}

	while (!input.eof())
	{
		if (is_full(count, size) == true)
		{
			double_size(INV, count, size);
		}
		
		input >> INV[count].cell_number >> INV[count].item_number >> INV[count].quantity
			>> INV[count].price >> INV[count].processing_plant;

		count++;
	}
	input.close();
}

//******************************************************************************************
///****************************************************************************************
// Name : is_Empty
//Precondition: input paramter has no true/false indicator
//Postcondition: will return true or false for input parameters
//Description: checks count to see if its empty
//Purpose: to return a true or false statment

bool is_Empty(int count)
{
	return count == 0;
}

//******************************************************************************************
///****************************************************************************************
// Name : is_full
//Precondition: input paramters have no true or false statment
//Postcondition: will return a true/false relationship between the two paramters
//Description: checks count to see if its full
//Purpose: checks atrue or false statment

bool is_full(int count, int size)
{
	return count == size;
}

//******************************************************************************************
///****************************************************************************************
// Name : search
//Precondition: parameters have been initialized
//Postcondition: will return the location of a value located in an array
//Description: searches for a value in an array
//Purpose: searches an array

int search(order_record* INV, int&count, string key)
{
	if (is_Empty(count) == false)
	{
		for (int i = 0; i < count; i++)
		{
			if (INV[i].cell_number == key);
			return i;
		}
		
	}
	return -1;
}

//******************************************************************************************
///****************************************************************************************
// Name : add
//Precondition: array is being intialized
//Postcondition: add a key(cell_number) into the array
//Description: will add data into an array element
//Purpose: to add data into an array

void add(order_record*& INV, int& count, int& size)
{
	if (is_full(count, size) == true)
	{
		double_size(INV, count, size);
	}
	cout << "Enter customer cell number:	" << " " << endl;
	cin >> INV[count].cell_number;
	cout << "Enter item number: " << " " << endl;
	cin >> INV[count].item_number;
	cout << "Enter quantity of item:	" << " " << endl;
	cin >> INV[count].quantity;
	cout << "Enter price of single item:	" << " " << endl;
	cin >> INV[count].price;
	cout << "Enter processing plant #:	" << " " << endl;
	cin >> INV[count].processing_plant;

	string key = INV[count].cell_number;
	remove(INV, count, key);
	/*process(INV, count);*/

}

//******************************************************************************************
///****************************************************************************************
// Name : remove
//Precondition: key has been assigned to data in array
//Postcondition: key duplicates will be removed
//Description: removed duplicates that have matching keys
//Purpose: to remove duplicate information

void remove(order_record* INV, int& count, const string key)
{
	if (is_Empty(count) == false)
	{
		int loc = search(INV, count, key);
		if(loc != -1)
			for (int i = loc; i < count-1; i++)
			{
				INV[i] = INV[i + 1];
			}
		count--;
	}
}

//******************************************************************************************
///****************************************************************************************
// Name : double_size
//Precondition: array is full
//Postcondition: array space is doubled
//Description: doubles array space
//Purpose: to increase the cpacity of a dynamic array

void double_size(order_record*& INV, int count, int& size)
{
	size *= 2;
	order_record* t = new order_record[size];

	for (int i = 0; i < count; i++)
	{
		t[i] = INV[i];
	}

	delete[] INV;

	INV = t;
}

//******************************************************************************************
///****************************************************************************************
// Name : process
//Precondition: parameters: cell_nuber, item_number, quantity, price, and processing_plant
//have been intialized
//Postcondition: will intialize total_cost, net_cost, order_tax
//Description: will intialize parametrs will equations
//Purpose: to initalized parameters
void process(order_record* INV, int count)
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

		INV[i].order_tax = INV[i].quantity * INV[i].price * (INV[i].tax_rate / 100);
		INV[i].net_cost = INV[i].quantity * INV[i].price;
		INV[i].total_cost = INV[i].net_cost + INV[i].order_tax;
	}

}


//******************************************************************************************
///****************************************************************************************
// Name : print
//Precondition: all data has been input from input file
//Postcondition: data will be displayed on output file
//Description: outputs data to file
//Purpose: displays all data on output file in correct format
void print(const order_record* INV, const int count)
{
	ofstream out;
	out.open("purchase8_results.txt");

	out.setf(ios::showpoint);
	out.setf(ios::fixed);
	out.precision(2);

	for (int i = 0; i < count; i++)
	{
		out << INV[i].cell_number << '\t' << INV[i].item_number << '\t' << INV[i].quantity << '\t' << INV[i].price << '\t'
			<< INV[i].processing_plant << '\t' << static_cast <int> (INV[i].tax_rate) << '\t' << INV[i].order_tax << '\t'
			<< INV[i].net_cost << '\t' << INV[i].total_cost << endl;


	}
}

//******************************************************************************************
///****************************************************************************************
// Name : destroy_INV
//Precondition: INV has been itialized
//Postcondition: memory allocated for INV will be de-allocated
//Description: de-allocates memory used by array
//Purpose: de-allocates memory

void destroy_INV(order_record*& INV, int& count, int& size)
{
	delete[] INV;
	INV = 0;
	count = 0;
	size = 0;

}

//******************************************************************************************
int main()
{
	int count = 0, size = 1;
	order_record* INV = new order_record[size];

	initialize(INV, count, size);
	add(INV, count, size);
	process(INV, count);
	print(INV, count);
	destroy_INV(INV, count, size);

	

	return 0;
}