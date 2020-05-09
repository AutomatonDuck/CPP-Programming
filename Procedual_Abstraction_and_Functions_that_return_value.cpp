/*************************************************************************************************************************
Chapter 4 notes
Topic: Procedual abstraction and functions that return a value


coded by Dominic Robbins 
**************************************************************************************************************************/

#include<iostream>

#include<cmath> 
/***********************************************************************************************
contains:
	sqrt (Square root)
	pow (powers)
	fabs (absolute value for doubles)
	ceil (round up for doubles)
	floor (round down for doubles)

**************************************************************************************************************/
#include<cstdlib> 
/*******************************************************************************************
contains:
	abs (absolute value for integers)
	labs(absolute value for longs)
**************************************************************************************************************/
#include<ctime>

using namespace std;

int main()
{
	double the_root, value, square, r_up, r_down;
	int num_1, num_2;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);


	the_root = sqrt(9.0);
	cout << the_root << endl;

	value = fabs(-8.9);
	cout << value << endl;

	square = pow(8.0,2.0);
	cout << square << endl;

	r_up = ceil(8.698);
	r_down = floor(8.698);

	cout << r_up << endl << r_down << endl;


	int die = rand();
	cout << die << endl;
	srand(time(NULL));
	die = rand();
	cout << die << endl;
	srand(5);
	die = rand();
	cout << die << endl;
	return 0;
}