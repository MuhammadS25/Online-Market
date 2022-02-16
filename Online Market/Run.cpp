#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "Run.h"
#include "LinkedList.cpp"
#include "Product.cpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>

using namespace std;

Run::Run()
{
}

Run::~Run()
{
}

void Run::customerRun(int id)
{
	int customer_operation;
	while (true)
	{
		int C_index = getCustomerindex(id);
		Customer tmp = Customers.at(C_index);
		cout << "press 1 to Search by Category Name" << endl;
		cout << "press 2 to Search by Name" << endl;
		cout << "press 3 to Browse All Products" << endl;
		cout << "press 4 to Modify Your Cart" << endl;
		cout << "press 5 to Confirm Buy proccess" << endl;
		cout << "press 6 to Logout" << endl;
		cin >> customer_operation;
		if (customer_operation == 1) {
			displayCategory(id, tmp);
		}
		else if (customer_operation == 2) {
			searchbyname(id, tmp);
		}
		else if (customer_operation == 3) {
			dispalyproductseller(1, -1);
			checkAdd(id, tmp);
		}
		else if (customer_operation == 4) {
			modifycart(id, tmp);
		}
		else if (customer_operation == 5) {
			confirm(id, tmp);
		}

		Customers.insertAt(C_index, tmp);

		if (customer_operation == 6) break;

	}
	cout << "**********************_Thank you_**********************" << endl;
}

void Run::sellerRun(int id )
{
	int seller_operation;

	while (true)
	{
		cout << "press 1 to Add Product" << endl;
		cout << "press 2 to Display your product " << endl;
		cout << "press 3 to Logout " << endl;
		cin >> seller_operation;
		if (seller_operation == 1) {
			addtoproducts(id);
		}
		else if (seller_operation == 2) {
			dispalyproductseller(0, id);
		}
		else break;
	}
	cout << "**********************_Thank you_**********************" << endl;
}

void Run::adminRun(int id) {
	int admin_operation;
	while (true)
	{
		cout << "press 1 to approval pending " << endl;
		cout << "press 2 to Logout " << endl;
		cin >> admin_operation;
		if (admin_operation == 1) {
			Approvalrequest();
		}else break;
	}
	cout << "**********************_Thank you_**********************" << endl;
}

  void Run::initialrunApp()
{
	Constant c;
	int select, type;
	int id = -1;
	bool flagselect = false;
	c.initalProduct(Run::Products);
	c.initalCustomer(Run::Customers);
	c.initalSeller(Run::Sellers);
	c.initalcategory(Products, cat);
	c.initalAdmin(Admins);

	while (true)
	{
		cout << "*********************" << " Welcome in Our system " << "*********************" << endl;
		cout << "press 1 if you seller" << endl;
		cout << "press 2 if you customer" << endl;
		cout << "press 3 if you Admins" << endl;
		cout << "press 4 to Exit..!!" << endl;
		cin >> select;
		if (select == 1 || select == 2 || select == 3) {
			type = 0;
			cout << "press 1 to login" << endl;
			cout << "press 2 to register" << endl;
			cin >> type;
			if (type == 1) {
				id = Login(select);
				flagselect = true;
			}
			else if (type == 2) {
				id = Register(select);
				flagselect = true;
			}
			else cout << "invalid choice" << endl;

			if (flagselect) {
				if (select == 1) sellerRun(id);
				else if (select == 2)customerRun(id);
				else if (select == 3) adminRun(id);
			}
			select = -1;
		}
		else if (select == 4) { break; }
		else {
			cout << "Please,Try Again..!!" << endl;
			select = -1;
		}
	}
	c.finalAdmin(Admins);
	c.finalProduct(Products);
	c.finalSeller(Sellers);
	cout << "**********************_Thank you,We want to know your Feedback_**********************" << endl;
}

  void Run::Approvalrequest() {
	  int seletion;
	  if(ProductRequest.length() > 0 ){
		for (int i = 0; i < ProductRequest.length(); i++)
		{
			cout << "________________________________________________________________________________________" << endl;
			cout << "Product ID" << setw(20) << "Product Name" << setw(20) << "Product Price" << setw(20) << "Product Category" << setw(20) << "Seller Id" << endl;
			cout << "________________________________________________________________________________________" << endl;
			ProductRequest.at(i).display(true);
			cout << "Press 1 to Accept this product " << endl;
			cout << "Press 2 to Reject this product " << endl;
			cin >> seletion;
			if (seletion == 1) { 
				Product p = ProductRequest.at(i);
				Products.append(p);
				ProductRequest.deleteAt(i);
				cout << "Product adds to his list " << endl;
			}
			else if (seletion == 2) {
				ProductRequest.deleteAt(i);
				cout << "Product deletes from his list " << endl;
			}
			else cout << "No change happens..!!" << endl;
			cout << "________________________________________________________________________________________" << endl;
		}
	  }
	  else {
		  cout << "there are not Request...!!" << endl;
	  }
  }

  void Run::confirm(int c_index,Customer&tmp)
{
	float total = 0;
	c_index = getCustomerindex(c_index);
	if (Customers.at(c_index).CustomerCart.size() == 0) { cout << "******" << "Your Cart is Empty...!!"<<"******" << endl; }
	else{
	cout << "************************************-Your Receipt-************************************" << endl;
	//////////
	time_t now = time(0);
	tm* ltm = localtime(&now);
	// print various components of tm structure.
	cout << "Year: " << 1900 + ltm->tm_year << '\t' << "Month: " << 1 + ltm->tm_mon << '\t' << "Day: " << ltm->tm_mday << endl;
	cout << "Time: " << ltm->tm_hour << ":";
	cout << ltm->tm_min << ":";
	cout << ltm->tm_sec << endl;
	///////
	cout<<"Customer information : " <<endl;
	Customers.at(c_index).display();
	cout << "Your products in the cart are : \n";
	cout << "________________________________________________________________________________________" << endl;
	cout << "Product ID" << setw(20) << "Product Name" << setw(20) << "Product Price" << setw(20) << "Product Category" << setw(20) << "Product Rate" << endl;
	cout << "________________________________________________________________________________________" << endl;
		for (int i = 0; i < Customers.at(c_index).CustomerCart.size(); i++)
		{
			Customers.at(c_index).CustomerCart.at(i).display(false);
			 total += Customers.at(c_index).CustomerCart.at(i).Getprice();
		}
	cout << "The  total cost for your products is equal : " << total << endl;
	cout << " Do you want to confirm your cart? " << endl;
	cout << " Press y to confirm " << endl;
	char ans;
	cin >> ans;
//	cout << "SIZE  " << Customers.at(c_index).CustomerCart.size() << endl;
		if (ans == 'y' || ans == 'Y')
		{
			cout << "Done **\n";
			tmp = Customers.at(c_index);
			tmp.em();
			Customers.deletAt(c_index);
			Customers.insertAt(c_index, tmp);
			cout << "************************************-Thank You-************************************" << endl;
			//cout << "SIZE  " << Customers.at(c_index).CustomerCart.size() << endl;
		}

	}
}
	
  int Run::Login(int type) {
	  string email="";
	  int id= -1;
	  while (true)
	  {
		  cout << "Enter Your Email" << endl;
		  cin >> email;
		  cout << "Enter Your ID" << endl;
		  cin >> id;
		 // cout << email << "    " << id << "     " << type << endl;
		if (checkLogin(email,id,type) == 1 ) return id;
		  cout << "Please,Try again" << endl;
		  cout << "*****************************" << endl;
	  }
  }

  void Run::checkAdd(int customer_id,Customer &tmp) {
	  char anwser;
	  int pid = -1;
	  customer_id = getCustomerindex(customer_id);
	  cout << "Do You want Add any product to your cart ?? or Make Rate ??" << endl;
	  cout << "Enter Y to go ahead " << endl;
	  cin >> anwser;
	  while (anwser == 'Y' || anwser == 'y')
	  {
		  pid = -1;
		  cout << "Enter Product ID,Plz" << endl;
		  try
		  {
			  cin >> pid;
			  if (std::cin.fail())
				  throw 1;
			  pid = getproductindex(pid);

		  }
		  catch (int err)
		  {
			  cout << "You Should enter Integer Number.Please try again"  << endl;
			  // report here according to err
		  }
		  if (pid >= 0) {
			  int choice;
			  cout << "Press 1 to Add to your Cart" << endl;
			  cout << "Press 2 to Rate product" << endl;
			  cin >> choice;
			  if(choice == 1 ){
				  tmp.addProduct(Products.at(pid));
				  cout << "Successfully Process" << endl;
			  }
			  else if (choice == 2) {
				  Product tmpProduct = Products.at(pid);
				  int rate;
				  cout << "________________________________________________________________________________________" << endl;
				  cout << "Product ID" << setw(20) << "Product Name" << setw(20) << "Product Price" << setw(20) << "Product Category" << setw(20) << "Product Rate" << endl;
				  cout << "________________________________________________________________________________________" << endl;
				  Products.at(pid).display(false);
				  cout << "Enter Rate (1 to 10 )" << endl;
				  cin >> rate;
				  tmpProduct.Setrate(rate);
				  cout << "index is : " << pid << endl ;
				  Products.deleteAt(pid);
				  Products.insertAt(pid, tmpProduct);
				  cout << "Successfully Process" << endl;
			  }
		 }
		  else {
			  cout << "Invalid choice" << endl;
		  }

		  cout << "Do You want to continue ??" << endl;
		  cout << "Enter Y to go ahead " << endl;
		  cin >> anwser;
	  }
  }

  void Run::searchbyname(int customer_id, Customer& tmp) {
	  string name;
	  int choice;
	  cout << "press 1 to search by full Name \n";
	  cout << "press 2 to search by first lettter \n";
	  cin >> choice;
	  if(choice == 1) {
	  cout << "Enter Product name \n";
	  cin >> name;
	  for (int i = 0; i < Products.length(); i++)
	  {
		  if (name == Products.at(i).Getname()) {
			  tmp.addProduct(Products.at(i));
			  cout << "Successfully Process" << endl;
			  return;
		  }
	  }
	  cout << "sorry product not found..! \n";
	  }
	  else if (choice == 2) {
		  char ch;
		  bool flag=false;
		  cout << "Enter first letter \n";
		  cin >> ch;
		  for (int i = 0; i < Products.length(); i++)
		  {
			  if (ch == Products.at(i).Getname()[0] ) {
				  cout << "________________________________________________________________________________________" << endl;
				  cout << "Product ID" << setw(20) << "Product Name" << setw(20) << "Product Price" << setw(20) << "Product Category" << setw(20) << "Product Rate" << endl;
				  cout << "________________________________________________________________________________________" << endl;
				  Products.at(i).display(false);
				  cout << "________________________________________________________________________________________" << endl;
				  flag = true;
			  }
		  }

		  if (flag) {
		  checkAdd(customer_id, tmp); 
		  }
	  }
  }

  int Run::Register(int type) {
	  string email, name, address, pn;
	  int id=-1;
	  if (type == 1) {
		  cout << "Enter Your Email" << endl;
		  cin >> email;
		  cout << "Enter Your ID" << endl;
		  cin >> id;
		  cout << "Enter Your Name" << endl;
		  cin >> name;
		  Seller s(id, name, email);
		  Sellers.append(s);
		  cout << "Done" << endl;
	  }
	  else if (type == 2) {
		  cout << "Enter Your Email" << endl;
		  cin >> email;
		  cout << "Enter Your ID" << endl;
		  cin >> id;
		  cout << "Enter Your Name" << endl;
		  cin >> name;
		  cout << "Enter Your Address" << endl;
		  cin >> address;
		  cout << "Enter Your Phone Number" << endl;
		  cin >> pn;
		  Customer c(id, name, email, address, pn);
		  Customers.append(c);
		  cout << "Done" << endl;
	  }
	  else if (type == 3 ) {
		  cout << "Enter Your Email" << endl;
		  cin >> email;
		  cout << "Enter Your ID" << endl;
		  cin >> id;
		  cout << "Enter Your Name" << endl;
		  cin >> name;
		  Person p(id, name, email);
		  Admins.append(p);
		  cout << "Done" << endl;
	  }
	  return id;
  }

  inline void Run::modifycart(int c_index, Customer& tmp)
  {
	  int productID;
	  char ans;
	  vector<Product>::iterator it;
	  vector<Product> v = tmp.getVector();
	  c_index = getCustomerindex(c_index);

	  cout << "________________________________________________________________________________________" << endl;
	  cout << "Product ID" << setw(20) << "Product Name" << setw(20) << "Product Price" << setw(20) << "Product Category" << setw(20) << "Product Rate" << endl;
	  cout << "________________________________________________________________________________________" << endl;
	  for (int i = 0; i < Customers.at(c_index).CustomerCart.size(); i++)
	  {
		  Customers.at(c_index).CustomerCart.at(i).display(false);
	  }
	  cout << "________________________________________________________________________________________" << endl;
	  cout << " Do you want to Delete item from your cart? " << endl;
	  cout << " Press y to confirm " << endl;
	  cin >> ans;
	  while (ans == 'Y' || ans == 'y')
	  {
		 // cout << "Len  " << Customers.at(c_index).CustomerCart.size() << endl;
		  cout << "Please,Enter Product ID that's want to delete" << endl;
		  cin >> productID;
		  for (int i = 0; i < v.size(); i++)
		  {
			  //v.at(i).Getid(); 
			  if (v.at(i).Getid() == productID) {
				  it = v.begin() + i;
				  cout << " I    " << i << endl;
				  v.erase(it);
				  cout << "It'e delete successfully" << endl;
				  break;
			  }
		  }
	//	  cout << "Len  " << Customers.at(c_index).CustomerCart.size() << endl;
		  cout << " Do you want to Continue ? " << endl;
		  cout << " Press y to confirm " << endl;
		  cin >> ans;
	  }

	  tmp.em();
	  for (int i = 0; i < v.size(); i++)
	  {
		  tmp.CustomerCart.push_back(v[i]);
	  }
	  Customers.deletAt(c_index);
	  Customers.insertAt(c_index, tmp);

  }
  
  void Run::getcategoryproducts(int choice, int customer_id,Customer &tmp) {
	 
	 string category = cat.at(--choice);
	 cout << "**************************************************************" << endl;
	 for (int i = 0; i < Products.length(); i++)
	 {
		 if (category == Products.at(i).Getcatgory()) {
			 Products.at(i).display(false);
		 }
	 }
	 cout << "**************************************************************" << endl;
	 checkAdd(customer_id,tmp);

 }
   
 int Run::searchidproduct(int id_search) {//

	for (int i = 0; i < Products.length(); i++) {
		if (Products.at(i).Getid() == id_search) {
			return -1;
		}
	}

	return id_search;

}

 int Run::checkid() { //
	int id;
	while (true)
	{
		cout << "Enter Product Id" << endl;
		cin >> id;
		id = searchidproduct(id);
		if (id != -1) break;
		cout << "Please,Try again..!!" << endl;
	}
	return id;
 }

 void Run::addtoproducts(int sellerId) //
{
	string PName, Pcategory;
	double PPrice;
	int PId;
	cout << "Enter Product Name" << endl;
	cin >> PName;
	cout << "Enter Product Category" << endl;
	cin >> Pcategory;
	cout << "Enter Product Price" << endl;
	cin >> PPrice;
	PId = checkid();
	Product p(PId, PName, PPrice, Pcategory, sellerId);
	ProductRequest.append(p);
	cout << "\n Well done, Product is added to Waite list " << endl;

}

 int Run::checkLogin(string email,int id,int type)
 {
	 if (type == 1) {
		 for (int i = 0; i < Sellers.length(); i++)
		 {
			 if (email == Sellers.at(i).getEmail() && id == Sellers.at(i).getID()) return 1;
		 }
	 }
	 else if (type == 2) {
		 for (int i = 0; i < Customers.length(); i++)
		 {
			 if (email == Customers.at(i).getEmail() && id == Customers.at(i).getID()) return 1;
		 }
	 }
	 else if (type == 3) {
		 for (int i = 0; i < Admins.length(); i++)
		 {
			 if (email == Admins.at(i).getEmail() && id == Admins.at(i).getID()) return 1;
		 }
	 }


	 return 0;
 }

 void Run::displayCategory(int customer_id,Customer &tmp) //
{
	int choice;
	for (int j = 0; j < cat.length(); j++)
	{
		cout << j + 1 << ") " << cat.at(j) << endl;
	}
	while (true)
	{
		cout << "Enter your choice" << endl;
		cin >> choice;
		if (choice > 0 && choice <= cat.length() ) {
				 getcategoryproducts(choice,customer_id,tmp);
				 break;
		}
		else {
			cout << "Please,Try again" << endl;
		}
	}
}

 void Run::dispalyproductseller(int type,int seller_id) {

	cout << "________________________________________________________________________________________" << endl;
	cout << "Product ID" << setw(20) << "Product Name" << setw(20) << "Product Price" << setw(20) << "Product Category" << setw(20) << "Product Rate" << endl;
	cout << "________________________________________________________________________________________" << endl;
	for (int i = 0; i < Products.length(); i++) {
		if (type == 0) {
			if (seller_id == Products.at(i).Getseller_id()) {
				Products.at(i).display(false);
			}
		}
		else if (type == 1) {
			Products.at(i).display(false);
		}
	}
	cout << "________________________________________________________________________________________" << endl;
}

 int Run::getCustomerindex(int id) {

	 for (int i = 0; i < Customers.length(); i++) {
		 if (Customers.at(i).getID() == id) {
			 return i;
		 }
	 }
	 return -1;
 }

 int Run::getproductindex(int id) {

	 for (int i = 0; i < Products.length(); i++) {
		 if (Products.at(i).Getid() == id) {
			 return i;
		 }
	 }
	 return -1;
 }

// COnstant Class

 Constant::Constant()
{
}

 Constant::~Constant()
{
}

void Constant::initalProduct(LinkedList<Product>& Products)
{
	string P_name, P_category;
	int P_id, S_id;
	double P_price;
	double rate;
	ifstream ProductsFile("ProductsFile.txt");
	while (ProductsFile >> P_id >> P_name >>  P_price >> P_category >>  S_id >> rate) {
		Product p(P_id,P_name , P_price ,P_category,S_id,rate);
		Products.append(p);
	}
	ProductsFile.close();
	//cout << "LEN " << Products.length() << endl;
}

void Constant::finalProduct(LinkedList<Product>& Products)
{
//	cout << "LEN " << Products.length() << endl;
	ofstream ProductsFile("ProductsFile.txt");
	for (int i = 0; i < Products.length(); i++)
	{
		ProductsFile << Products.at(i).Getid() << " " << Products.at(i).Getname() << " " << Products.at(i).Getprice() << " " << Products.at(i).Getcatgory() << " " << Products.at(i).Getseller_id() << " " <<Products.at(i).Getrate()<< endl;
	}
	ProductsFile.close();
}

void Constant::initalcategory(LinkedList<Product> Products, ArraList<string>& cat)
{
	bool flag;
	for (int i = 0; i < Products.length(); i++)
	{
		flag = false;
		for (int j = 0; j < cat.length(); j++)
		{
			if (Products.at(i).Getcatgory() == cat.at(j)) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			cat.append(Products.at(i).Getcatgory());
		}
	}
}

void Constant::initalCustomer(ArraList<Customer>& Customers) {
	/*string C_name, C_email, C_address, C_phone;
	int  C_id;
	vector<Product> p;
	string P_name, P_category;
	int P_id, S_id;
	double P_price;
	ifstream CustomerFile("CustomerFile.txt");
	while (CustomerFile >> C_id >> C_name >> C_email >> C_address >> C_phone >> p) {
		Customer s(C_id, C_name, C_email,C_address,C_phone, p);
		Customers.append(s);
	}
	CustomerFile.close();
	*/
	
	Customer c1(100, "customer1", "cust1@.com", "cario", "01156301051");
	Customer c2(200, "customer2", "cust2@.com", "alex", "01276215277");
	Customer c3(300, "customer3", "cust3@.com", "aswan", "0114659455");
	Customers.append(c1);
	Customers.append(c2);
	Customers.append(c3);
}

void Constant::initalSeller(ArraList<Seller>& Sellers) {
	string S_name, S_email;
	int  S_id;
	ifstream SellersFile("SellersFile.txt");
	while (SellersFile >> S_id >> S_name >> S_email) {
		Seller s(S_id, S_name, S_email);
		Sellers.append(s);
	}
	SellersFile.close();

/*	Seller s1(1, "seller1", "sel1@.com");
	Seller s2(2, "seller2", "sel2@.com");
	Seller s3(3, "seller3", "sel3@.com");
	Sellers.append(s1);
	Sellers.append(s2);
	Sellers.append(s3);*/

}

 void Constant::finalSeller(ArraList<Seller>& Sellers)
{
	//cout << "IN Fun " << endl;
	ofstream SellersFile("SellersFile.txt");
	for (int i = 0; i < Sellers.length(); i++)
	{
		SellersFile << Sellers.at(i).getID() << " " << Sellers.at(i).getName() << " " << Sellers.at(i).getEmail() << endl;
	}
	SellersFile.close();
	//cout << "Done " << endl;

}

 inline void Constant::initalAdmin(ArraList<Person>& Admins)
 {
	 string S_name, S_email;
	 int  S_id;
	 ifstream AdminsFile("AdminsFile.txt");
	 while (AdminsFile >> S_id >> S_name >> S_email) {
		 Person p(S_id, S_name, S_email);
		 Admins.append(p);
	 }
	 AdminsFile.close();
 }

 inline void Constant::finalAdmin(ArraList<Person>& Admins)
 {
	 ofstream AdminsFile("AdminsFile.txt");
	 for (int i = 0; i < Admins.length(); i++)
	 {
		 AdminsFile << Admins.at(i).getID() << " " << Admins.at(i).getName() << " " << Admins.at(i).getEmail() << endl;
	 }
	 AdminsFile.close();

 }
