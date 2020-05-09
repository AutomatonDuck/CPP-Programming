/************************************************************************************************************************

Name:  Dominic Robbins                               	Z23496617
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:   09/23/19
Total Points: 20
Assignment #: 4

Description: Will calculate the area and semiperimeter of a triangle with user defined sided and will execute until user
//chooses to exit program

*************************************************************************************************************************/


#include <iostream>
#include <cmath>

using namespace std;

//Function prototype

void compute(double, double, double, double&, double&);
void greeting(void);

//Function Implementations

///*************************************************************************************
//Name: compute
//Precondition: Formal parameters a,b, and c been initalized
//Postcondition: Parameters area and perimeter will be intialized using calculations 
//Description: Using user input data will calculate the area and semiperimeter of a triangle
//Purpose: To calculate the area and semiperimeter of a triangle

//*************************************************************************************
void compute(double a, double b, double c, double& area, double& s)
{
	s = (a + b + c) / 2;
	area = sqrt(s * (s - a) * (s - b) * (s - c));

}
//*************************************************************************************

///*************************************************************************************
//Name: greeting
//Precondition: Formal parameters have not been initalized
//Postcondition: User will know scope and function of program
//Description: A greeting to inform user purpose of function
//Purpose: to greet user and inform function of prgram

//*************************************************************************************
void greeting(void)
{
	cout << "Hello, this program will calculate the semiperimeter and area of a triangle\n"
		<< "using three numbers enetred below as the length of the sides.\n"
		<< "Remember the rule with triangles: The sum of two sides must be greater than the third side\n";
}
//*************************************************************************************

int main()
{
	double a, b, c, area, perimeter;
	char choice;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	greeting();
	do
	{
		cout << "Enter three numbers\n";
		cin >> a >> b >> c;
		while (a + b <= c || a + c <= b || b + c <= a)
		{
			cout << "Invalid lengths\nReenter lengths of the sides\n";
			cin >> a >> b >> c;
		}
		compute(a, b, c, area, perimeter);

		cout << "The triangle with the sides:\n" << a << '\t' << b << '\t' << c << endl
			<< "Has an area of:\t" << area << endl
			<< "Has a semiperimter of:\t" << perimeter << endl << endl;
		//while conditions will go here using choice == y or == Y as the condition
		cout << "Would you like to calculate another triangle? Press Y to enter new data, any other key will end program:\n";
		cin >> choice;

	} while (choice == 'y' || choice == 'Y');

	cout << "Thank you for using this program\n";

	return 0;
}