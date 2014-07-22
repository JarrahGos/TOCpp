/*
 * File:   main.cpp
 * Author: jarrah
 *
 * Created on 22 July 2014, 5:40 AM
 */

#include <QApplication>
#include <string>

class Person {
private:
	std::string name;
	long totalCostRunning, totalCostWeek, barCode;
	bool canBuy;
public: 
	Person(std::string, long, long, long, bool);
	addPrice(long);
	bool canBuy();
	long getBarCode();
	std::string getData();
	std::string getDataUser();
	std::string getName();
	resetWeekCost();
	setCanBuy(bool);
	setData(std::string, int, bool);
	setName(std::string);
	double totalCostRunning();
	double totalCostWeek();
};
Person::Person(std::string extName, long extBarCode, long running, long week, bool extCanBuy)
{
	Person::name = extName; 
	Person::barCode = extBarCode;
	Person::totalCostRunning = running;
	Person::totalCostWeek = week;
	Person::canBuy = extCanBuy;
}
Person::setData(std::string name, long extbarCode, bool extCanBuy)
{
	Person::name = name;
	Person::barCode = extbarCode;
	Person::canBuy = extCanBuy;
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
	output += (double)(totalCostRunning/100);
	output += "\n	Bill Cost: $";
	output += (double)totalCostWeek/100;
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
	output += (double)totalCostRunning/100;
	output += "\n	Current Bill total: $"; 
	output += (double)totalCostWeek/100;
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
	return (double)totalCostRunning/100;
}
double Person::totalCostWeek()
{
	/**
	Class Person: Method totalCostRunning
	Precondition: setData has been run for the invoking person
	Postcondition: this method will return the price of the invoking person as a decimal double.
	*/
	return (double)totalCostWeek/100;
}
Person::addPrice(long cost)
{
	Person::totalCostRunning += cost;
	Person::totalCostWeek += cost;
}
Person::setName(std::string extName)
{
	Person::name = extName;
}
bool Person::canBuy()
{
	return Person::canBuy;
}
Person::setCanBuy(bool extCanBuy)
{
	Person::canBuy = extCanBuy;
}
int main(int argc, char *argv[]) {
	// initialize resources, if needed
	// Q_INIT_RESOURCE(resfile);

	QApplication app(argc, argv);

	// create and show your widgets here

	return app.exec();
}
