#include <iostream>
#include <conio.h>
#include "../include/Automaton.h"
#include "../include/Transition.h"

using namespace std;

/**
 * @brief main function
 * @return
 */
int main() {
	Automaton a;
	vector<int> b;
	vector<Transition> c;
	if(a.loadAutomaton()) {
		b = a.getA();
		cout << "Alphabet :";
		for (unsigned int cpt = 0; cpt < b.size(); cpt++) {
			cout << " " << (char) b[cpt];
		}
		cout << endl;
		b = a.getQ();
		cout << "Etats :";
		for (unsigned int cpt = 0; cpt < b.size(); cpt++) {
			cout << " " << b[cpt];
		}
		cout << endl;
		b = a.getI();
		cout << "Etats initiaux :";
		for (unsigned int cpt = 0; cpt < b.size(); cpt++) {
			cout << " " << b[cpt];
		}
		cout << endl;
		b = a.getT();
		cout << "Etats terminaux :";
		for (unsigned int cpt = 0; cpt < b.size(); cpt++) {
			cout << " " << b[cpt];
		}
		cout << endl;
		c = a.getTt();
		for(unsigned int cpt = 0; cpt < c.size(); cpt++) {
			cout << "Transition " << cpt << ": " << endl;
			cout << c[cpt].getStateBegin() << "." << (char) c[cpt].getTag() << "." << c[cpt].getStateEnd() << endl;
		}
		cout << endl << endl << endl;

		if(!a.isStandard()) a.standardize();
		b = a.getA();
		cout << "Alphabet :";
		for (unsigned int cpt = 0; cpt < b.size(); cpt++) {
			cout << " " << (char) b[cpt];
		}
		cout << endl;
		b = a.getQ();
		cout << "Etats :";
		for (unsigned int cpt = 0; cpt < b.size(); cpt++) {
			cout << " " << b[cpt];
		}
		cout << endl;
		b = a.getI();
		cout << "Etats initiaux :";
		for (unsigned int cpt = 0; cpt < b.size(); cpt++) {
			cout << " " << b[cpt];
		}
		cout << endl;
		b = a.getT();
		cout << "Etats terminaux :";
		for (unsigned int cpt = 0; cpt < b.size(); cpt++) {
			cout << " " << b[cpt];
		}
		cout << endl;
		c = a.getTt();
		for(unsigned int cpt = 0; cpt < c.size(); cpt++) {
			cout << "Transition " << cpt << ": " << endl;
			cout << c[cpt].getStateBegin() << "." << (char) c[cpt].getTag() << "." << c[cpt].getStateEnd() << endl;
		}

	}

	_getch();
	return 0;
}
