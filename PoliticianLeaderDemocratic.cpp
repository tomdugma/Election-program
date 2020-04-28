/*
 * PoliticianLeaderDemocratic.cpp
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#include "PoliticianLeaderDemocratic.h"

//PoliticianLeaderDemocratic::PoliticianLeaderDemocratic() {
//	// TODO Auto-generated constructor stub
//
//}

PoliticianLeaderDemocratic::~PoliticianLeaderDemocratic() {
	// TODO Auto-generated destructor stub
}
//PoliticianLeaderDemocratic PoliticianLeaderDemocratic::CreatePoliticianLeaderDemocratic(string Firstname,string Lastname, string Id, int Power){
//
//	PoliticianLeaderDemocratic p = new PoliticianLeaderDemocratic(Firstname, Lastname, Id, Power);
//	return p;
//}

//PoliticianLeaderDemocratic::PoliticianLeaderDemocratic(const PoliticianLeaderDemocratic &other) {
//	// TODO Auto-generated constructor stub
//	this->firstname = other.firstname;
//	this->lastname = other.lastname;
//	this->id = other.id;
//	this->power = other.power;
//	this->party = other.party;
//	this->chairman = other.chairman;
//	this->seniority = other.seniority;
//}

//PoliticianLeaderDemocratic& PoliticianLeaderDemocratic::operator=(
//		const PoliticianLeaderDemocratic &other) {
//	this->firstname = other.firstname;
//	this->lastname = other.lastname;
//	this->id = other.id;
//	this->power = other.power;
//	this->party = other.party;
//	this->chairman = other.chairman;
//	this->seniority = other.seniority;
//	return *this;
//}
void PoliticianLeaderDemocratic::print() const{
	cout<< "Democratic ";
	Leader::print();
}

void PoliticianLeaderDemocratic::addMeToDemocratic(Party* partyto){
	if (partyto->AddDemocraticPolitician(this) == FAILED)
		return;

	if (this->party != NULL)
	{
		Party* old = this->party;
		old->RemovePolitician(this);
	}
//	partyto->AddDemocraticPolitician(this);
	this->party = partyto;
	this->chairman = partyto->PartyChariman();

}

