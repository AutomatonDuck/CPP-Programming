/************************************************************************************************************************

Name:  Dominic Robbins                               	Z23496617
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:   10/14/19
Total Points: 10
Assignment #: 7

Description: will determine the number of occurances of each letter in a block of text, and count the number of words

*************************************************************************************************************************/


#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;
//function prototypes

void InzArray(int);
int word_count(ifstream&, string, int);
void letter_count(string, int[]);
void output(int, int);

//function inmplementation




///********************************************************************************************************
// Name : InzArray
//Precondition: Array has not been intialized
//Postcondition: array will be intialized to 0
//Description: This function intializes refrenced array to 0 for all elements
//Purpose: Will initalize array

void InzArray(int letters[])
{
	for (int i = 0; i < 26; i++)
	{
		letters[i] = 0;
		/*cout << letters[i] << endl;*/
	}
}


//*********************************************************************************************************

///********************************************************************************************************
// Name : word_count
//Precondition: string has not been intialized
//Postcondition: string will be intialized to last letter from dat file and word count will be returned
//Description: This function will read words from a dat file and count the words
//Purpose: Will initalize parameters and count words from a data file

int word_count(ifstream& in, string words, int letArray[])
{
	int count = 0;
	while (!in.eof())
	{
		in >> words;
		count++;
		
		////displays all text to monitor for testing
		//cout << words << endl;

		//this works better since the eof tag does not need to be cleared
		letter_count(words, letArray);
	}

	return count;
}



//*********************************************************************************************************

///********************************************************************************************************
// Name : letter_count
//Precondition: String is being intialized in while loop
//Postcondition: Will count number of occurances of a character 
///using an array starting from elements: 0 = a to 26 = z
//Description: This function will count occurances of each letter
//Purpose: Will count occurances of letters

void letter_count(string words, int letters[])
{
	
	
	for (int q = 0; q < words.length(); q++) 
	{
		//this loop allows the int value of characters to be assigned to it equal number value element in the array
		//whilst adding 1 to the element every time it occures in the loop.
		if (words[q] >= 'A' && words[q] <= 'Z')
		{
			letters[words[q] - 'A']++;
		}
		if (words[q] >= 'a' && words[q] <= 'z')
		{
			letters[words[q] - 'a']++;
		}
	}

	
}
///********************************************************************************************************
// Name : Output
//Precondition: all parameters have been intialized
//Postcondition: data has been output to screen
//Description: This function will display parameter data
//Purpose: to output data for user

void output(int count, int letArray[])
{
	cout << "********************************" << endl;

	cout << count << " Words" << endl;

	for (int n = 0; n < 26; n++)
	{
		if (letArray[n] > 0)
			cout << letArray[n] << '\t' << static_cast<char>(n + 'a') << endl;
	}
	cout << endl << "********************************" << endl;
}



//*********************************************************************************************************



//**********************************************************************************************************

int main()
{
	int count, letArray[26];
	ifstream inp;
	string words; 

	inp.open("mytext.dat");

	if (inp.fail())
	{
		cout << "Error: File did not open \n" << "Program will now exit\n";
		exit(1);
	}

	
	
	//intializes array
	InzArray(letArray);

	//input
	////letArray is passed for function call inside word_count
	count = word_count(inp, words, letArray); 

	//output
	output(count, letArray);
	
	
	
	
	
	//// getting ascii values
	//for (int i = 'A'; i < 'Z'; i++)
	//{
	//	cout << "i = \t" << i << "\t letter is\t " << static_cast<char>(i) << endl;
	//}

	//for (int i = 'a'; i < 'z'; i++)
	//{
	//	cout << "i = \t" << i << "\t letter is\t " << static_cast<char>(i) << endl;
	//}

	

	inp.close();
	return 0;
}