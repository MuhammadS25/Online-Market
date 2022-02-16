#pragma once
#include <iostream>
#include <string>
#include<vector>
using namespace std;

class Product
{
	

private:
	string name;
	double price;
	string category;
	int seller_id;
	vector<int> rate;
	int product_id;
	 
public:
	inline Product();
	inline Product(int, string, double, string, int);
	inline Product(int,string, double, string,int,double);
	inline	int  Getid();
	inline void setId(int);
	inline string Getname();
	inline double Getprice();
	inline string Getcatgory();
	inline int Getseller_id();
	inline float Getrate();
	inline void Setrate(double);
	inline	void display(bool);
};