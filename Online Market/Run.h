#pragma once
#include "LinkedList.h"
#include <iostream>
#include "Person.h"
using namespace std;


class Run
{
private:
	LinkedList<Product> Products;
	LinkedList<Product> ProductRequest;
	ArraList<string> cat;
	ArraList<Seller> Sellers;
	ArraList<Person> Admins;
	ArraList<Customer> Customers;

public:
	inline Run(void);
	inline	~Run(void);
	inline void customerRun(int);
	inline void sellerRun(int);
	inline int checkLogin(string email, int id, int type);
	inline void dispalyproductseller(int,int);
	inline void adminRun(int id);
	inline void initialrunApp();
	inline void Approvalrequest();
	inline void checkAdd(int customer_id,Customer&);
	inline void searchbyname(int customer_id, Customer& tmp);
	inline int getCustomerindex(int id);
	inline int getproductindex(int id);
	inline int checkid();
	inline void confirm(int c_index,Customer&tmp);
	inline int Login(int);
	inline int Register(int);
	inline void modifycart(int c_index,Customer&tmp);
	inline void displayCategory(int customer_id,Customer& tmp);
	inline int searchidproduct(int id_search);
	inline void addtoproducts(int sellerId);
	inline void getcategoryproducts(int choice, int,Customer&);
	// bool x(string,int ,int);
};


class Constant
{
public:
	inline Constant();
	inline ~Constant();
	
	inline void initalProduct(LinkedList<Product> &Products);
	inline void finalProduct(LinkedList<Product>& Products);
	inline void initalcategory(LinkedList<Product> Products , ArraList<string> &cat);
	inline void initalCustomer(ArraList<Customer>& Customers);
	inline void initalSeller(ArraList<Seller>& Sellers);
	inline void finalSeller(ArraList<Seller>& Sellers);
	inline void initalAdmin(ArraList<Person>& Admins);
	inline void finalAdmin(ArraList<Person>& Admins);
};
