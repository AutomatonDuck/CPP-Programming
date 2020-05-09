#include<iostream>
#include<string>
#include<fstream>
#include"order_class.h"

/********************************************************HEADER COMPILE FILE****************************************************************/
//Function implementation

///****************************************************************************************
// Name : Order_class ( Default Constructor)
//Precondition: parameters are uninitialized
//Postcondition: parameters, cell_nuber, item_number, quantity, price, and processing_plant
//will be intialized
//Description: will intialize parameters in order record with data from input file
//Purpose: to intialize parameters

order_class::order_class()
{
	
	INV = new order_record[size];

	cout << "****************************" << endl << "Default constructor called" << endl << "****************************" << endl;



	ifstream input;
	input.open("purchase_data_Assignment11.txt");

	if (input.fail())
	{
		cout << "*************************************************************" << endl;
		cout << "Error: Input file could not be found \nProgram will now end" << endl;
		cout << "*************************************************************" << endl;
		exit(1);
	}

	while (!input.eof())
	{
		if (is_full() == true)
		{
			double_size();
		}

		input >> INV[count].cell_number >> INV[count].item_number >> INV[count].quantity
			>> INV[count].price >> INV[count].processing_plant;

		count++;
	}
	input.close();
}

//******************************************************************************************

///****************************************************************************************
// Name : order_class (Copy Constructor)
//Precondition: dynamic array is not intialized
//Postcondition: will copy data stored in current object into dynamic array
//Description: performs deep copy of data
//Purpose: to copy data into a dynamic array

order_class::order_class(const order_class& org)
{
	cout << "****************************" << endl << "Copy constructor called" << endl << "****************************" << endl;
	count = org.count;
	size = org.size;
	INV = new order_record[size];
	for (int i = 0; i < count; i++)
	{
		INV[i] = org.INV[i];
	}
	
	

}

//******************************************************************************************

///****************************************************************************************
// Name : is_Empty
//Precondition: input paramter has no true/false indicator
//Postcondition: will return true or false for input parameters
//Description: checks count to see if its empty
//Purpose: to return a true or false statment

bool order_class::is_empty()
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

bool order_class::is_full()
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

int order_class::search(string key)
{
	if (is_empty() == false)
	{
		for (int i = 0; i < count; i++)
		{
			if (INV[i].cell_number == key)
			{

				return i;
			}
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

void order_class::add()
{
	if (is_full() == true)
	{
		double_size();
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




	count++;
	process();
}

//******************************************************************************************
///****************************************************************************************
// Name : operator -
//Precondition: data has been intialized to record
//Postcondition: will remove data
//Description: removed duplicates that have matching keys using chaining
//Purpose: member function with chaining
//
order_class& order_class :: operator-(const string key)
{
	if (is_empty() == false)
	{
		int loc = search(key);
		if (loc != -1)
		{
			for (int i = loc; i < count - 1; i++)
			{
				INV[i] = INV[i + 1];
			}

			count--;
		}
	}

	return *this;
}

//******************************************************************************************
///****************************************************************************************
// Name : double_size
//Precondition: array is full
//Postcondition: array space is doubled
//Description: doubles array space
//Purpose: to increase the cpacity of a dynamic array

void order_class::double_size()
{
	size *= 2;
	order_record* t = new order_record[size];

	for (int i = 0; i < count; i++)
	{
		t[i] = INV[i];
	}

	delete[] INV;

	INV = t;

	/*cout << "***************************" << endl << "Double size called" << endl << "***********************" << endl;*/
}

//******************************************************************************************
///****************************************************************************************
// Name : process
//Precondition: parameters: cell_nuber, item_number, quantity, price, and processing_plant
//have been intialized
//Postcondition: will intialize total_cost, net_cost, order_tax
//Description: will intialize parametrs will equations
//Purpose: to initalized parameters
void order_class::process()
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
// Name : operator <<
//Precondition: all data has been input from input file
//Postcondition: data will be displayed to screen using chaining
//Description: friend function that outputs to screen using chaining
//Purpose: displays all data on output screen
ostream& operator<<(ostream& out, order_class& org)
{


	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);

	for (int i = 0; i < org.count; i++)
	{
		out << org.INV[i].cell_number << '\t' << org.INV[i].item_number << '\t' << org.INV[i].quantity << '\t' << org.INV[i].price << '\t'
			<< org.INV[i].processing_plant << '\t' << static_cast <int> (org.INV[i].tax_rate) << '\t' << org.INV[i].order_tax << '\t'
			<< org.INV[i].net_cost << '\t' << org.INV[i].total_cost << endl;


	}
	return out;
}

//******************************************************************************************
///****************************************************************************************
// Name : destructor
//Precondition: INV has been itialized and constructor called
//Postcondition: destrcutor will be called
//Description: de-allocates memory used by array
//Purpose: de-allocates memory

order_class::~order_class()
{
	cout << endl << "****************************" << endl << "Destructor has been called" << endl
		<< "****************************" << endl;

}

//******************************************************************************************