/*
 * PoliticalSys.cpp
 *
 *  Created on: Jan 11, 2020
 *      Author: ise
 */

#include "PoliticalSys.h"

PoliticalSys::PoliticalSys() {
	// TODO Auto-generated constructor stub

}

PoliticalSys::PoliticalSys(char *&filepath) {
	// TODO Auto-generated constructor stub

	ifstream myfile;
	string line;
	bool polition = true;
	bool party = false;
	myfile.open(filepath);
	if (myfile.is_open()) {
		while (getline(myfile, line)) //loop through the lines
		{
			string word;
			if (line.rfind("Politicians:", 0) == 0)
				continue;
			if (line.rfind("Parties:", 0) == 0) {
				polition = false;
				party = true;
				continue;
			}
			list<string> currLine = convertStringToList(line);
			list<string>::iterator it = currLine.begin();

			if (polition) {
				string Firstname = (*it);
				++it;
				string Lastname = (*it);
				++it;
				string Id = (*it);
				++it;
				// cast power to int
				string powerS = (*it);
				stringstream s(powerS);
				int Power = 0;
				s >> Power;
				// cast power to int
				++it;
				string side = (*it);
				++it;
				string type = (*it);
				/*
				 * COMPLETE IF ARGUMENTS ARE WRONG !
				 */
				addthePolitician(Firstname, Lastname, Id, Power, side[0],
						type[0]);
			}
			if (party) {
				string partyName = (*it);
				++it;
				string partyType = (*it);
				/*
				 * COMPLETE IF ARGUMENTS ARE WRONG !
				 */
				Party *p;
				if (partyType[0] == 'D') {
					p = new Democratic(partyName);
					//notify();
				} else if (partyType[0] == 'R') {
					p = new Republican(partyName);
					//notify();
				}
				parties.push_back(p);
				sorted_parties.push_back(p);
				sort(sorted_parties.begin(),sorted_parties.end(),LowerParty());
				//max_heap_parties.push(p);
				//int a = parties_size.size();
				//parties_size[a] = p->PartyName(),p->PartySize();
				int s = all_politicians.size();
				for (int i = 0; i < s; i++) {
						if ((all_politicians[i]->getParty() == NULL) || (all_politicians[i]->getParty()->PartySize() > p->PartySize())) {

								if (partyType[0] == 'D')
									all_politicians[i]->addMeToDemocratic(p);
								else
									all_politicians[i]->addMeToRepublican(p);

					}
				//make_heap(max_heap_parties.begin(), max_heap_parties.end(),LowerParty());
				//priority_queue<Party*>(max_heap_parties.begin(), max_heap_parties.end());
			}
			//delete p;
		}
	}
}
}

list<string> PoliticalSys::convertStringToList(string str){
	list<string> res;
	stringstream ss(str);
	string tok;
	while (getline(ss, tok, ' ')) {
		res.push_back(tok);
	}
	return res;
}

PoliticalSys::~PoliticalSys() {


	int s = all_politicians.size();
	for (int i = 0; i< s; i++)
		delete(all_politicians[i]);
	int p = parties.size();
	for(int i =0; i<p ; i++)
		delete(parties[i]);
	//int k = sorted_parties.size();
//	for (int i = 0; i<k; i++)
//		delete(sorted_parties[i]);
	all_politicians.clear();
	parties.clear();
	sorted_parties.clear();
	//max_heap_parties.clear();
	//r_parties.clear();
}
status PoliticalSys::addPolitician() {
	//TODO : check inputs**

	cout << "---Create Politician---" << endl;
	cout << "First name:" << endl;
	string Firstname;
	cin >> Firstname;
	while (has_number(Firstname)) {
		try {
			if (has_number(Firstname))
				throw NameError();
		} catch (Error &e) {
			e.Handle();
			cin >> Firstname;
		}
	}
	cout << "Last name:" << endl;
	string Lastname;
	cin >> Lastname;
	while (has_number(Lastname)) {
		try {
			if (has_number(Lastname))
				throw NameError();
		} catch (Error &e) {
			e.Handle();
			cin >> Lastname;
		}
	}
	cout << "ID:" << endl;
	string Id;
	cin >> Id;
	while (is_number(Id)) {
		try {
			if (is_number(Id))
				throw IDError();
		} catch (Error &e) {
			e.Handle();
			cin >> Id;
		}
	}
	while (PoliticianExists(Id)) {
		try {
			if (PoliticianExists(Id))
				throw DataError();
		} catch (Error &e) {
			e.Handle();
			cin >> Id;
		}
	}
	cout << "Power:" << endl;
	int Power;
	cin >> Power;
	while (Power < 0) {
		try {
			if (Power < 0)
				throw DataError();
		} catch (Error &e) {
			e.Handle();
			cin >> Power;
		}
	}
	cout << "Republican or Democratic person" << endl;
	char side;
	cin >> side;
	while (side != 'R' && side != 'D') {
		try {
			if (side != 'R' && side != 'D')
				throw DataError();
		} catch (Error &e) {
			e.Handle();
			cin >> side;
		}
	}
	cout << "Leader or Social" << endl;
	char type;
	cin >> type;
	while (type != 'S' && type != 'L') {
		try {
			if (type != 'S' && type != 'L')
				throw DataError();
		} catch (Error &e) {
			e.Handle();
			cin >> type;
		}
	}
	addthePolitician(Firstname, Lastname, Id, Power, side, type);

	return SUCCES;
}
status PoliticalSys::addthePolitician(string Firstname, string Lastname,
		string Id, int Power, char side, char type) {
	Politician *p;
	int s = parties.size();
	if (type == 'L') {
		if (side == 'D') {
			p = new PoliticianLeaderDemocratic(Firstname, Lastname, Id, Power);

			for (int i = 0; i < s; i++) {
				if ((p->getParty() == NULL)
						|| (p->getParty()->PartySize() > parties[i]->PartySize())) {
					p->addMeToDemocratic(parties[i]);
				}
			}
		} else if (side == 'R') {
			p = new PoliticianLeaderRepublican(Firstname, Lastname, Id, Power);
			for (int i = 0; i < s; i++) {
				if ((p->getParty() == NULL)
						|| (p->getParty()->PartySize() > parties[i]->PartySize())) {
					p->addMeToRepublican(parties[i]);
				}
			}
		}
	} else if (type == 'S') {
		if (side == 'D') {
			p = new PoliticianSocialDemocratic(Firstname, Lastname, Id, Power);
			for (int i = 0; i < s; i++) {
				if ((p->getParty() == NULL)
						|| (p->getParty()->PartySize() > parties[i]->PartySize())) {
					p->addMeToDemocratic(parties[i]);
				}
			}
		} else if (side == 'R') {
			p = new PoliticianSocialRepublican(Firstname, Lastname, Id, Power);
			for (int i = 0; i < s; i++) {
				if ((p->getParty() == NULL)
						|| (p->getParty()->PartySize() > parties[i]->PartySize())) {
					p->addMeToRepublican(parties[i]);
				}
			}
		}
	}
	//make_heap(max_heap_parties.begin(), max_heap_parties.end(),LowerParty());

	all_politicians.push_back(p);
	sort(sorted_parties.begin(),sorted_parties.end(),LowerParty());
	//checkParties();
//	delete p;
	return SUCCES;
}

status PoliticalSys::addParty() {
	//TODO: check input*

	cout << "---Create Party---" << endl;
	cout << "Name:" << endl;
	string partyname;
	cin >> partyname;
	while (has_number(partyname)) {
		try {
			if (has_number(partyname))
				throw NameError();
		} catch (Error &e) {
			e.Handle();
			cin >> partyname;
		}
	}
	cout << "Republican or Democratic party" << endl;
	char side;
	cin >> side;
	while (side != 'R' && side != 'D') {
		try {
			if (side != 'R' && side != 'D')
				throw DataError();
		} catch (Error &e) {
			e.Handle();
			cin >> side;
		}
	}
	Party *p;
	int s = all_politicians.size();
	if (side == 'D') {
		p = new Democratic(partyname);

	} else if (side == 'R') {
		p = new Republican(partyname);

	}
	parties.push_back(p);




	for (int i = 0; i < s; i++) {
				if ((all_politicians[i]->getParty() == NULL) || (all_politicians[i]->getParty()->PartySize() > p->PartySize())) {

						if (side == 'D')
							all_politicians[i]->addMeToDemocratic(p);
						else
							all_politicians[i]->addMeToRepublican(p);

			}
	}
	sorted_parties.push_back(p);
	sort(sorted_parties.begin(),sorted_parties.end(),LowerParty());
	//make_heap(max_heap_parties.begin(), max_heap_parties.end(),LowerParty());
	return SUCCES;

}
status PoliticalSys::removePolitician() {
	cout << "---Remove Politician---"<<endl;
	cout << "Enter the ID:"<<endl;
	string Id;
	cin >> Id;
	while (is_number(Id)) {
		try {
			if (is_number(Id))
				throw IDError();
		} catch (Error &e) {
			e.Handle();
			cin >> Id;
		}
	}
	while (!PoliticianExists(Id)) {
		try {
			if (!PoliticianExists(Id))
				throw IDError();
		} catch (Error &e) {
			e.Handle();
			cin >> Id;
		}
	}
	int s = parties.size();

	Politician *p;
	for (int i = 0; i < s; i++) {
		p = parties[i]->getPoliticianById(Id);
		if (p != NULL) {
			parties[i]->RemovePolitician(p);
			break;
		}
	}
	int k = all_politicians.size();
	for (int j = 0; j < k; j++) {
		if (all_politicians[j]->getId() == Id) {
			delete all_politicians[j];
			all_politicians.erase(all_politicians.begin() + j);
			sort(sorted_parties.begin(), sorted_parties.end(), LowerParty());

			return SUCCES;
		}
	}

	return FAILED;
}

status PoliticalSys::removeParty() {
	cout << "---Remove Party---"<<endl;
	cout << "Enter party name:"<<endl;
	string partyname;
	cin >> partyname;
	while (has_number(partyname)) {
		try {
			if (has_number(partyname))
				throw NameError();
		} catch (Error &e) {
			e.Handle();
			cin >> partyname;
		}
	}
	while (!PartyExists(partyname)) {
		try {
			if (!PartyExists(partyname))
				throw NameError();
		} catch (Error &e) {
			e.Handle();
			cin >> partyname;
		}
	}
	int s = parties.size();
	vector<Politician*> non_party_all_politicians;
	int i,j;
	for (i = 0; i < s; i++) {
		if (parties[i]->PartyName() == partyname) {
			non_party_all_politicians = parties[i]->deleteMe();
			break;
			}
	}
	cout<<partyname<<endl;
	int m = sorted_parties.size();
	for (j =0; j<m ; j++){
		if (sorted_parties[j]->PartyName() == partyname) {
			sorted_parties.erase(sorted_parties.begin() + j);

			}
	}
	delete parties[i];
	parties.erase(parties.begin() + i);
	//sorted_parties.erase(sorted_parties.begin() + j);

	int k = non_party_all_politicians.size();
	s = parties.size();

		for (int j = 0; j <k; j++) {
			for (int i = 0; i < s; i++) {
			if ((non_party_all_politicians[j]->getParty() == NULL)||(non_party_all_politicians[j]->getParty()->PartySize() > parties[i]->PartySize())) {
				non_party_all_politicians[j]->addMeToDemocratic(parties[i]);
				non_party_all_politicians[j]->addMeToRepublican(parties[i]);
			}
		}
	}
	sort(sorted_parties.begin(),sorted_parties.end(),LowerParty());
	//make_heap(max_heap_parties.begin(), max_heap_parties.end(),LowerParty());
	non_party_all_politicians.clear();
	return SUCCES;

}
void PoliticalSys::elections() {
	cout << "----Primaries----"<<endl;

	int s = parties.size();
	for (int j = 0; j < s; j++)
		parties[j]->Primeriz();

	cout << "----Elections----"<<endl;
	int max = 0, p = 0;
	Party *winner;
	for (int j = 0; j < s; j++) {
		cout << "Party: ";
		cout << parties[j]->PartyName();
		cout << ",Power: ";
		p = parties[j]->PartyPower();
		cout << p << endl;
		if (p > max) {
			max = p;
			winner = parties[j];
		}

	}

	cout << "----Elections Results----"<<endl;
	cout << winner->PartyName();
	cout << " party won the elections and ";
	if (winner->PartyChariman())
		cout << winner->PartyChariman()->getName();
	else
		cout << "None";
	cout << " is the prime minister" << endl;

}
void PoliticalSys::printPoliticians() {
	cout << "----all_politicians----" << endl;
	int p = all_politicians.size();
	for (int i = 0; i < p; ++i) {
		all_politicians[i]->print();
	}

}
void PoliticalSys::printParties() {
	cout << "----Parties----" << endl;
	int s = parties.size();
	for (int j = 0; j < s; j++)
		parties[j]->print();

}
void PoliticalSys::BiggestParty() {
	cout << "----Biggest Party----" << endl;
	if ((sorted_parties.empty()) || (sorted_parties[0]->PartySize() == 0))
		cout<<"[None,0]"<< endl;
	cout<<"[" <<sorted_parties[0]->PartyName()<< ",";
	cout<<sorted_parties[0]->PartySize() << "]"<< endl;
}

bool PoliticalSys::has_number(const string &s) {
	return (s.find_first_of("0123456789") != string::npos);
}

bool PoliticalSys::is_number(const string &s) {
	return (s.find_first_not_of("0123456789") != string::npos);
}
bool PoliticalSys::PoliticianExists(const string &id)
{
	int s = all_politicians.size();
	for (int i =0; i<s; i++)
		if(all_politicians[i]->getId() == id)
			return true;
	return false;
}

bool PoliticalSys::PartyExists(const string &name)
{
	int s = parties.size();
	for (int i =0; i<s; i++)
		if(parties[i]->PartyName() == name)
			return true;
	return false;
}

