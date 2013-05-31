#include <iostream>
#include "../include/BenetNguyenNasserAutomaton.h"
#include "../include/BenetNguyenNasserTransition.h"
#include <string>

using namespace std;

/**
 * @brief main function
 * @return
 */
int main() {
	Automaton* a;
	a = new Automaton;
	string data("data/"), txt(".txt"), val("test");
		short choice(-1);
		if(a->loadAutomaton("data/test.txt")) a->show();
		do {
			cout << endl << endl << endl;
			cout << "Que souhaitez vous faire ?" << endl << endl;
			cout << "1) Standardiser." << endl;
			cout << "2) Determiniser." << endl;
			cout << "3) Minimiser." << endl;
			cout << "4) Tout faire." << endl;
			cout << "5) Lire un mot." << endl;
			cout << "6) Choisir un automate" << endl;
			cout << endl << "Entrez le numero de l'action : ";
			cin >> choice;
			cout << endl << endl;

			switch(choice) {
			case 1:
				if(!a->isStandard()) a->standardize();
				a->show();
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
				if(!a->readWord()) cout << "Le mot n'est pas reconnu !" << endl;
				else cout << "Le mot est reconnu !" << endl;
				break;
			case 6:
				cout << "Saisissez le numéro de l'automate : ";
				cin >> val;
				delete a;
				a = new Automaton;
				if(a->loadAutomaton(data + val + txt)) a->show();
				else a->loadAutomaton("data/test.txt");
				break;
			default :
				cout << "Entrez un action valide !" << endl;
				break;
			}
			choice = -1;
		}while(choice == -1);
	return 0;
}
