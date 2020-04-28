/*
 * Error.h
 *
 *  Created on: Jan 13, 2020
 *      Author: ise
 */
#pragma once
//#ifndef SRC_ERROR_H_
//#define SRC_ERROR_H_
#include <iostream>
using namespace std;

class Error {
public:
	virtual ~Error(){}
	virtual void Handle()const = 0;
};

//#endif /* SRC_ERROR_H_ */

class IDError: public Error{
	//IDError(){ cout<<"Please enter valid id"<<endl;}
public:
	virtual ~IDError(){}
	virtual void Handle()const { cout<<"Please enter valid id"<<endl;}
};

class NameError: public Error{
public:
	virtual ~NameError(){}
	virtual void Handle()const{ cout<<"Please enter valid name"<<endl;}
};

class DataError: public Error{
public:
	virtual ~DataError(){}
	virtual void Handle()const{ cout<<"Please enter valid details"<<endl;}
};
