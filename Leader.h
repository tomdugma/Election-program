/*
 * Leader.h
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#ifndef LEADER_H_
#define LEADER_H_

#include "Politician.h"

class Leader: public Politician {
public:
	//Leader();
	Leader(string Firstname, string Lastname, string Id, int Power):Politician(Firstname, Lastname, Id, Power){}
	virtual ~Leader();
	//Leader(const Leader &other);
	virtual bool isGoodForPrimeriz() { return true; }
	virtual void print() const=0;
//	virtual bool canBeDemocratic()=0;
//	virtual bool canBeRepublican()=0;
	virtual void addMeToDemocratic(Party* partyto) = 0;
	virtual void addMeToRepublican(Party* partyto) = 0;
};

#endif /* LEADER_H_ */
