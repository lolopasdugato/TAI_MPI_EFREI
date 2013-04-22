/**
 *@file	Automaton.cpp
 *@author Alpha
 *@version
 *@date 22 avr. 2013
 *@brief
 *@details
 */

#include "../include/Automaton.h"

/**
 *
 */
Automaton::Automaton() {
	_standard = false;
	_determinized = false;
	_minimized = false;
	_completed = false;
}

Automaton::~Automaton() {
	// TODO Auto-generated destructor stub
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
