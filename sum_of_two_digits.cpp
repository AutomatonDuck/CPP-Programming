// sum_of_two_digits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


int sum_of_two_digits(int a, int b)
{
	int sum = a + b;
	return sum;
}

int main()
{
	int a, b;
	cout << "enter two intigers: ";
	cin >> a >> b;

	cout << sum_of_two_digits(a, b);
	return 0;
}