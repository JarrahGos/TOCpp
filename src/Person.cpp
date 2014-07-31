/*
 * File:   main.cpp
 * Author: jarrah
 *
 * Created on 22 July 2014, 5:40 AM
 */

#include <string>

class Person {
private:
	std::string name;
	long costRunning, costWeek, barCode;
	bool userCanBuy;
public: 
	Person();
	Person(std::string, long, long, long, bool);
	void addPrice(long);
	bool canBuy();
	long getBarCode();
	std::string getData();
	std::string getDataUser();
	std::string getName();
	void resetWeekCost();
	void setCanBuy(bool);
	void setData(std::string, long, bool);
	void setData(std::string, long, long, long, bool);
	void setName(std::string);
	double totalCostRunning();
	double totalCostWeek();
};
Person::Person()
{
	Person::name = "name"; 
	Person::barCode = 0;
	costRunning = 0;
	costWeek = 0;
	userCanBuy = false;
}
Person::Person(std::string extName, long extBarCode, long running, long week, bool extCanBuy)
{
	Person::name = extName; 
	Person::barCode = extBarCode;
	costRunning = running;
	costWeek = week;
	userCanBuy = extCanBuy;
}
void Person::setData(std::string name, long extbarCode, bool extCanBuy)
{
	Person::name = name;
	Person::barCode = extbarCode;
	Person::userCanBuy = extCanBuy;
}
void Person::setData(std::string name, long extbarCode, long running, long week, bool extCanBuy)
{
	Person::name = name;
	Person::barCode = extbarCode;
	Person::userCanBuy = extCanBuy;
	Person::costRunning = running;
	Person::costWeek = week;
}
std::string Person::getData()
{
	/**
	Class Person: Method getData
	Procondition: setData has been run for invoking person or the person constructor outlined above has been run
	Postcondition: The data that has been entered for the invoking person will be returned. 
	*/
	std::string output = "";
	output += "\n	Name: ";
	output += name;
	output += "\n	Running Cost: $";
	output += (double)(costRunning/100);
	output += "\n	Bill Cost: $";
	output += (double)costWeek/100;
	return output;
}
std::string Person::getDataUser() // html may not be needed for C++
{
	/**
	Class Person: Method getData
	Procondition: setData has been run for invoking person or the person constructor outlined above has been run
	Postcondition: The data that has been entered for the invoking person will be returned. 
	*/
	std::string output = "";
	// add handler in here if html needed
	output += name;
	output += "\n	Running Cost: $";
	output += (double)costRunning/100;
	output += "\n	Current Bill total: $"; 
	output += (double)costWeek/100;
	return output;
}
std::string Person::getName()
{
	return Person::name;
}
long Person::getBarCode()
{
	return Person::barCode;
}
double Person::totalCostRunning()
{
	/**
	Class Person: Method totalCostRunning
	Precondition: setData has been run for the invoking person
	Postcondition: this method will return the price of the invoking person as a decimal double
	*/
	return (double)costRunning/100;
}
double Person::totalCostWeek()
{
	/**
	Class Person: Method totalCostRunning
	Precondition: setData has been run for the invoking person
	Postcondition: this method will return the price of the invoking person as a decimal double.
	*/
	return (double)costWeek/100;
}
void Person::addPrice(long cost)
{
	Person::costRunning += cost;
	Person::costWeek += cost;
}
void Person::setName(std::string extName)
{
	Person::name = extName;
}
bool Person::canBuy()
{
	return Person::userCanBuy;
}
void Person::setCanBuy(bool extCanBuy)
{
	Person::userCanBuy = extCanBuy;
}
