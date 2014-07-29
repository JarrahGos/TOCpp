/* 
 * File:   ProductDatabase.cpp
 * Author: jarrah
 * 
 * Created on 23 July 2014, 12:05 AM
 */

#include <string>
#include <vector>
#include "Product.cpp"

class ProductDatabase
{
private:
	Product admin;
	std::vector<Product> allProducts;
	int logicalSize;
	int allProductsSize;
public:
	ProductDatabase();
	int adminWriteOutDatabase(std::string);
	int binarySearch(long);
	int delProduct(int);
	int emptyProduct();
	int findProduct(long);
	long getBarCode(int);
	std::string getDatabase(int);
	int getNumber(int);
	std::string getProduct(int);
	std::string getProductName(int);
	std::string* getProductNames();
	double getProductPrice(int);
	Product* getProductRef(int);
	std::string* getUserNames();
	int partition(int, int, bool(ProductDatabase::*)(Product*, Product*, bool));
	bool testName(Product*, Product*, bool);
	bool testBarCode(Product*, Product*, bool);
	bool testPrice(Product*, Product*, bool);
	void quickSort(int, int, bool(ProductDatabase::*)(Product*, Product*, bool));
	bool productExists(std::string, long);
	bool productExists(long);
	int readDatabase(std::string);
	void resetBills();
	void resizeDatabase(bool);
	std::vector<Product> resizeDatabase(bool, std::vector<Product>);
	int setDatabaseProduct(int, std::string, long, long);
	void setNumber(int, int);
	void sortBy(int);
	int writeOutDatabase(std::string);
};
ProductDatabase::ProductDatabase()
{
	allProducts = new Product[47];
	logicalSize = 0;
	allProductsSize = 47;
}
int ProductDatabase::setDatabaseProduct(int productNo, std::string name, long price, long barCode)
{
	int test = 1;
	if(!productExists(name, barCode)) {
		allProducts[logicalSize] = new Product(name, price, barCode);
		logicalSize++;
		test = 0;
		ProductDatabase::writeOutDatabase("productDatabase.txt");
	}
	if(logicalSize >= allProductsSize){
		allProducts = resizeDatabase(true, &allProducts);
	}
	return test;
}
std::string ProductDatabase::getDatabase(int sort)
{
	ProductDatabase::sortBy(sort);
	std::string output = "";
	for(int i = 0; i < logicalSize; i++) {
		if(allProducts[i] != '\0') {
			output += "\nProduct ";
			output += 1+i;
			output += ": \n";
			output += allProducts[i]->getData();
		}
	}
	ProductDatabase::sortBy(3);
	return output;
}
std::string ProductDatabase::getProduct(int productNo)
{
	if(productNo < logicalSize) {
		return allProducts[productNo].getData();
	}
	else return "That product does not exist";
}
int ProductDatabase::getNumber(int productNo)
{
	return allProducts[productNo].getNumber();
}
int ProductDatabase::delProduct(int productNo) 
{
	if(productNo < logicalSize) {
		for(int i = productNo; i < logicalSize; i++) {
			allProducts[i] = allProducts[i+1];
		}
		--logicalSize;
		if(allProductsSize > 2*logicalSize){
			allProducts = resizeDatabase(false, &allProducts);
		}
		ProductDatabase::writeOutDatabase("productDatabase.txt");
		return 0;
	}
	else return 1;
}
std::string ProductDatabase::getProductName(int productNo) 
{
	if(productNo == -2) {
		return admin.getName();
	}
	else if(productNo < logicalSize) {
		return allProducts[productNo].getName();
	}
	else return "error";
}
std::string* ProductDatabase::getUserNames() { 
	//not sure about the ptr usage of output here
	std::string* output = std::string[logicalSize];
	for(int i = 0; i < logicalSize; i++) {
		output[i] = allProducts[i].getName();
	}
	return output;
}
long ProductDatabase::getBarCode(int productNo) 
{
	if(productNo < logicalSize){
		return allProducts[productNo].getBarCode();
	}
	else return 0;
}
int ProductDatabase::emptyProduct()
{
	return logicalSize; // this is not how it was implemented in java, test and revise
}
bool ProductDatabase::productExists(std::string extProductName, long extBarCode) 
{
	for(int i = 0; i < logicalSize; i++){
		if(allProducts[i] != '\0' && allProducts[i].getName() == extProductName && allProducts[i].getBarCode == extBarCode) {
			return true;
		}
	}
	return false;
}
bool ProductDatabase::productExists(long extBarCode) 
{
	if(extBarCode == 7000000) {
		return true;
	}
	for(int i =0; i  < logicalSize; i++) {
		if(allProducts[i] != '\0' && allProducts[i].getBarCode() == extBarCode && allProducts[i].canBuy()) {
			return true;
		}
	}
	return false;
}
void ProductDatabase::resizeDatabase(bool action) 
{
	ProductDatabase::allProducts = resizeDatabase(action, allProducts);
}
std::vector<Product> ProductDatabase::resizeDatabase(bool action, std::vector<Product> resizing) 
{
	if(action) {
		allProductsSize += 4;
		return resizing.resize(allProductsSize);
	}
	else if(allProductsSize/2 > 4) {
		allProductsSize /=4;
		return resizing.resize(allProductsSize);
	}
	else {
		allProductsSize = 4;
		resizing.resize(allProductsSize);
	}
}
int ProductDatabase::partition(int lb, int ub, bool(ProductDatabase::*)(Product*, Product*, bool))
{
	Product pivotElement = allProducts[lb];
	int max = logicalSize;
	int left = lb;
	int right = ub;
	Product temp;
	
	while(left < right ){
		while(test(allProducts[left], pivotElement) && left + 1 < max) {
			left++;
		}
		while(test(allProducts[right], pivotElement) && right-1 > 0) {
			right--;
		}
		if(left < right) {
			temp = allProducts[left];
			allProducts[left] = allProducts[right];
			allProducts[right] = temp;
		}
	}
	for(left = lb; left <= right && left +1 < max; left++) {
		allProducts[left] = allProducts[left+1];
	}
	allProducts[right] = pivotElement;
	return right;
}
void ProductDatabase::quickSort(int left, int right, bool(ProductDatabase::*)(Product*, Product*, bool))
{
	if(left < right) {
		int pivot = partition(left, right, test);
		quickSort(left, pivot - 1, test);
		quickSort(pivot + 1, right, test);
	}
}
bool ProductDatabase::testName(Product* left, Product* right, bool lessEq)
{
	if(lessEq) {
		return (left->getName() <= right->getName());
	}
	else {
		return (left->getName() > right->getName());
	}
}
bool ProductDatabase::testPrice(Product* left, Product* right, bool lessEq)
{
	if(lessEq) {
		return (left->productPrice() <= right->productPrice());
	}
	else {
		return (left->productPrice() > right->productPrice());
	}
}
bool ProductDatabase::testBarCode(Product* left, Product* right, bool lessEq)
{
	if(lessEq) {
		return (left->getBarCode() <= right->getBarCode());
	}
	else {
		return (left->getBarCode() > right->getBarCode());
	}
}
void ProductDatabase::sortBy(int sort) {
	switch(sort) {
		case 1:
			ProductDatabase::quickSort(0, logicalSize-1, &ProductDatabase::testName);
			break;
		case 2:
			ProductDatabase::quickSort(0, logicalSize-1, &ProductDatabase::testPrice);
			break;
		case 3:
			ProductDatabase::quickSort(0, logicalSize-1, &ProductDatabase::testBarCode);
			break;
		default:
			ProductDatabase::quickSort(0, logicalSize-1, &ProductDatabase::testName);
	}
}
int ProductDatabase::writeOutDatabase(std::string path) 
{
	ProductDatabase::sortBy(1);
	std::ofstream outfile (path);
	if(outfile.is_open()) {
		outfile << "ProductDatabase File" << '\n';
		outfile << "---------------------------------------------" << '\n';
		outfile << "7000000" << '\n';
		outfile << admin.getName() << '\n';
		for(int i = 0; i < logicalSize; i++) {
			outfile << "---------------------------------------------" << '\n';
			outfile << allProducts[i].getName() << '\n';
			outfile << allProducts[i].productPrice()/100 << '\n';
			outfile << allProducts[i].getBarCode() << '\n';
			outfile << allProducts[i].getNumber() << '\n';
		}
		sortBy(3);
		outfile.close();
		return 0;
	}
	return 1;
}
int ProductDatabase::adminWriteOutDatabase(std::string path) 
{
	int total = 0;
	ProductDatabase::sortBy(1);
	std::ofstream outfile (path);
	if(outfile.is_open()) {
		for(int i = 0; i < logicalSize; i++) {
			outfile << "---------------------------------------------" << '\n';
			outfile << "Bar Code:	" + allProducts[i].getName() << '\n';
			outfile << "Name:	" + allProducts[i].productPrice() << '\n';
			outfile << "Total:	$" + allProducts[i].getBarCode() << '\n';
			outfile << "Bill:	$" + allProducts[i].getNumber() << '\n';
		}
		outfile << "---------------------------------------------" << '\n';
		outfile << "The total for this bill is: " + total; << '\n';
		sortBy(3);
		outfile.close();
		return 0;
	}
	return 1;
}
int ProductDatabase::readDatabase(std::string path)
{
	std::string tempName, tempInput;
	long tempPrice;
	double doubleCosts;
	int tempBarCode;
	int tempNumberOfProduct;
	int count = 0;
	bool negative;
	int z;
	std::string::size_type sz;
	std::ifstream inFile (path);
	if(inFile.is_open()) {
		std::getline(inFile, tempInput);
		for(z = 0; inFile.good(); z++) {
			std::getline(inFile, tempName);
			std::getline(inFile, tempInput);
			doubleCosts =  std::stod(tempInput);
			tempPrice = (long)(doubleCosts*100);
			std::getline(inFile, tempInput);
			tempBarCode =  std::stol(tempInput);
			
			std::getline(inFile, tempInput);
			if('-' == tempInput.at(0)) {
				tempInput = tempInput.substr(1,tempInput.length());
				negative = true;
			}
			tempNumberOfProduct =  std::stoi(tempInput);
			if(negative) {
				tempNumberOfProduct *= -1;
			}
			count += ProductDatabase::setDatabaseProduct(z, tempName, tempPrice, tempBarCode);
			allProducts[z].setNumber(tempNumberOfProduct);
		}
	}
	else return -1;
	inFile.close();
	ProductDatabase::sortBy(3);
	return z-count;
}
int ProductDatabase::findProduct(long barCode) 
{
	if(7000000 == barCode) {
		return -2;
	}
	else return ProductDatabase::binarySearch(barCode);
}
int ProductDatabase::binarySearch(long extBarCode)
{
	int imax = logicalSize-1;
	int imin = 0;
	int mid;
	while (imax >= imin) {
		mid = (imax+imin)/2;
		if(allProducts[mid].getBarCode() == extBarCode) {
			return mid;
		}
		else if(allProducts[mid].getBarCode() > extBarCode) {
			imax = mid+1;
		}
		else if(allProducts[mid].getBarCode() < extBarCode) {
			imin = mid+1;
		}
	}
	return -1;
}