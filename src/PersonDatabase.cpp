/* 
 * File:   PersonDatabase.cpp
 * Author: jarrah
 * 
 * Created on 22 July 2014, 11:41 PM
 */

#include <string>

class PersonDatabase
{
private:
	Person *admin = new Person;
	Person *allPersons = new Person[4];
	int logicalSize;
public:
	PersonDatabase();
	addCost(int, long);
	int adminWriteOutDatabase(std::string);
	int binarySearch(long);
	int delPerson(int);
	int emptyPerson();
	int findPerson(long);
	long getBarcode(int);
	std::string getDatabase(int);
	std::string getPerson(int);
	std::string getPersonName(int);
	double getPersonPriceWeek(int);
	double getPersonPriceYear(int);
	std::string getPersonUser(int);
	std::string* getUserNames();
	int partition(int, int, bool (*test)(Person*));
	bool test(Person*, Person*);
	quickSort(int, int, int);
	bool personCanBuy(int);
	bool personExists(std::string, long);
	bool personExists(long);
	int readDatabase(std::string);
	resetBills();
	resizeDatabase(bool);
	Person* resizeDatabase(bool, Person*);
	setAdminPassword(std::string);
	setDatabasePerson(int, std::string, long, long, long, bool);
	setPersonCanBuy(int, bool);
	writeOutDatabase(std::string);
};