// Test 2 playground.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<fstream>

using namespace std;

class student_record
{
public:
	int age;
	string name;
	double gpa;
};

void destroy(student_record*&, int&, string, double);
void destroy(student_record*& s_record, int& count, const int age, const string name, const double gpa)
{
	if (count != 0)
	{
		int loc = -1;
		for (int i = 0; i < count; i++)
		{
			if (s_record[i].name == name && s_record[i].age == age && s_record[i].gpa == gpa)
			{
				loc = i;
				break;
			}
		}
		if (loc != -1)
		{
			for (int j = loc; j < count - 1; j++)
			{
				s_record[j] = s_record[j + 1];
			}

			count--;
		}
	}



}

void double_size(int*& h, int& size)
{
	size *= 2;
	int* t = new int[size];

	for (int i = 0; i < 1; i++)
	{
		t[i] = h[i];
	}
	delete[]h;
	h = t;
}
int main()
{
	int size = 1;
	int* p = new int[5];
	int* h = new int[size];
		for (int i = 0; i < 5; i++)
		{
			p[i] = 1+i;
		}

		for (int j = 0; j < 5; j++)
		{
			if (size < 5)
			{
				double_size(h, size);
			}
			h[j] = p[j];
		}

	
		for (int n = 0; n < 5; n++)
		{
			cout << "P #" << n << "=" << p[n] << endl;
			cout << "H #" << n << "=" << h[n] << endl;
		}
		delete[] p;
		delete[] h;
	return 0;
}
