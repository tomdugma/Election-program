/*
 * PoliticianSocialDemocratic.cpp
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#include "PoliticianSocialDemocratic.h"
//
//PoliticianSocialDemocratic::PoliticianSocialDemocratic() {
//	// TODO Auto-generated constructor stub
//
//}

PoliticianSocialDemocratic::~PoliticianSocialDemocratic() {
	// TODO Auto-generated destructor stub
}

//PoliticianSocialDemocratic::PoliticianSocialDemocratic(
//		const PoliticianSocialDemocratic &other) {
//	this->firstname = other.firstname;
//	this->lastname = other.lastname;
//	this->id = other.id;
//	this->power = other.power;
//	this->party = other.party;
//	this->chairman = other.chairman;
//	this->seniority = other.seniority;
//
//}

//PoliticianSocialDemocratic& PoliticianSocialDemocratic::operator=(
//		const PoliticianSocialDemocratic &other) {
//	this->firstname = other.firstname;
//	this->lastname = other.lastname;
//	this->id = other.id;
//	this->power = other.power;
//	this->party = other.party;
//	this->chairman = other.chairman;
//	this->seniority = other.seniority;
//	return *this;
//
//}
void PoliticianSocialDemocratic::print() const{
	cout<< "Democratic ";
	Social::print();
}


void PoliticianSocialDemocratic::addMeToDemocratic(Party* partyto){
	if (partyto->AddDemocraticPolitician(this) == FAILED)
		return;
	if (this->party != NULL)
	{
		Party* old = this->party;
		old->RemovePolitician(this);
	}
	this->party = partyto;
	this->chairman = partyto->PartyChariman();

}
