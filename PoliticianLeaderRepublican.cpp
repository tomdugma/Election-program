/*
 * PoliticianLeaderRepublican.cpp
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#include "PoliticianLeaderRepublican.h"

//PoliticianLeaderRepublican::PoliticianLeaderRepublican() {
//	// TODO Auto-generated constructor stub
//
//}

PoliticianLeaderRepublican::~PoliticianLeaderRepublican() {
	// TODO Auto-generated destructor stub
}

//PoliticianLeaderRepublican::PoliticianLeaderRepublican(const PoliticianLeaderRepublican &other) {
//	this->firstname = other.firstname;
//	this->lastname = other.lastname;
//	this->id = other.id;
//	this->power = other.power;
//	this->party = other.party;
//	this->chairman = other.chairman;
//	this->seniority = other.seniority;
//
//}

//PoliticianLeaderRepublican& PoliticianLeaderRepublican::operator=(
//		const PoliticianLeaderRepublican &other) {
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
void PoliticianLeaderRepublican::print() const{
	cout<< "Republican ";
	Leader::print();
}
void PoliticianLeaderRepublican::addMeToRepublican(Party* partyto){
	if (partyto->AddRepublicanPolitician(this) == FAILED)
		return;
	if (this->party != NULL)
	{
		Party* old = this->party;
		old->RemovePolitician(this);
	}

	this->party = partyto;
	this->chairman = partyto->PartyChariman();

}
