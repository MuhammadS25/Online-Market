#pragma once
#include<string>
#include "ArraList.cpp"
#include "Product.h"
using namespace std;
class Person
{
protected:
	int id;
	string name, email;
public:
	 Person(void);
	 Person(int ID, string Name, string Email);
	void setID(int ID);
	void setName(string Name);
	void setEmail(string Email);
	int getID(void);
	string getEmail();
	string getName();
	virtual void display();

};
class Seller :public Person
{
public:
	Seller(void);
	 Seller(int ID, string Name, string Email);
	inline	void display();
};
class Customer :public Person
{
public:
	string address, PhoneNumber;
	vector<Product>CustomerCart;
public:
	 Customer(void);
	 Customer(int ID, string Name, string Email, string Address, string PN);
inline	void setAddress(string Address);
inline	void setPhoneNumber(string PN);
inline	string getAddress();
inline	string getPhoneNumber();
void addProduct(Product p);
inline	void display();
inline double getTotal();
void em();
vector<Product> getVector();
};