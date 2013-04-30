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
	int* getA() const;
	void setA(int* a);
	int* getI() const;
	void setI(int* i);
	int* getQ() const;
	void setQ(int* q);
	int* getT() const;
	void setT(int* t);
	int getAsize() const;
	void setAsize(int asize);
	int getIsize() const;
	void setIsize(int isize);
	int getQsize() const;
	void setQsize(int qsize);
	int getTsize() const;
	void setTsize(int tsize);

	void fill(int* charac1, int* charac2);

private:
	// Automaton current status
	bool _completed;
	bool _determinized;
	bool _minimized;
	bool _standard;

	// Automaton characteristics
	int* _I; // Initial states
	int* _T; // Terminal states
	int* _Q; // Finished states
	int* _A; // Language recognized
	int _Isize; // Number of initial states
	int _Tsize; // Number of terminal states
	int _Qsize; // Number of finished states
	int _Asize; // Number of characters recognized

};

#endif /* AUTOMATON_H_ */
