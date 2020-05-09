// Array testing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<iomanip>
#include<fstream>

using namespace std;

const int SIZE = 50;
class record1
{
public:

	int a, b, c;
	string e, f, g;
	double h, j, k;
	char l, m, n;
	bool x, y, z;

};

void input(record1, int&);

void input(record1 arrayz[], int& count)
{
	while (count < SIZE)
	{
		arrayz[count].a = 5;
		arrayz[count].e = "Hello";
		arrayz[count].h = 99.87678;
		arrayz[count].l = 'a';
		arrayz[count].x = true;

		count++;
	}


}

void copyarr(record1 arrayz[], record1 arrays[], int const count) {

	for (int i = 0; i < count; i++)
	{
		arrays[i] = arrayz[i];

	}

}

int main()
{
	record1 array3[SIZE], array5[SIZE];
	int array1[SIZE], array4[SIZE], count, f;
	double array2[SIZE];
	ofstream out;
	out.open("Array_Test.doc");
	
	return 0;
}
