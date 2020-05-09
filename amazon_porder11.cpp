/************************************************************************************************************************

Name:  Dominic Robbins                               	Z23496617
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:   11/02/19
Total Points: 20
Assignment #: 10

Description: Reads data from an input file and will read to output file using dyanmic arrays, new and delete functions.
//with program spilt into a header file, a header compilation file, and a driver File.

*************************************************************************************************************************/

/********************************************************DRIVER FILE****************************************************************/

#include<iostream>
#include<string>
#include<fstream>
#include"order_class.h"




int main()
{
	order_class c_orders;

	c_orders.add();

	order_class my_orders = c_orders;

	cout << endl << "////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << c_orders << c_orders; //chain test
	cout << endl << "////////////////////////////////////////////////////////////////////////////////////////" << endl;

	c_orders - "9546321555" - "9546321555" - "9546321555"; //testing chaining

	cout << endl << "////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << c_orders; // single test
	cout << endl << "////////////////////////////////////////////////////////////////////////////////////////" << endl;

	c_orders - "5617278899"; //testing single

	cout << endl << "////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << c_orders;
	cout << endl << "////////////////////////////////////////////////////////////////////////////////////////" << endl;

	c_orders - "9542991211"; //testing unfound record

	cout << endl << "////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << c_orders;
	cout << endl << "////////////////////////////////////////////////////////////////////////////////////////" << endl;

	my_orders.add();

	cout << endl << "////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << my_orders;
	cout << endl << "////////////////////////////////////////////////////////////////////////////////////////" << endl;
	return 0;
}