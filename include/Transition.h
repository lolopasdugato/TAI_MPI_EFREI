/**
 *@file	Transition.h
 *@author Alpha
 *@version
 *@date 30 avr. 2013
 *@brief
 *@details
 */

#ifndef TRANSITION_H_
#define TRANSITION_H_

class Transition {
public:
	Transition(const int& tag = -1, const int& stateBegin = -1, const int& stateEnd = -1);
	virtual ~Transition();
	int getStateBegin() const;
	void setStateBegin(int stateBegin);
	int getStateEnd() const;
	void setStateEnd(int stateEnd);
	int getTag() const;
	void setTag(int tag);

private:
	int _stateBegin;
	int _stateEnd;
	int _tag;
};

#endif /* TRANSITION_H_ */
