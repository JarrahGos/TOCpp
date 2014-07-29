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
	int partition(int, int, bool(*test)(Product*));
	bool testName(Product*, Product*, bool);
	bool testBarCode(Product*, Product*, bool);
	bool testPrice(Product*, Product*, bool);
	void productBought();
	int productEqualTo(long extBarCode);
	void quickSort(int, int, bool(*test)(Product*));
	Product* resizeCheckOut(bool, Product*);
	int* resizeQuantities(bool, int*);
	void sortBy(int);
};
CheckOut::CheckOut()
{
	products = new Product[4];
	quantities = new int[4];
	logicalSize = 0;
	productsSize = 4;
	totalPrice = 0;
	quantitiesSize = 4;
}
int CheckOut::addProduct(Product item, int quantity)
{
	if(logicalSize == productsSize) {
		products = resizeCheckOut(true, products);
		quantities = resizeQuantities(true, quantities);
	}
	item.setQuantity(quantity);
	products[logicalSize] = item;
	quantities[logicalSize = quantity;
	totalPRice += item.productPrice()*quantity;
	++logicalSize;
	return 0;
}
int CheckOut::addProduct(std::string name, long price, int barCode)
{
	if(logicalSize == productsSize) {
		products = resizeCheckOut(true, products);
		quantities = resizeQuantities(true,quantities);
	}
	products[logicalSize] = new Product (name, Price, barCode);
	totalPrice += price;
	quantities[logicalSize] = 1;
	logicalSize++;
	return 0;
}
std::string CheckOut::getCheckOut(int sort)
{
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
	return totalPrice();
}
void CheckOut::delProduct(int productNo)
{
	if(productNo < logicalSize) {
		totalPrice -= products[productNo].productPRice();
		for(int i = productNo; i < logicalSize; i++) {
			products[i] = products[i+1];
		}
		for(int i = productNo; i < logicalSize; i++) {
			quantities[i] = quantities[i+1];
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
Product* CheckOut::resizeCheckOut(bool action, std::vector<Product> resizing)
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
Product* CheckOut::resizeQuantities(bool action, std::vector<int> resizing)
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
int CheckOut::partition(int lb, int ub, bool(*test)(Product*))
{
	Product pivotElement = products[lb];
	Product max = products[logicalSize];
	int left = lb;
	int right = ub;
	Product temp;
	
	while(left < right ){
		while(test(&products[left], &pivotElement) && left + 1 < max) {
			left++;
		}
		while(test(&products[right], &pivotElement) && right-1 > 0) {
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
void CheckOut::quickSort(int left, int right, bool(*test)(Product*))
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
		return (left->getName() <= right->getName);
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
		return (left->getBarCode() <= right->getBarCode);
	}
	else {
		return (left->getBarCode() > right->getBarCode());
	}
}
void CheckOut::sortBy(int sort) {
	switch(sort) {
		case 1:
			CheckOut::quickSort(0, logicalSize-1, testName);
			break;
		case 2:
			CheckOut::quickSort(0, logicalSize-1, testPrice);
			break;
		case 3:
			CheckOut::quickSort(0, logicalSize-1, testBarCode);
			break;
		default:
			CheckOut::quickSort(0, logicalSize-1, testName);
	}
}
void CheckOut::productBought()
{
	for(int i = logicalSize -1; i > 0; i--) {
		products[i].minusNumber(quantities[i]);
	}
}
void CheckOut::addQuantity(int productNo, int add)
{
	products[productNo].setQuantity(products[productNo].getQuantity() + add);
	totalPrice += products[productNo].productPrice();
}
