/* 
 * File:   PersonDatabase.cpp
 * Author: jarrah
 * 
 * Created on 22 July 2014, 11:41 PM
 */

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Person.cpp"

class PersonDatabase
{
private:
	Person admin;
	std::vector<Person> allPersons;
	int logicalSize;
	int allPersonsSize;
public:
	PersonDatabase();
	void addCost(int, long);
	int adminWriteOutDatabase(std::string);
	int binarySearch(long);
	int delPerson(int);
	int emptyPerson();
	int findPerson(long);
	long getBarCode(int);
	std::string getDatabase(int);
	std::string getPerson(int);
	std::string getPersonName(int);
	double getPersonPriceWeek(int);
	double getPersonPriceYear(int);
	std::string getPersonUser(int);
	std::string* getUserNames();
<<<<<<< HEAD
	int partition(Person*, Person*, bool(PersonDatabase::*)(Person*, Person*, bool));
	bool testName(Person*, Person*, bool);
	bool testPrice(Person*, Person*, bool);
	bool testBarCode(Person*, Person*, bool);
	void quickSort(int, int, bool(PersonDatabase::*)(Person*, Person*, bool));
=======
	int partition(Person*, Person*, bool (*)(*));
	bool testName(Person*, Person*, bool);
	bool testPrice(Person*, Person*, bool);
	bool testBarCode(Person*, Person*, bool);
	void quickSort(int, int, bool (*test)(Person*));
>>>>>>> e90bab75b2c1215403c585d5d4af4e642598b041
	bool personCanBuy(int);
	bool personExists(std::string, long);
	bool personExists(long);
	int readDatabase(std::string);
	void resetBills();
	void resizeDatabase(bool);
<<<<<<< HEAD
	std::vector<Person> resizeDatabase(bool, std::vector<Person>);
=======
	Person* resizeDatabase(bool, std::vector<Person>);
>>>>>>> e90bab75b2c1215403c585d5d4af4e642598b041
	void setAdminPassword(std::string);
	int setDatabasePerson(int, std::string, long, long, long, bool);
	void setPersonCanBuy(int, bool);
	void sortBy(int);
<<<<<<< HEAD
	int writeOutDatabase(std::string);
=======
	void writeOutDatabase(std::string);
>>>>>>> e90bab75b2c1215403c585d5d4af4e642598b041
};
PersonDatabase::PersonDatabase()
{
	allPersons = new Person[47];
	logicalSize = 0;
	allPersonsSize = 47;
}
int PersonDatabase::setDatabasePerson(int personNo, std::string name, long running, long week, long barCode, bool canBuy)
{
	int test = 1;
	if(!personExists(name, barCode)) {
		allPersons[logicalSize] = new Person(name, barCode, running, week, canBuy);
		logicalSize++;
		test = 0;
		PersonDatabase::writeOutDatabase("personDatabase.txt");
	}
	if(logicalSize >= allPersonsSize){
		allPersons = resizeDatabase(true, &allPersons);
	}
	return test;
}
std::string PersonDatabase::getDatabase(int sort)
{
	PersonDatabase::sortBy(sort);
	std::string output = "";
	for(int i = 0; i < logicalSize; i++) {
		if(allPersons[i] != '\0') {
			output += "\nPerson ";
			output += 1+i;
			output += ": \n";
			output += allPersons[i].getData();
		}
	}
	PersonDatabase::sortBy(3);
	return output;
}
std::string PersonDatabase::getPerson(int personNo)
{
	if(personNo < logicalSize) {
		return allPersons[personNo].getData();
	}
	else return "That person does not exist";
}
std::string PersonDatabase::getPersonUser(int personNo) // html probably won't be used
{
	if(personNo == -1 || personNo == -2) return "Admin";
	else if(personNo < logicalSize) {
		return allPersons[personNo].getDataUser();
	}
	else return "That person does not exist";
}
int PersonDatabase::delPerson(int personNo) 
{
	if(personNo < logicalSize) {
		for(int i = personNo; i < logicalSize; i++) {
			allPersons[i] = allPersons[i+1];
		}
		--logicalSize;
		if(allPersonsSize > 2*logicalSize){
			allPersons = resizeDatabase(false, &allPersons);
		}
		PersonDatabase::writeOutDatabase("personDatabase.txt");
		return 0;
	}
	else return 1;
}
std::string PersonDatabase::getPersonName(int personNo) 
{
	if(personNo == -2) {
		return admin.getName();
	}
	else if(personNo < logicalSize) {
		return allPersons[personNo].getName();
	}
	else return "error";
}
std::string* PersonDatabase::getUserNames() { 
	//not sure about the ptr usage of output here
	std::string* output = std::string[logicalSize];
	for(int i = 0; i < logicalSize; i++) {
		output[i] = allPersons[i].getName();
	}
	return output;
}
double PersonDatabase::getPersonPriceYear(int personNo) {
	if(personNo < logicalSize) {
		return allPersons[personNo].totalCostRunning();
	}
	else return 0;
}
double PersonDatabase::getPersonPriceWeek(int personNo) {
	if(personNo < logicalSize) {
		return allPersons[personNo].totalCostWeek();
	}
	else return 0;
}
long PersonDatabase::getBarCode(int personNo) 
{
	if(personNo < logicalSize){
		return allPersons[personNo].getBarCode();
	}
	else return 0;
}
int PersonDatabase::emptyPerson()
{
	return logicalSize; // this is not how it was implemented in java, test and revise
}
bool PersonDatabase::personExists(std::string extPersonName, long extBarCode) 
{
	for(int i = 0; i < logicalSize; i++){
		if(allPersons[i] != '\0' && allPersons[i].getName() == extPersonName && allPersons[i].getBarCode == extBarCode) {
			return true;
		}
	}
	return false;
}
bool PersonDatabase::personExists(long extBarCode) 
{
	if(extBarCode == 7000000) {
		return true;
	}
	for(int i =0; i  < logicalSize; i++) {
		if(allPersons[i] != '\0' && allPersons[i].getBarCode() == extBarCode && allPersons[i].canBuy()) {
			return true;
		}
	}
	return false;
}
PersonDatabase::resizeDatabase(bool action) 
{
	allPersons = resizeDatabase(action, &allPersons);
}
std::vector<Person> PersonDatabase::resizeDatabase(bool action, std::vector<Person> resizing) 
{
	if(action) {
		allPersonsSize += 4;
		return resizing.resize(allPersonsSize);
	}
	else if(allPersonsSize > 4) {
		allPersonsSize /=4;
		return resizing.resize(allPersonsSize);
	}
	else {
		allPersonsSize = 4;
		resizing.resize(allPersonsSize);
	}
}
int PersonDatabase::partition(int lb, int ub, bool(PersonDatabase::*)(Person*, Person*, bool))
{
	Person pivotElement = allPersons[lb];
	Person max = allPersons[logicalSize];
	int left = lb;
	int right = ub;
	Person temp;
	
	while(left < right ){
		while(test(&allPersons[left], &pivotElement) && left + 1 < max) {
			left++;
		}
		while(test(&allPersons[right], &pivotElement) && right-1 > 0) {
			right--;
		}
		if(left < right) {
			temp = allPersons[left];
			allPersons[left] = allPersons[right];
			allPersons[right] = temp;
		}
	}
	for(left = lb; left <= right && left +1 < max; left++) {
		allPersons[left] = allPersons[left+1];
	}
	allPersons[right] = pivotElement;
	return right;
}
PersonDatabase::quickSort(int left, int right, bool(PersonDatabase::*)(Person*, Person*, bool))
{
	if(left < right) {
		int pivot = partition(left, right, test);
		quickSort(left, pivot - 1, test);
		quickSort(pivot + 1, right, test);
	}
}
bool PersonDatabase::testName(Person* left, Person* right, bool lessEq)
{
	if(lessEq) {
		return (left->getName() <= right->getName());
	}
	else {
		return (left->getName() > right->getName());
	}
}
bool PersonDatabase::testPrice(Person* left, Person* right, bool lessEq)
{
	if(lessEq) {
		return (left->totalCostWeek() <= right->totalCostWeek());
	}
	else {
		return (left->totalCostWeek() > right->totalCostWeek());
	}
}
bool PersonDatabase::testBarCode(Person* left, Person* right, bool lessEq)
{
	if(lessEq) {
		return (left->getBarCode() <= right->getBarCode());
	}
	else {
		return (left->getBarCode() > right->getBarCode());
	}
}
void PersonDatabase::sortBy(int sort) {
	switch(sort) {
		case 1:
			PersonDatabase::quickSort(0, logicalSize-1, testName);
			break;
		case 2:
			PersonDatabase::quickSort(0, logicalSize-1, testPrice);
			break;
		case 3:
			PersonDatabase::quickSort(0, logicalSize-1, testBarCode);
			break;
		default:
			PersonDatabase::quickSort(0, logicalSize-1, testName);
	}
}
int PersonDatabase::writeOutDatabase(std::string path) 
{
	PersonDatabase::sortBy(1);
	std::ofstream outfile (path);
	if(outfile.is_open()) {
		outfile << "PersonDatabase File" << '\n';
		outfile << "---------------------------------------------" << '\n';
		outfile << "7000000" << '\n';
		outfile << admin.getName() << '\n';
		for(int i = 0; i < logicalSize; i++) {
			outfile << "---------------------------------------------" << '\n';
			outfile << allPersons[i].getBarCode() << '\n';
			outfile << allPersons[i].getName() << '\n';
			outfile << allPersons[i].totalCostRunning() << '\n';
			outfile << allPersons[i].totalCostWeek() << '\n';
			outfile << allPersons[i].canBuy() << '\n';
		}
		sortBy(3);
		outfile.close();
		return 0;
	}
	return 1;
}
int PersonDatabase::adminWriteOutDatabase(std::string path) 
{
	int total = 0;
	PersonDatabase::sortBy(1);
	std::ofstream outfile (path);
	if(outfile.is_open()) {
		for(int i = 0; i < logicalSize; i++) {
			outfile << "---------------------------------------------" << '\n';
			outfile << "Bar Code:	" + allPersons[i].getBarCode() << '\n';
			outfile << "Name:	" + allPersons[i].getName() << '\n';
			outfile << "Total:	$" + std::to_string(allPersons[i].totalCostRunning()) << '\n';
			outfile << "Bill:	$" + std::to_string(allPersons[i].totalCostWeek()) << '\n';
			total += allPersons[i].totalCostWeek();
		}
		outfile << "---------------------------------------------" << '\n';
		outfile << "The total for this bill is: " + std::to_string(total); << '\n';
		sortBy(3);
		outfile.close();
		return 0;
	}
	return 1;
}
int PersonDatabase::readDatabase(std::string path)
{
	std::string tempName, tempInput;
	long tempTotalCostRunning, tempTotalCostWeek;
	double doubleCosts;
	int tempBarCode;
	int count = 0;
	bool tempCanBuy;
	int z;
	std::string::size_type sz;
	std::ifstream inFile (path);
	if(inFile.is_open()) {
		std::getline(inFile, tempInput);
		std::getline(inFile, tempInput);
		std::getline(inFile, tempInput);
		tempBarCode =  std::stol(tempInput);
		std::getline(inFile, tempName);
		admin = new Person(tempName, tempBarCode, 0,0, true);
		for(z = 0; inFile.good(); z++) {
			std::getline(inFile, tempInput);
			tempBarCode =  std::stol(tempInput);
			std::getline(inFile, tempName);
			std::getline(inFile, tempInput);
			doubleCosts =  std::stod(tempInput);
			tempTotalCostRunning = (long)(doubleCosts*100);
			std::getline(inFile, tempInput);
			doubleCosts =  std::stod(tempInput);
			tempTotalCostWeek = (long)(doubleCosts*100);
			std::getline(inFile, tempInput);
			if(tempInput == "0" || tempInput == "true" || tempInput == "True" || tempInput == "TRUE") {
				tempCanBuy = true;
			}
			else tempCanBuy = false;
			count += PersonDatabase::setDatabasePerson(z, tempName, tempTotalCostRunning, tempTotalCostWeek, tempBarCode, tempCanBuy);
		}
	}
	else return -1;
	inFile.close();
	PersonDatabase::sortBy(3);
	return z-count;
}
int PersonDatabase::findPerson(long barCode) 
{
	if(7000000 == barCode) {
		return -2;
	}
	else return PersonDatabase::binarySearch(barCode);
}
int PersonDatabase::binarySearch(long extBarCode)
{
	int imax = logicalSize-1;
	int imin = 0;
	int mid;
	while (imax >= imin) {
		mid = (imax+imin)/2;
		if(allPersons[mid].getBarCode() == extBarCode) {
			return mid;
		}
		else if(allPersons[mid].getBarCode() > extBarCode) {
			imax = mid+1;
		}
		else if(allPersons[mid].getBarCode() < extBarCode) {
			imin = mid+1;
		}
	}
	return -1;
}
void PersonDatabase::addCost(int personNo, long cost) {
	allPersons[personNo].addPrice(cost);
}
void PersonDatabase::resetBills() {
	for(int i = logicalSize -1; i > 0; i--) {
		allPersons[i].resetWeekCost();
	}
}
void PersonDatabase::setAdminPassword(std::string extPassword) {
	admin.setName(extPassword);
}
bool PersonDatabase::personCanBuy(int personNumber) 
{
	return allPersons[personNumber].canBuy();
}
void PersonDatabase::setPersonCanBuy(int personNumber, bool canBuy) 
{
	allPersons[personNumber].setCanBuy(canBuy);
	writeOutDatabase("personDatabase.txt");
}