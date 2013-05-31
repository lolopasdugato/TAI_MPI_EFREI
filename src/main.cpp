#include <iostream>
#include "../include/Automaton.h"
#include "../include/Transition.h"

using namespace std;

/**
 * @brief main function
 * @return
 */
int main() {
	Automaton a;
		short choice(-1);
		if(a.loadAutomaton()) a.show();
		do {
			cout << endl << endl << endl;
			cout << "Que souhaitez vous faire ?" << endl << endl;
			cout << "1) Standardiser." << endl;
			cout << "2) Determiniser." << endl;
			cout << "3) Minimizer." << endl;
			cout << "4) Tout faire." << endl;
			cout << "5) Lire un mot." << endl;
			cout << endl << "Entrez le numero de l'action : ";
			cin >> choice;
			cout << endl << endl;

			switch(choice) {
			case 1:
				if(!a.isStandard()) a.standardize();
				a.show();
				break;
			case 2:
				// if(!a.isDeterminized()) a.determinize();
				cout << "pas encore implemente" << endl;
				// a.show();
				break;
			case 3:
				// if(!a.isMinimized()) a.minimize();
				cout << "pas encore implemente" << endl;
				// a.show();
				break;
			case 4:
				/*
				if(!a.isStandard()) a.standardize();
				if(!a.isDeterminized()) a.determinize();
				if(!a.isMinimized()) a.minimize();
				*/
				cout << "pas encore implemente" << endl;
				// a.show();
				break;
			case 5:
				// a.readWord();
				cout << "pas encore implemente" << endl;
				// a.show();
				break;
			default :
				cout << "Entrez un action valide !" << endl;
				break;
			}
			choice = -1;
		}while(choice == -1);
	return 0;
}
