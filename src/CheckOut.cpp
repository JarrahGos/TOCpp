/* 
 * File:   CheckOut.cpp
 * Author: jarrah
 * 
 * Created on 28 July 2014, 10:54 PM
 */

/* 
 * File:   CheckOut.cpp
 * Author: jarrah
 * 
 * Created on 28 July 2014, 7:36 PM
 */

#include <string>
#include <vector>
#include "Product.cpp"

class CheckOut 
{
private: 
	int logicalSize;
	std::vector<Product> products;
	std::vector<int> productQuantities;
	long totalPrice;
	int productsSize, quantitiesSize;
public:
	CheckOut();
	int addProduct(Product, int);
	int addProduct(std::string, long, int);
	void addQuantity(int, int);
	void delProduct(int);
	int emptyProduct();
	std::string getCheckOut(int);
	std::string* getCheckOutNames();
	std::string* getCheckOutPrices();
	long getPrice();
	int partition(int, int, bool(CheckOut::*)(Product*, Product*, bool));
	bool testName(Product*, Product*, bool);
	bool testBarCode(Product*, Product*, bool);
	bool testPrice(Product*, Product*, bool);
	void productBought();
	int productEqualTo(long extBarCode);
	void quickSort(int, int, bool(CheckOut::*)(Product*, Product*, bool));
	std::vector<Product> resizeCheckOut(bool, std::vector<Product>);
	std::vector<int> resizeQuantities(bool, std::vector<int>);
	void sortBy(int);
};
CheckOut::CheckOut()
{
	products = new Product[4];
	productQuantities = new int[4];
	logicalSize = 0;
	productsSize = 4;
	totalPrice = 0;
	quantitiesSize = 4;
}
int CheckOut::addProduct(Product item, int quantity)
{
	if(logicalSize == productsSize) {
		products = resizeCheckOut(true, products);
		productQuantities = resizeQuantities(true, productQuantities);
	}
	item.setQuantity(quantity);
	products[logicalSize] = item;
	productQuantities[logicalSize] = quantity;
	totalPrice += item.productPrice()*quantity;
	++logicalSize;
	return 0;
}
int CheckOut::addProduct(std::string name, long price, int barCode)
{
	if(logicalSize == productsSize) {
		products = resizeCheckOut(true, products);
		productQuantities = resizeQuantities(true, productQuantities);
	}
	products[logicalSize] = new Product (name, price, barCode);
	totalPrice += price;
	productQuantities[logicalSize] = 1;
	logicalSize++;
	return 0;
}
std::string CheckOut::getCheckOut(int sort)
{
	CheckOut::sortBy(sort);
	std::string output = "";
	for(int i = 0; i < logicalSize; i++) {
		output += products[i].getDataUser();
	}
	return output;
}
std::string* CheckOut::getCheckOutNames()
{
	std::string* output = new std::string[logicalSize];
	for(int i = 0; i < logicalSize; i++) {
		output[i] = products[i].getDataName();
	}
	return output;
}
std::string* CheckOut::getCheckOutPrices()
{
	std::string* output = new std::string[logicalSize];
	for(int i = 0; i < logicalSize; i++) {
		output[i] = products[i].getDataPrice();
	}
	return output;
}		
long CheckOut::getPrice()
{
	return totalPrice;
}
void CheckOut::delProduct(int productNo)
{
	if(productNo < logicalSize) {
		totalPrice -= products[productNo].productPrice();
		for(int i = productNo; i < logicalSize; i++) {
			products[i] = products[i+1];
		}
		for(int i = productNo; i < logicalSize; i++) {
			productQuantities[i] = productQuantities[i+1];
		}
		logicalSize--;
	}
	if(logicalSize < productsSize/2) {
		products = resizeCheckOut(false, products);
	}
}
int CheckOut::emptyProduct()
{
	return logicalSize;
}
int CheckOut::productEqualTo(long extBarCode)
{
	for (int i = 0; i < logicalSize; i++) {
		if(products[i] != '\0' && products[i].getBarCode() == extBarCode) {
			return i;
		}
	}
	return -1;
}
std::vector<Product> CheckOut::resizeCheckOut(bool action, std::vector<Product> resizing)
{
if(action) {
		productsSize += 4;
		return resizing.resize(productsSize);
	}
	else if(productsSize/2 > 4) {
		productsSize /=4;
		return resizing.resize(productsSize);
	}
	else {
		productsSize = 4;
		resizing.resize(productsSize);
	}
}
std::vector<int> CheckOut::resizeQuantities(bool action, std::vector<int> resizing)
{
if(action) {
		quantitiesSize += 4;
		return resizing.resize(productsSize);
	}
	else if(productsSize/2 > 4) {
		productsSize /=4;
		return resizing.resize(productsSize);
	}
	else {
		productsSize = 4;
		resizing.resize(productsSize);
	}
}
int CheckOut::partition(int lb, int ub, bool(CheckOut::*test)(Product*, Product*, bool))
{
	Product pivotElement = products[lb];
	int max = logicalSize;
	int left = lb;
	int right = ub;
	Product temp;
	
	while(left < right ){
		while(test(&products[left], &pivotElement) && left + 1 < max) {
			left++;
		}
		while (test(&products[right], &pivotElement) && (right-1 > 0)) {
			right--;
		}
		if(left < right) {
			temp = products[left];
			products[left] = products[right];
			products[right] = temp;
		}
	}
	for(left = lb; left <= right && left +1 < max; left++) {
		products[left] = products[left+1];
	}
	products[right] = pivotElement;
	return right;
}
void CheckOut::quickSort(int left, int right, bool(CheckOut::*)(Product*, Product*, bool))
{
	if(left < right) {
		int pivot = partition(left, right, test);
		quickSort(left, pivot - 1, test);
		quickSort(pivot + 1, right, test);
	}
}
bool CheckOut::testName(Product* left, Product* right, bool lessEq)
{
	if(lessEq) {
		return (left->getName() <= right->getName());
	}
	else {
		return (left->getName() > right->getName());
	}
}
bool CheckOut::testPrice(Product* left, Product* right, bool lessEq)
{
	if(lessEq) {
		return (left->productPrice() <= right->productPrice());
	}
	else {
		return (left->productPrice() > right->productPrice());
	}
}
bool CheckOut::testBarCode(Product* left, Product* right, bool lessEq)
{
	if(lessEq) {
		return (left->getBarCode() <= right->getBarCode());
	}
	else {
		return (left->getBarCode() > right->getBarCode());
	}
}
void CheckOut::sortBy(int sort) {
	switch(sort) {
		case 1:
			CheckOut::quickSort(0, logicalSize-1, &CheckOut::testName);
			break;
		case 2:
			CheckOut::quickSort(0, logicalSize-1, &CheckOut::testPrice);
			break;
		case 3:
			CheckOut::quickSort(0, logicalSize-1, &CheckOut::testBarCode);
			break;
		default:
			CheckOut::quickSort(0, logicalSize-1, &CheckOut::testName);
	}
}
void CheckOut::productBought()
{
	for(int i = logicalSize -1; i > 0; i--) {
		products[i].minusNumber(productQuantities[i]);
	}
}
void CheckOut::addQuantity(int productNo, int add)
{
	products[productNo].setQuantity(products[productNo].getQuantity() + add);
	totalPrice += products[productNo].productPrice();
}
