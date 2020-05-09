#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

/********************************************************HEADER FILE****************************************************************/

#ifndef ORDER_CLASS




#define ORDER_CLASS
class order_record
{
public:
	int processing_plant;
	string cell_number, item_number;
	double quantity, price, tax_rate, order_tax, net_cost, total_cost;
};

class order_class
{
public:
	order_class();
	order_class(const order_class&);
	~order_class();
	bool is_empty();
	bool is_full();
	int search(string key);
	void add();
	order_class& operator -(const string key);
	void double_size();
	void process();
	friend ostream& operator <<(ostream& out, order_class& org);
private:
	int count = 0;
	int size = 1;
	order_record* INV;



};

#endif ORDER_CLASS