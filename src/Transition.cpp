/**
 *@file	Transition.cpp
 *@author Alpha
 *@version
 *@date 30 avr. 2013
 *@brief
 *@details
 */

#include "../include/Transition.h"

/**
 *
 * @param tag
 * @param stateBegin
 * @param stateEnd
 */
Transition::Transition(const int& tag = -1, const int& stateBegin = -1, const int& stateEnd = -1) {
	_tag = tag;
	_stateBegin = stateBegin;
	_stateEnd = stateEnd;
}

Transition::~Transition() {
	// TODO Auto-generated destructor stub
}

/**
 *
 * @return
 */
int Transition::getStateBegin() const {
	return _stateBegin;
}

/**
 *
 * @param stateBegin
 */
void Transition::setStateBegin(int stateBegin) {
	_stateBegin = stateBegin;
}

/**
 *
 * @return
 */
int Transition::getStateEnd() const {
	return _stateEnd;
}

/**
 *
 * @param stateEnd
 */
void Transition::setStateEnd(int stateEnd) {
	_stateEnd = stateEnd;
}

/**
 *
 * @return
 */
int Transition::getTag() const {
	return _tag;
}

/**
 *
 * @param tag
 */
void Transition::setTag(int tag) {
	_tag = tag;
}
