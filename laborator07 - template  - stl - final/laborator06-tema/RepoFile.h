#pragma once
#include <fstream>
#include "Repo.h"
#include <cstddef>

template <class T>
class RepoFile : public Repo<T> {
private:
	char* fileName;
	//char* fileNameOut;
public:

	RepoFile() : Repo<T>() {
		this->fileName = NULL;
		//this->fileNameOut = NULL;
	}

	RepoFile(const char* fileName) {
		this->fileName = new char[strlen(fileName) + 1];
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		/*this->fileNameOut = new char[strlen(fileNameOut) + 1];
		strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);*/
		this->loadFromFile();
	}

	RepoFile(const RepoFile<T>& repo) {
		this->fileName = new char[strlen(repo.filename) + 1];
		strcpy_s(this->fileName, strlen(repo.filename) + 1, repo.fileName);
		/*this->fileNameOut = new char[strlen(repo.filenameOut) + 1];
		strcpy_s(this->fileNameOut, strlen(repo.filenameOut) + 1, repo.fileNameOut);*/
		this->loadFromFile();
	}

	~RepoFile() {
		if (this->fileName != NULL)
		{
			delete[] this->fileName;
		}
		/*if (this->fileNameOut != NULL)
		{
			delete[] this->fileNameOut;
		}*/
	}

	void addElement(const T& elem) {
		Repo<T>::addElement(elem);
		this->saveToFile();
	}


	vector<T> getAll() {
		return Repo<T>::getAll();
	}

	RepoFile<T>& operator=(const RepoFile<T>& r) {
		this->setFileName(r.fileName);
		//this->setFileNameOut(r.fileNameOut);
		this->loadFromFile();
		return *this;
	}
	void updateElement(T& oldElement, T& newElement) {
		Repo<T>::updateElement(oldElement, newElement);
		this->saveToFile();
	}
	void deleteElement(T& elem) {
		Repo<T>::deleteElement(elem);
		this->saveToFile();
	}

	T getItemAtPosition(int pos) {
		return Repo<T>::getItemAtPosition(pos);
	}
	int getSize() {
		return this->elements.size();
	}

	void setFileName(const char* fileName) {
		if (fileName != NULL) {
			this->fileName = new char[strlen(fileName) + 1];
			strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		}
		else {
			this->fileName = NULL;
		}
	}
	/*void setFileNameOut(const char* fileNameOut) {
		if (fileNameOut != NULL) {
			this->fileNameOut = new char[strlen(fileNameOut) + 1];
			strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
		}
		else {
			this->fileNameOut = NULL;
		}
	}*/

	void loadFromFile() {
		if (this->fileName != NULL) {
			this->elements.clear();
			ifstream fin(this->fileName);
			T element;
			while (fin>>element) {
				if (!!element) {
					RepoFile<T>::addElement(element);
				}
			}
			fin.close();
		}
	}
	void saveToFile() {
		if (this->fileName != NULL) {
			ofstream fout(this->fileName);
			for (int i = 0; i < this->elements.size(); i++) {
				fout << this->elements[i];
			}
			fout.close();
		}
	}

};