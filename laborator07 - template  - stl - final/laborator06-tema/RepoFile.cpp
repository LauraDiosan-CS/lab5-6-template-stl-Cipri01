//#include "RepoFile.h"
//#include <fstream>
//using namespace std;
//
////Descr:	create an empty Repo object
////In:		none
////out:		an instance of type Repo (without elements)
//RepoFile::RepoFile() {
//	this->fileNameIn = NULL;
//	this->fileNameOut = NULL;
//}
//
//RepoFile::RepoFile(const char* fileNameIn, const char* fileNameOut) {
//	this->fileNameIn = new char[strlen(fileNameIn) + 1];
//	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
//	this->fileNameOut = new char[strlen(fileNameOut) + 1];
//	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
//
//	this->loadFromFile();
//}
////Descr:	destroy a Repo object
////In:		a Repo object
////out:		none
//RepoFile::~RepoFile() {
//	this->products.clear();
//}
//
//void RepoFile::setFileNameIn(const char* fileNameIn)
//{
//	if (this->fileNameIn != NULL)
//	{
//		delete[] this->fileNameIn;
//	}
//	this->fileNameIn = new char[strlen(fileNameIn) + 1];
//	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
//}
//
//void RepoFile::setFileNameOut(const char* fileNameOut)
//{
//	if (this->fileNameOut != NULL)
//	{
//		delete[] this->fileNameOut;
//	}
//	this->fileNameOut = new char[strlen(fileNameOut) + 1];
//	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
//}
//
////Descr:	add an element p into vector "elements"
////In:		a Product object
////out:		the (changed) vector
//void RepoFile::addProduct(const Product& p) {
//	this->products.push_back(p);
//	this->saveToFile();
//}
//
////Descr:	get all elemts of vector "elements"
////In:		none
////out:		vector "elements"
//vector<Product> RepoFile::getAll() {
//	return this->products;
//}
//
////Descr:	update an elemnt of vector "elemnts"
////In:		the vector, old item and new item 
////out:		the (changed) vector
//void RepoFile::updateProduct(Product& oldProduct, Product& newProduct) {
//	vector<Product>::iterator it;
//	it = find(this->products.begin(), this->products.end(), oldProduct);
//	if (it != this->products.end()) {
//		*it = newProduct;
//	}
//	/*for (int i = 0; i < this->products.size(); i++) {
//		if (this->products[i] == oldProduct) {
//			this->products[i] = newProduct;
//		}
//	}*/
//	this->saveToFile();
//}
//
////Descr:	delete all elemnt el of vector "elemnts"
////In:		the vector and item el for delete
////out:		the (changed) vector
//void RepoFile::deleteProduct(Product& p) {
//	vector<Product>::iterator it;
//	it = find(this->products.begin(), this->products.end(), p);
//	if (!(it == this->products.end())) {
//		this->products.erase(it);
//	}
//	this->saveToFile();
//}
//
////Descr:	acces an element from the vector
////In:		the vector and a position
////out:		the vector's element from the given position
//Product RepoFile::getItemAtPosition(int pos)
//{
//	return this->products[pos];
//}
//
////Descr:	acces the size of the vector
////In:		the vector
////out:		the vector's size
//int RepoFile::getSize() {
//	return this->products.size();
//}
//
////Descr:	change an element from the vector
////In:		the vector, a position and an element
////out:		the (changed) vector
//void RepoFile::setElemPos(int pos, Product p)
//{
//	this->products[pos] = p;
//	this->saveToFile();
//}
//
//void RepoFile::loadFromFile()
//{
//	if (this->fileNameIn != NULL)
//	{
//		this->products.clear();
//		ifstream fin(this->fileNameIn);
//		char* code = new char[20];
//		char* name = new char[20];
//		float price;
//		while (!fin.eof())
//		{
//			fin >> code >> name >> price;
//			if (strlen(code) > 0 && strlen(name) > 0){
//				this->addProduct(Product(code, name, price));
//			}
//		}
//		delete[] code;
//		delete[] name;
//		fin.close();
//	}
//}
//
//void RepoFile::saveToFile()
//{
//	if (this->fileNameOut != NULL)
//	{
//		ofstream fout(this->fileNameOut);
//		for (int i = 0; i < this->products.size(); i++)
//		{
//			fout << this->products[i] << endl;
//		}
//		fout.close();
//	}
//}
