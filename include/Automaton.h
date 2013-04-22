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
	virtual ~Automaton();
	bool isCompleted() const;
	void setCompleted(bool completed);
	bool isDeterminized() const;
	void setDeterminized(bool determinized);
	bool isMinimized() const;
	void setMinimized(bool minimized);
	bool isStandard() const;
	void setStandard(bool standard);

private:
	bool _completed;
	bool _determinized;
	bool _minimized;
	bool _standard;
};

#endif /* AUTOMATON_H_ */
