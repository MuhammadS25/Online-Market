#include <assert.h>
#include "Product.h"
#include<iostream>
#include <iomanip>

using namespace std;

 Product::Product() {
	name = "";
	price = 0;
	product_id = 0;
	seller_id = 0;
}

 Product::Product(int _id, string _name, double _price, string _category, int _seller_id) {
	 name = _name;
	 price = _price;
	 category = _category;
	 seller_id = _seller_id;
	 product_id = _id;
 }

Product::Product( int _id,string _name, double _price,string _category , int _seller_id,double rate) {	 
	name = _name;
	price = _price;
	category = _category;
	seller_id = _seller_id;
	product_id=_id;
	Product::Setrate(rate);
}

  int  Product::Getid() {
	return product_id;
}

 void Product::setId(int id)
{
	Product::product_id = id;
}

 string Product::Getname() {
	return name;
}

 double Product::Getprice() {
	return price;
}

 string Product::Getcatgory() {
	return category;
}

 int Product::Getseller_id() {
	return seller_id;
}

 float Product::Getrate() {
	double total = 0;
	for (int i = 0; i < rate.size(); i++) {
		total = total + rate[i];
	}
	return rate.size() == 0 ? total / 1  :total / rate.size() ;
}

 void Product::Setrate(double value) {
	rate.push_back(value);
}


 void Product::display(bool type) {
	 string select;
	 type ? select= to_string(seller_id) : select= to_string(Getrate());
	 cout << product_id << setw(25) << name << setw(15) << price << setw(30) << category << setw(15) << select << endl;
}