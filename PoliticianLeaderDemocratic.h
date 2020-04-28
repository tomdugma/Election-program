/*
 * PoliticianLeaderDemocratic.h
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#ifndef PoliticianLeaderDemocratic_H_
#define PoliticianLeaderDemocratic_H_

#include "Leader.h"

class PoliticianLeaderDemocratic: public Leader {
public:
	PoliticianLeaderDemocratic(string Firstname, string Lastname, string Id, int Power):Leader(Firstname, Lastname, Id, Power){}
	virtual ~PoliticianLeaderDemocratic();
	//PoliticianLeaderDemocratic CreatePoliticianLeaderDemocratic(string Firstname,string Lastname,string Id,int Power);
	//PoliticianLeaderDemocratic(const PoliticianLeaderDemocratic &other);
	//PoliticianLeaderDemocratic& operator=(const PoliticianLeaderDemocratic &other);
	virtual void print() const;
//	virtual bool canBeDemocratic(){ return true; }
//	virtual bool canBeRepublican(){ return false; }
	virtual void addMeToDemocratic(Party* partyto);
	virtual void addMeToRepublican(Party* partyto){}
};

#endif /* PoliticianLeaderDemocratic_H_ */
