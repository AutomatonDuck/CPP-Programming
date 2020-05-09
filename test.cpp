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
int word_count(ifstream&, string);
void letter_count(string, int array[]);

//function inmplementation




///********************************************************************************************************
// Name : InzArray
//Precondition: Array ha s not been intialized
//Postcondition: Formal parameters will be intialized from data file
//Description: This function will read words from a dat file and count the words
//Purpose: Will initalize paramters and count words from a data file

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

int word_count(ifstream& in, string words)
{
	int count = 0, letters[26];
	InzArray(letters);
	while (!in.eof())
	{
		in >> words;
		count++;
		letter_count(words, letters);
	}
	for (int n = 0; n < 26; n++)
	{
		if (letters[n] > 0)
			cout << letters[n] << '\t' << static_cast<char>(n + 'a') << endl;
	}

	return count;
}



//*********************************************************************************************************

///********************************************************************************************************
// Name : letter_count
//Precondition: String has been intialized
//Postcondition: Will reintialize string while counting # of occurances for letters
//Description: This function will count occurances of each letter
//Purpose: Will count occurances of letters

void letter_count(string words, int letters[])
{
	

		for (int q = 0; q < words.length(); q++)
		{

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



//**********************************************************************************************************

int main()
{
	int count, letArray[26];
	ifstream inp;
	string text, words; // two strings, one for word count and one for letter occurance

	inp.open("mytext.dat");

	if (inp.fail())
	{
		cout << "Error: File did not open \n" << "Program will now exit\n";
		exit(1);
	}

	//copying all text of file to string for letter occurance
	/*getline(inp, text);*/

	// clearing eof tag and placing read line at beginning of file after getline function


	InzArray(letArray);

	count = word_count(inp, words);
	cout << count << " Words" << endl;

	inp.clear();
	inp.seekg(0, ios::beg);

	/*letter_count(text, letArray);*/

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