// Maximum_Pairwise_Product.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MaxPairwiseProduct(const vector <int>& numbers)
{
	int product = 0;
	int n = numbers.size();

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			product = max(product, numbers[i] * numbers[j]);
		}
	}
	return product;
}



int main()
{
	int n;
	cin >> n;
	vector <int> numbers(n);
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}
	
	int product = MaxPairwiseProduct(numbers);

	cout << product << endl;

	return 0;
}