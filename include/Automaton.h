/**
 *@file	Automaton.h
 *@author Alpha
 *@version
 *@date 22 avr. 2013
 *@brief
 *@details
 */

#ifndef AUTOMATON_H_
#define AUTOMATON_H_

#include <vector>
#include "Transition.h"

class Automaton {
public:
	Automaton();
	Automaton(const Automaton& automaton);
	virtual ~Automaton();

	bool isCompleted() const;
	void setCompleted(bool completed);
	bool isDeterminized() const;
	void setDeterminized(bool determinized);
	bool isMinimized() const;
	void setMinimized(bool minimized);
	bool isStandard() const;
	void setStandard(bool standard);
	const std::vector<int>& getA() const;
	void setA(const std::vector<int>& a);
	const std::vector<int>& getI() const;
	void setI(const std::vector<int>& i);
	const std::vector<int>& getQ() const;
	void setQ(const std::vector<int>& q);
	const std::vector<int>& getT() const;
	void setT(const std::vector<int>& t);
	const std::vector<Transition>& getTt() const;
	void setTt(const std::vector<Transition>& tt);

	// File Reading
	bool loadAutomaton();
	bool readA();
	bool readI();
	bool readQ();
	bool readT();
	bool readTransition();


private:
	// Automaton current status
	bool _completed;
	bool _determinized;
	bool _minimized;
	bool _standard;

	// Automaton characteristics
	std::vector<int> _I; // Initial states
	std::vector<int> _T; // Terminal states
	std::vector<int> _Q; // Finished states
	std::vector<int> _A; // Language recognized
	std::vector<Transition> _TT; // Transition table
};

#endif /* AUTOMATON_H_ */
