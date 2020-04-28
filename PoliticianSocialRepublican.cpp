/*
 * PoliticianSocialRepublican.cpp
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#include "PoliticianSocialRepublican.h"

//PoliticianSocialRepublican::PoliticianSocialRepublican() {
//	// TODO Auto-generated constructor stub
//
//}

PoliticianSocialRepublican::~PoliticianSocialRepublican() {
	// TODO Auto-generated destructor stub
}
//
//PoliticianSocialRepublican::PoliticianSocialRepublican(
//		const PoliticianSocialRepublican &other) {
//	this->firstname = other.firstname;
//	this->lastname = other.lastname;
//	this->id = other.id;
//	this->power = other.power;
//	this->party = other.party;
//	this->chairman = other.chairman;
//	this->seniority = other.seniority;
//
//}

//PoliticianSocialRepublican& PoliticianSocialRepublican::operator=(
//		const PoliticianSocialRepublican &other) {
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
void PoliticianSocialRepublican::print() const{
	cout<< "Republican ";
	Social::print();
}
void PoliticianSocialRepublican::addMeToRepublican(Party* partyto){
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
