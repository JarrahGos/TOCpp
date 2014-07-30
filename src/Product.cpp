/* 
 * File:   Product.cpp
 * Author: jarrah
 * 
 * Created on 22 July 2014, 6:31 PM
 */

#include <string>

class Product {
private:
	std::string name;
	long barCode, productPriceVar;
	int numberOfItems, quantity;
public: 
	Product();
	Product(std::string, long, long);
	void decrementNmuber();
	long getBarCode();
	std::string getData();
	std::string getDataName();
	std::string getDataPrice();
	std::string getDataScreen();
	std::string getDataUser();
	std::string getName();
	int getNumber();
	int getQuantity();
	void minusNumber(int);
	long productPrice();
	void setData(std::string, long, long);
	void setName(std::string);
	void setNumber(int);
	void setPrice(long);
	void setQuantity(int);
};
Product::Product()
{
	name = "name";
	barCode = 0;
	productPriceVar = 0;
}
Product::Product(std::string extName, long extProductPrice, long extBarCode)
{
	Product::name = extName; 
	Product::barCode = extBarCode;
	Product::productPriceVar = extProductPrice;
}
void Product::setData(std::string name, long extProductPrice, long extbarCode)
{
	Product::name = name;
	Product::barCode = extbarCode;
	Product::productPriceVar = extProductPrice;
}
void Product::setNumber(int number)
{
	Product::numberOfItems = number;
}
int Product::getNumber()
{
	return Product::numberOfItems;
}
std::string Product::getData()
{
	/**
	Class Product: Method getData
	Procondition: setData has been run for invoking person or the person constructor outlined above has been run
	Postcondition: The data that has been entered for the invoking person will be returned. 
	*/
	std::string output = "";
	output += "\n	Name: ";
	output += name;
	output += "\n	Running Cost: $";
	output += (double)(productPriceVar/100);
	output += "\n	Quantity: ";
	output += numberOfItems;
	return output;
}
std::string Product::getDataScreen()
{
	std::string output = "";
	output += "\n	Product Name: ";
	output += name;
	output += " x ";
	output += quantity;
	output += "\n	Price: $";
	output += (double)((productPriceVar/100)*quantity);
	return output;
}
std::string Product::getDataUser() // html may not be needed for C++
{
	/**
	Class Product: Method getData
	Procondition: setData has been run for invoking person or the person constructor outlined above has been run
	Postcondition: The data that has been entered for the invoking person will be returned. 
	*/
	std::string output = "";
	// add handler in here if html needed
	output += "\n	Product Name: ";
	output += name;
	output += " x ";
	output += quantity;
	output += "\n	Price: $";
	output += (double)((productPriceVar/100)*quantity);
	output += "\n";
	return output;
}
std::string Product::getDataName()
{
	std::string output = "";
	output += name;
	output += " x ";
	output += quantity;
	output += "\n";
	return output;
}
std::string Product::getDataPrice()
{
	std::string output = "";
	output += "\n	Price: $";
	output += (double)((productPriceVar/100)*quantity);
	output += "\n";
	return output;
}
std::string Product::getName()
{
	return Product::name;
}
long Product::getBarCode()
{
	return Product::barCode;
}
long Product::productPrice()
{
	/**
	Class Product: Method totalCostRunning
	Precondition: setData has been run for the invoking person
	Postcondition: this method will return the price of the invoking person as a decimal double
	*/
	return Product::productPriceVar;
}
void Product::setPrice(long cost)
{
	Product::productPriceVar = cost;
}
void Product::setName(std::string extName)
{
	Product::name = extName;
}
void Product::decrementNmuber()
{
	numberOfItems--;
}
void Product::minusNumber(int sub)
{
	numberOfItems -= sub;
}
void Product::setQuantity(int quantity)
{
	Product::quantity = quantity;
}
int Product::getQuantity()
{
	return quantity;
}