/**
 *@file	Automaton.cpp
 *@author Alpha
 *@version
 *@date 22 avr. 2013
 *@brief
 *@details
 */

#include "../include/BenetNguyenNasserAutomaton.h"
#include "../include/BenetNguyenNasserTransition.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#define P -2
using namespace std;
/**
 *
 */
Automaton::Automaton() {
	_standard = false;
	_determinized = false;
	_minimized = false;
	_completed = false;
}

/**
 * @brief copy constructor
 * @param automaton
 */
Automaton::Automaton(const Automaton& automaton) {
	_standard = automaton._standard;
	_determinized = automaton._determinized;
	_minimized = automaton._minimized;
	_completed = automaton._completed;

	_I = automaton._I;
	_Q = automaton._Q;
	_A = automaton._A;
	_T = automaton._T;
}

/**
 *
 */
Automaton::~Automaton() {
}

/**
 *
 * @return
 */
bool Automaton::isCompleted() const {
	return _completed;
}

/**
 *
 * @param completed
 */
void Automaton::setCompleted(bool completed) {
	_completed = completed;
}

/**
 *
 * @return
 */
bool Automaton::isDeterminized() const {
	return _determinized;
}

/**
 *
 * @param determinized
 */
void Automaton::setDeterminized(bool determinized) {
	_determinized = determinized;
}

/**
 *
 * @return
 */
bool Automaton::isMinimized() const {
	return _minimized;
}

/**
 *
 * @param minimized
 */
void Automaton::setMinimized(bool minimized) {
	_minimized = minimized;
}

/**
 *
 * @return
 */
bool Automaton::isStandard() const {
	return _standard;
}

/**
 *
 * @param standard
 */
void Automaton::setStandard(bool standard) {
	_standard = standard;
}

/**
 *
 * @return
 */
const std::vector<int>& Automaton::getA() const {
	return _A;
}

/**
 *
 * @param a
 */
void Automaton::setA(const std::vector<int>& a) {
	_A = a;
}

/**
 *
 * @return
 */
const std::vector<int>& Automaton::getI() const {
	return _I;
}

/**
 *
 * @param i
 */
void Automaton::setI(const std::vector<int>& i) {
	_I = i;
}

/**
 *
 * @return
 */
const std::vector<int>& Automaton::getQ() const {
	return _Q;
}

/**
 *
 * @param q
 */
void Automaton::setQ(const std::vector<int>& q) {
	_Q = q;
}

/**
 *
 * @return
 */
const std::vector<int>& Automaton::getT() const {
	return _T;
}

/**
 *
 * @param t
 */
void Automaton::setT(const std::vector<int>& t) {
	_T = t;
}

/**
 *
 * @return
 */
const std::vector<Transition>& Automaton::getTt() const {
	return _TT;
}

/**
 *
 * @param tt
 */
void Automaton::setTt(const std::vector<Transition>& tt) {
	_TT = tt;
}

/**
 * @brief return true if the array is filled with values. Read into automaton.txt
 * @return
 */
bool Automaton::readA(std::string path) {
	ifstream file(path.c_str());
	if (file) {
		string line;
		//Search "A={" from the file's beginning to the end.
		while(getline(file, line)) {
			unsigned int found = line.find("A={");
			unsigned int foundCommentary = line.find("//");
			//if it has been found, get all signs & there is no commentary
			if(found != string::npos && foundCommentary != 1) {
				bool end = false; // End of line flag
				bool numberBefore = false; 	// the treated character is a number > 9 (flag)
				int cpt = 3;
				do {
					if(line[cpt] == ',') {
						numberBefore = false;
						cpt++;
					}
					else if(line[cpt] == '}') end = true;
					// If it's a number
					else if(line[cpt] >= 48  && line[cpt] <= 57) {
						// If the number is > 9
						if(numberBefore) {
							_A.back() = _A.back()*10 + ((int) line[cpt]) - 48;
						}
						else {
							_A.push_back(((int) line[cpt]) - 48);
							numberBefore = true;
						}
						cpt++;
					}
					// If it's a simple character
					else {
						_A.push_back((int) line[cpt]);
						cpt++;
					}
				}while(!end);
			}
		}
	}
	else {
		cout << "ERROR: file cannot be opened" << endl;
		return false;
	}
	// If the array is empty, there is an error. BTW the function should return false.
	if (_A.empty()) {
		cout << "there are'nt any recognized language in the program. Please check how it has been written in the text file." << endl;
		return false;
	}
	return true;
}

/**
 * @brief return true if the array is filled with values. Read into automaton.txt
 * @return
 */
bool Automaton::readI(std::string path) {
	ifstream file(path.c_str());
	if (file) {
		string line;
		//Search "I={" from the file's beginning to the end.
		while(getline(file, line)) {
			unsigned int found = line.find("I={");
			unsigned int foundCommentary = line.find("//");
			//if it has been found, get all signs & there is no commentary
			if(found != string::npos && foundCommentary != 1) {
				bool end = false; // End of line flag
				bool numberBefore = false; 	// the treated character is a number > 9 (flag)
				int cpt = 3;
				do {
					if(line[cpt] == ',') {
						numberBefore = false;
						cpt++;
					}
					else if(line[cpt] == '}') end = true;
					// If it's a number
					else if(line[cpt] >= 48  && line[cpt] <= 57) {
						// If the number is > 9
						if(numberBefore) {
							_I.back() = _I.back()*10 + ((int) line[cpt]) - 48;
						}
						else {
							_I.push_back((int) line[cpt] - 48);
						}
						cpt++;
					}
					// If it's a simple character
					else {
						_I.push_back((int) line[cpt]);
						cpt++;
					}
				}while(!end);
			}
		}
	}
	else {
		cout << "ERROR: file cannot be opened" << endl;
		return false;
	}
	// If the array is empty, there is maybe an error. BTW we should inform the user by a message.
	if (_I.empty()) {
		cout << "Warning, there are'nt any inital states, is that normal ?" << endl;
		return false;
	}
	return true;
}

/**
 * @brief return true if the array is filled with values. Read into automaton.txt
 * @return
 */
bool Automaton::readT(std::string path) {
	ifstream file(path.c_str());
	if (file) {
		string line;
		//Search "A={" from the file's beginning to the end.
		while(getline(file, line)) {
			unsigned int found = line.find("T={");
			unsigned int foundCommentary = line.find("//");
			//if it has been found, get all signs & there is no commentary
			if(found != string::npos && foundCommentary != 1) {
				bool end = false; // End of line flag
				bool numberBefore = false; 	// the treated character is a number > 9 (flag)
				int cpt = 3;
				do {
					if(line[cpt] == ',') {
						numberBefore = false;
						cpt++;
					}
					else if(line[cpt] == '}') end = true;
					// If it's a number
					else if(line[cpt] >= 48  && line[cpt] <= 57) {
						// If the number is > 9
						if(numberBefore) {
							_T.back() = _T.back()*10 + ((int) line[cpt]) - 48;
						}
						else {
							_T.push_back(((int) line[cpt]) - 48);
							numberBefore = true;
						}
						cpt++;
					}
					// If it's a simple character
					else {
						_T.push_back((int) line[cpt]);
						cpt++;
					}
				}while(!end);
			}
		}
	}
	else {
		cout << "ERROR: file cannot be opened" << endl;
		return false;
	}
	// If the array is empty, there is maybe an error. BTW we should inform the user by a message.
	if (_T.empty()) {
		cout << "Warning, there are'nt any terminal states, is that normal ?" << endl;
	}
	return true;
}

/**
 * @brief return true if the array is filled with values. Read into automaton.txt
 * @return
 */
bool Automaton::readQ(std::string path) {
	ifstream file(path.c_str());
	if (file) {
		string line;
		//Search "A={" from the file's beginning to the end.
		while(getline(file, line)) {
			unsigned int found = line.find("Q={");
			unsigned int foundCommentary = line.find("//");
			//if it has been found, get all signs & there is no commentary
			if(found != string::npos && foundCommentary != 1) {
				bool end = false; // End of line flag
				bool numberBefore = false; 	// the treated character is a number > 9 (flag)
				int cpt = 3;
				do {
					if(line[cpt] == ',') {
						numberBefore = false;
						cpt++;
					}
					else if(line[cpt] == '}') end = true;
					// If it's a number
					else if(line[cpt] >= 48  && line[cpt] <= 57) {
						// If the number is > 9
						if(numberBefore) {
							_Q.back() = _Q.back()*10 + ((int) line[cpt]) - 48;
						}
						else {
							_Q.push_back(((int) line[cpt]) - 48);
							numberBefore = true;
						}
						cpt++;
					}
					// If it's a simple character
					else {
						_Q.push_back((int) line[cpt]);
						cpt++;
					}
				}while(!end);
			}
		}
	}
	else {
		cout << "ERROR: file cannot be opened" << endl;
		return false;
	}
	// If the array is empty, there is an error. BTW the function should return false.
	if (_Q.empty()) {
		cout << "there are'nt any states in the program. Please check how it has been written in the text file." << endl;
		return false;
	}
	return true;
}

/**
 *
 * @return
 */
bool Automaton::readTransition(std::string path) {
	ifstream file(path.c_str());
	if(file) {
		string line;
		while (getline(file, line)) {
			// If it's the line to get transitions and it's not a commentary, we can continue.
			if(line.find("transitions {") != string::npos && line.find("//") != 1) {
				// transitions reading
				bool end = false;
				do {
					getline(file, line);
					// Next line check if it's the end of transition definition
					if (line.find("}") != string::npos) end = true;
					else {
						unsigned int cpt = 1;
						bool stateBegin = true, tag = false, stateEnd = false; // Define in which members the value will be store.
						bool numberBefore = false;
						// Next line store each value into the right members of transitions
						do {
							// If it's a number && we already store a number before
							if (numberBefore && (int) line[cpt] >= 48 && (int) line[cpt] <= 57) {
								if(stateBegin) _TT.back().setStateBegin(_TT.back().getStateBegin()*10 + (int) line[cpt] - 48 );
								else if (stateEnd) _TT.back().setStateEnd(_TT.back().getStateEnd()*10 + (int) line[cpt] - 48 );
								else if (tag) _TT.back().setTag(_TT.back().getTag()*10 + (int) line[cpt] - 48 );
								cpt++; //Go to the next char
							}
							// else if it's a simple number
							else if (line[cpt] >= '0' && (int) line[cpt] <= '9') {
								if (stateBegin) {
									Transition a;
									a.setStateBegin((int) line[cpt] - 48);
									_TT.push_back(a);
								}
								else if (stateEnd) {
									_TT.back().setStateEnd((int) line[cpt] - 48);
								}
								else if (tag){
									_TT.back().setTag((int) line[cpt] - 48);
								}
								cpt++;
								numberBefore = true;
							}
							else if (line[cpt] == '.') {
								numberBefore = false;
								if (stateBegin) { // if we were working on beginning state
									stateBegin = false;
									tag = true;
								}
								else if (tag) { // if we were working on transition's tag
									tag = false;
									stateEnd = true;
								}
								// Else we don't care because we are at the line's end
								cpt++;
							}
							else if (line[cpt] <= 'z' && line[cpt] >= 'a') { // if it's a letter
								if (stateBegin) {
									Transition a;
									a.setStateBegin((int) line[cpt]);
									_TT.push_back(a);
								}
								else if (stateEnd) {
									_TT.back().setStateEnd(((int) line[cpt]));
								}
								else if (tag) {
									_TT.back().setTag(((int) line[cpt]));
								}
								cpt++;
								numberBefore = false;
							}
						}while(cpt < line.size());
					}
				}while(!end);
			}
		}
	}
	else {
		cout << "ERROR: file cannot be opened" << endl;
		return false;
	}
	return true;
}

/**
 * @brief should verify if all files are OK.
 */
bool Automaton::loadAutomaton(std::string path) {
	if (Automaton::readA(path) && Automaton::readQ(path) && Automaton::readI(path) && Automaton::readT(path) && Automaton::readTransition(path)) {
		return true;
	}
	else return false;
}

/**
 * @brief standardize an automaton
 */
void Automaton::standardize() {
	vector<Transition> newArray;
	vector<Transition> treatment;
	vector<Transition>::iterator it1;
	vector<int>::iterator it2;
	vector<int>::iterator it3;

	bool toStandardize = false;
	// bool voidWordRecognized = false;

	// Test si L'automate doit �tre standardis�
	for(it1 = _TT.begin(); it1 != _TT.end(); it1++) {
		for(it2 = _I.begin(); it2 != _I.end(); it2++) {
			if((*it1).getStateEnd() == (*it2)) toStandardize = true;
		}
	}

	if(_I.size() > 1 || toStandardize == true) {
		// On enregistre les �tats � traiter dans un tableau
		for(it1 = _TT.begin(); it1 != _TT.end(); it1++) {
			for(it2 = _I.begin(); it2 != _I.end(); it2++) {
				if((*it1).getStateBegin() == (*it2)) treatment.push_back(*it1);
			}
		}

		//On traite les �tats initiaux pour n'en faire plus qu'un et on les ranges
		for(it1 = treatment.begin(); it1 != treatment.end(); it1++) {
			(*it1).setStateBegin(-1);
			_TT.push_back(*it1);
		}

		// On renomme les �tats pour plus de clart�
		for(it1 = _TT.begin(); it1 != _TT.end(); it1++) {
			(*it1).setStateBegin((*it1).getStateBegin() + 1);
			(*it1).setStateEnd((*it1).getStateEnd() + 1);
		}

		for(it2 = _Q.begin(); it2 != _Q.end(); it2++) (*it2)++;
		it2 = _Q.begin();
		_Q.insert(it2,0);

		// On pense � renommer les �tats finaux et � rajouter un nouvel �tat si l'automate reconaissait le mot vide !
		/*
		for(it2 = _T.begin(); it2 != _T.end(); it2++) {
			for(it3 = _I.begin(); it3 != _I.end(); it3++){
				if((*it3) == (*it2)){
					voidWordRecognized = true;
				}
			}
		}
		*/

		// On d�finie un unique �tat initial
		_I.clear();
		_I.push_back(0);
		/*
		if(voidWordRecognized) {
			it2 = _T.begin();
			_T.insert(it2,0);
		}
		*/
		_standard = true;
	}
	return;
}

void Automaton::completion() {
	int nb_state(0);
	int nb_tag(0);
	int nb_transit(0);
	bool tag_present = false;
	bool toComplete = false;
	vector<Transition> treatment;
	vector<Transition>::iterator it1;
	vector<Transition>::iterator it3;
	vector<int>::iterator it2;
	vector<int>::iterator it4;


	// Test si l'automate est complet ou pas
	nb_state = _Q.size();
	nb_tag = _A.size();
	nb_transit = _TT.size();

	if(nb_transit < nb_state*nb_tag) toComplete = true;

	// Complétion
	if(toComplete){

		// On créer l'état poubelle P
		_Q.push_back(P);

		it2 = _Q.begin();

		// On va vérifier si pour chaque état, il y a assez de transition
		for (it2 = _Q.begin(); it2 != _Q.end(); it2++) {
			for(it1 = _TT.begin(); it1 != _TT.end(); it1++)
				if(*it2 == (*it1).getStateBegin()) treatment.push_back(*it1);

			// Vérifie si chaque tag est présent dans les transitions d'un état
			for(it4 = _A.begin(); it4 != _A.end(); it4++) {
				for(it3 = treatment.begin(); it3 != treatment.end(); it3++) {
					if((*it3).getTag() == *it4) tag_present = true;
				}

				// Si un tag n'est pas dans une des transitions d'un état, on créer une transition
				// avec ce tag, de l'état concerné vers un état poubelle
				if (tag_present == false) {
					Transition trans(*it4, *it2, P);
					_TT.push_back(trans);
				}
				tag_present = false;
			}
			treatment.clear();
		}
		_completed = true;
	}
	return;
}

void Automaton::determinize() {
	vector<int> initial;
	vector<int> final;
	vector<int>::iterator it;
	vector<int> newStates;
	vector<Transition> tt;
	vector<Transition> mem;
	vector<Transition> newTransitions;
	vector<Transition>::iterator it2;
	vector<string> newStatesString;
	Automaton determinized;
	string sum;
	int temp = 0;

	if(this->_determinized) return;

	initial = this->_I;
	tt = this->_TT;

	// si il y a plus d'une entrée on doit les repérer puis noter leurs transitions
	if(initial.size() > 1) {
		for(it2 = tt.begin(); it2 != tt.end(); it2++) {
			for(it = initial.begin(); it != initial.end(); it++) {
				if((*it2).getStateBegin() == (*it)) mem.push_back((*it2));
			}
		}
	}
	for(unsigned int cpt=0; cpt < initial.size(); cpt++) {
		for(unsigned int cpt2=0; cpt2 < initial.size() - 1; cpt2++) {
				if(initial[cpt] > initial[cpt2]) {
					temp = initial[cpt];
					initial[cpt] = initial[cpt2];
					initial[cpt2] = temp;
				}
			}
	}
	// on doit fusionner les entrées en créant des nouveaux états
	for(unsigned int i = 0; i < initial.size(); i++) {
		newStatesString.push_back("");
		newStatesString[i].push_back(initial[i] + 48);
		sum+=newStatesString[i];
	}
	newStates.push_back(atoi(sum.c_str()));
	sum.clear();
	if(initial.size() > 1) {
		int i = 0;
			for(it2 = tt.begin(); it2 != tt.end(); it2++) {
				for(it = initial.begin(); it != initial.end(); it++) {
					if((*it2).getStateBegin() == (*it));
				}
			}
		}

	// on doit définir les transitions de ces nouveaux états


	// on doit fusionner les états doubles type (1,2 -> 12)
/*
	while(123) { // tant qu'on a pas décrit tout les états

	}
*/
	// il faut finir par mettre tout les états poubelle
/*
	int rr = 1;
	int ra = 0;
	string one;
	one.push_back(rr + 48);
	string two;
	two.push_back(ra + 48);
	string all=one+two;
	int rz = atoi(all.c_str());
	cout << all << " " << rz << endl;
*/
	for(unsigned int i = 0; i < mem.size(); i++)
		cout << mem[i].getStateBegin() << "." << (char)mem[i].getTag() << "." << mem[i].getStateEnd() << endl;
	// une fois qu'on a fini tout ça, l'automate est déterminisé
	this->_determinized = true;
	return;
}

void Automaton::show() {
	vector<Transition>::iterator it1;
	vector<int>::iterator it2;

	// Affichage de l'alphabet reconus
	cout << "Alphabet reconnu :" << endl;
	for(it2 = _A.begin(); it2 != _A.end(); it2++) {
		cout << (char)(*it2) << " " ;
	}

	// Affichage des états
	cout << endl << endl << "Etats contenus dans l'automate :";
	for(it2 = _Q.begin(); it2 != _Q.end(); it2++) {
		cout << " ";
		if(*it2 == -2) cout << "P";
		else cout << (*it2);
	}

	// Affichage des états initiaux
	cout << endl << endl << "Etats initiaux :";
	for(it2 = _I.begin(); it2 != _I.end(); it2++) {
		cout << " ";
		if(*it2 == -2) cout << "P";
		else cout << (*it2);
	}

	// Affichage des états finaux
	cout << endl << endl << "Etats finaux :";
	for(it2 = _T.begin(); it2 != _T.end(); it2++) {
		cout << " ";
		if(*it2 == -2) cout << "P";
		else cout << (*it2);
	}

	// Affichage des transitions
	cout << endl << endl << "Transition(s) :" << endl;
	for(it1 = _TT.begin(); it1 != _TT.end(); it1++) {
		if ((*it1).getStateBegin() == -2) cout << "P";
		else cout << (*it1).getStateBegin();
		cout << "." << (char)(*it1).getTag() << ".";
		if((*it1).getStateEnd() == -2) cout << "P";
		else cout << (*it1).getStateEnd();
		cout << endl;
	}
	_getch();
	return;
}

bool Automaton::readWord() {
	string input;
	string::iterator it;
	vector<int>::iterator it1;
	vector<Transition>::iterator it2;
	vector<Transition>::iterator it3;
	vector<int>::iterator it4;
	Transition before;
	bool itWorks = false;

	cout << "veuillez saisire un mot (# etant le mot vide) :" << endl;
	cin >> input;


	// Vérifier si l'alphabet est bien reconnu avant;

	// Pour chaques états initiaux existants ...
	for(it1 = _I.begin(); it1 != _I.end(); it1++) {
		for(it2 = _TT.begin(); it2 != _TT.end(); it2++) {
			it = input.begin();
			// On vérifie si la transition demandée existe pour au moins un état initial
			if((*it2).getStateBegin() == (*it1) && (*it2).getTag() == *it) {
				before = (*it2);
				// + ajouter le test du mot vide

				// Test pour un mot d'une lettre
				if(input.size() == 1) {
					for(it4 = _T.begin(); it4 != _T.end(); it4++) {
						if(before.getStateEnd() == (*it4)) return true;
					}
				}
				else if ((input.size() == 1) && (it1 + 1) == _I.end()) return false;
				else if (input.size() > 1) {
					do {
						it++;
						for(it3 = _TT.begin(); it3 != _TT.end(); it3++) {
							// Si L'état précédent et l'état de départ de la transition corresponde, on peut faire la transition.
							if(before.getStateEnd() == (*it3).getStateBegin() && (*it) == (*it3).getTag()) {
								before = (*it3);
							}
						}
					}while((it + 1) != input.end());
					if((it + 1) == input.end()) {
						for(it4 = _T.begin(); it4 != _T.end(); it4++) {
							if(before.getStateEnd() == (*it4)) return true;
						}
					}
				}
			}
		}
	}
	return false;
}
