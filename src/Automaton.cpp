/**
 *@file	Automaton.cpp
 *@author Alpha
 *@version
 *@date 22 avr. 2013
 *@brief
 *@details
 */

#include "../include/Automaton.h"
#include <stdlib.h>

/**
 *
 */
Automaton::Automaton() {
	_standard = false;
	_determinized = false;
	_minimized = false;
	_completed = false;

	_T = NULL;
	_I = NULL;
	_Q = NULL;
	_A = NULL;
	_Tsize = 0;
	_Asize = 0;
	_Qsize = 0;
	_Isize = 0;
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

	_Tsize = automaton._Tsize;
	_Isize = automaton._Isize;
	_Qsize = automaton._Qsize;
	_Asize = automaton._Asize;
	_T = new int[_Tsize];
	_I = new int[_Isize];
	_Q = new int[_Qsize];
	_A = new int[_Asize];
	/*
	fill(_T, automaton._T);
	fill(_Q, automaton._Q);
	fill(_A, automaton._A);
	fill(_I, automaton._I);
	*/
}

/**
 *
 */
Automaton::~Automaton() {
	delete[] _T;
	delete[] _I;
	delete[] _A;
	delete[] _Q;
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
int* Automaton::getA() const {
	return _A;
}

/**
 *
 * @param a
 */
void Automaton::setA(int* a) {
	_A = a;
}

/**
 *
 * @return
 */
int* Automaton::getI() const {
	return _I;
}

/**
 *
 * @param i
 */
void Automaton::setI(int* i) {
	_I = i;
}

/**
 *
 * @return
 */
int* Automaton::getQ() const {
	return _Q;
}

/**
 *
 * @param q
 */
void Automaton::setQ(int* q) {
	_Q = q;
}

/**
 *
 * @return
 */
int* Automaton::getT() const {
	return _T;
}

/**
 *
 * @param t
 */
void Automaton::setT(int* t) {
	_T = t;
}

/**
 *
 * @return
 */
int Automaton::getAsize() const {
	return _Asize;
}

/**
 *
 * @param asize
 */
void Automaton::setAsize(int asize) {
	_Asize = asize;
}

/**
 *
 * @return
 */
int Automaton::getIsize() const {
	return _Isize;
}

/**
 *
 * @param isize
 */
void Automaton::setIsize(int isize) {
	_Isize = isize;
}

/**
 *
 * @return
 */
int Automaton::getQsize() const {
	return _Qsize;
}

/**
 *
 * @param qsize
 */
void Automaton::setQsize(int qsize) {
	_Qsize = qsize;
}

/**
 *
 * @return
 */
int Automaton::getTsize() const {
	return _Tsize;
}

/**
 *
 * @param tsize
 */
void Automaton::setTsize(int tsize) {
	_Tsize = tsize;
}

/**
 * @brief Dynamic array filler
 * @param charac1
 * @param charac2
 */
void fill(const int* charac1, const int* charac2) {
	return;
}
