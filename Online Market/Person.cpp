#include "Person.h"
#include<iostream>
using namespace std;
Person::Person() {}

Person::Person(int ID, string Name, string Email)
{
	id = ID;
	name = Name;
	email = Email;
}

void Person::setID(int ID)
{
	id = ID;
}

void Person::setName(string Name)
{
	name = Name;
}

void Person::setEmail(string Email)
{
	email = Email;
}

int Person::getID()
{
	return id;
}

string Person::getName()
{
	return name;
}

string Person::getEmail()
{
	return email;
}

void Person::display()
{
	cout << "Name: " << name << endl;
	cout<<   "ID: " << id << endl;
	cout << "Email: " << email << endl;
}

Seller::Seller()
{
}

Seller::Seller(int ID, string Name, string Email) :Person(ID, Name, Email)
{
	id = ID;
	name = Name;
	email = Email;
}

void Seller::display()
{
	Person::display();
}

Customer::Customer()
{
//	Product p;
//	CustomerCart.append(p);
}

Customer::Customer(int ID, string Name, string Email, string Address, string PN):Person(ID,Name,Email)
{
	address = Address;
	PhoneNumber = PN;
}

void Customer::setAddress(string Address)
{
	address = Address;
}

void Customer::setPhoneNumber(string PN)
{
	PhoneNumber = PN;
}

string Customer::getAddress()
{
	return address;
}

string Customer::getPhoneNumber()
{
	return PhoneNumber;
}

void Customer::addProduct(Product p)
{
	CustomerCart.push_back(p);
}

void Customer::display()
{
	Person::display();
	cout << "Phone Number = " << PhoneNumber << endl;
	cout << " Address = " << address << endl;
}

double Customer::getTotal() {
	double total = 0.0;
	for (int i = 0; i < CustomerCart.size(); i++)
	{
		total += CustomerCart.at(i).Getprice();
	}
	return total;
}

void Customer::em()
{
	CustomerCart.clear();
}

vector<Product> Customer::getVector()
{
	return CustomerCart;
}
