/* 
 * File:   ProductDatabase.cpp
 * Author: jarrah
 * 
 * Created on 23 July 2014, 12:05 AM
 */

#include <string>

class ProductDatabase
{
private:
	Product *admin = new Product;
	Product *allProducts = new Product[4];
	int logicalSize;
public:
	ProductDatabase();
	addCost(int, long);
	int adminWriteOutDatabase(std::string);
	int adminWriteOutDatabase(std::string);
	int binarySearch(long);
	int delProduct(int);
	int emptyProduct();
	int findProduct(long);
	long getBarcode(int);
	std::string getDatabase(int);
	int getNumber(int);
	std::string getProduct(int);
	std::string getProductName(int);
	std::string* getProductNames();
	double getProductPrice(int);
	Product* getProductRef(int);
	std::string* getUserNames();
	int partition(int, int, bool (*test)(Product*));
	bool test(Product*, Product*);
	quickSort(int, int, int);
	bool productExists(std::string, long);
	bool productExists(long);
	int readDatabase(std::string);
	resetBills();
	resizeDatabase(bool);
	Product* resizeDatabase(bool, Product*);
	setDatabaseProduct(int, std::string, long, long, long, bool);
	setNumber(int, int);
	writeOutDatabase(std::string);
};