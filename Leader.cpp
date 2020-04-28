/*
 * Leader.cpp
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#include "Leader.h"

//Leader::Leader() {
//	// TODO Auto-generated constructor stub
//
//}

Leader::~Leader() {
	// TODO Auto-generated destructor stub
}

//Leader::Leader(const Leader &other) {
//	this->firstname = other.firstname;
//	this->lastname = other.lastname;
//	this->id = other.id;
//	this->power = other.power;
//	this->party = other.party;
//	this->chairman = other.chairman;
//	this->seniority = other.seniority;
//
//}

void Leader::print() const{
	Politician::print();
	cout<< "Type:L, ";
	Politician::printChairman();
}
