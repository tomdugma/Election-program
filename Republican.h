/*
 * Republican.h
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#ifndef REPUBLICAN_H_
#define REPUBLICAN_H_

#include "Party.h"


class Republican: public Party {

public:
	Republican(string partyname = "Republicans_party");
	virtual ~Republican();
	//Republican(const Republican &other);
	virtual status AddDemocraticPolitician(Politician* person) { return FAILED; }
	virtual status AddRepublicanPolitician(Politician* person);
    virtual int DemocraticPartySize() { return -1;}
    virtual int RepublicanPartySize() { return politicians.size(); }
	virtual void print() const;
};



#endif /* REPUBLICAN_H_ */
