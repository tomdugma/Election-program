/*
 * Social.h
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#ifndef SOCIAL_H_
#define SOCIAL_H_

#include "Politician.h"



class Social: public Politician {
public:
	//Social();
	Social(string Firstname, string Lastname, string Id, int Power):Politician(Firstname, Lastname, Id, Power){}
	virtual ~Social();
//	Social(const Social &other);
	bool isGoodForPrimeriz() { return false; }
	virtual void print() const=0;
//	virtual bool canBeDemocratic()=0;
//	virtual bool canBeRepublican()=0;
	virtual void addMeToDemocratic(Party* partyto) = 0;
	virtual void addMeToRepublican(Party* partyto) = 0;
};



#endif /* SOCIAL_H_ */
