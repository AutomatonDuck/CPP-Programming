/******************************************************************************************************
Dominic Robbins
09/03/19

Foundations of Computer science

Testing conditional statments and loops

*******************************************************************************************************/

#include <iostream>

using namespace std;

int main() {

	//This is incorrect because the else statment will connect to last if statment
	//Computers will not follow indentation.
	/*double fuel_guage;

	cout << "Fuel guage reading:	";
	cin >> fuel_guage;

	if (fuel_guage < 0.75)
		if (fuel_guage < 0.25)
			cout << "Low Fuel. Caution! \n";
		else
			cout << "Fule over 3/4. Do not stop! \n"; */

	//if-if else stamenent
	/*
	double tax_rate, income, tax;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "Enter income: $";
	cin >> income;

	if (income > 15000 && income <=25000)
		tax_rate = 0.05;
	else if (income > 25000)
		tax_rate = .10;
	else
		tax_rate = 0;

	tax = income * tax_rate;
	cout << "Income is: $" << income << endl;
	cout << "Tax rate is:" << tax_rate << endl;
	cout << "Total taxes: $" << tax << endl;
	*/

	//Switch statment.
	//Best used for a list
	/*char grade;

	cout << "Enter midterm grade:	";
	cin >> grade;

	switch (grade) {

	case 'A':
	case 'a':
		cout << "Excellent!" << endl;
		break;

	case 'B':
	case 'b':
		cout << "Very good" << endl;
		break;

	case 'C':
	case 'c':
		cout << "Passing" << endl;
		break;

	case 'D':
	case 'd':
	case 'F':
	case 'f':
		cout << "Not good, go study" << endl;
		break;

	default:
		cout << "Invalid grade"<<endl;
	}
	*/


	/*int x = 5;
	cout << x << endl;
	{
		cout << x << endl;
		int x = 6;
		cout << x << endl;
	}
	cout << x << endl;

	int number = 3, num = 2, res1, res2;

	res1 = 2 * number--;
	res2 = 2 * --num;
	cout << res1 << endl;
	cout << res2 << endl;*/

	/*int i = 1;
	cout << i << endl;

	for (i= 5; i < 9; i++)
	{
		i = i;
		cout << i << endl;

	}
	cout << i << endl;*/
int i;
for (i = 0; i < 14; i++)
{
	cout << "hi\n";
}

	return 0;
}
