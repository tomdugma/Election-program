/*
 * Social.cpp
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#include "Social.h"


//Social::Social() {
//	// TODO Auto-generated constructor stub
//
//}

Social::~Social() {
	// TODO Auto-generated destructor stub
}

//Social::Social(const Social &other) {
//	this->firstname = other.firstname;
//	this->lastname = other.lastname;
//	this->id = other.id;
//	this->power = other.power;
//	this->party = other.party;
//	this->chairman = other.chairman;
//	this->seniority = other.seniority;
//
//}
void Social::print() const{
	Politician::print();
	cout<< "Type:S, ";
	Politician::printChairman();
}

