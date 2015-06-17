#pragma once
#ifndef RL_ACTION_H
#define RL_ACTION_H

#include "RLActionBase.h"
#include <vector>
#include <algorithm>

template <typename T> 
bool zeroCond(T _val){
	return _val == (T)0;
}

template <typename T>
class RLAction : public RL::RLActionBase {
public:
	RLAction(unsigned int);
	//override from the base class
	bool operator==(const RLActionBase&);
	//set params
	virtual void setParams(const std::vector<T>);
	//get params
	virtual std::vector<T> getParams();
	//check if it is zero action
	bool isZero();
protected:
	std::vector<T> params;
};

template <typename T> RLAction<T>::RLAction(unsigned int size){
	this ->params.clear();
	this ->params.resize(size);
}

template <typename T> bool RLAction<T>::operator==(const RL::RLActionBase& val){
	return (this ->params == ((RLAction&)val).params);
}

template <typename T> void RLAction<T>::setParams(const std::vector<T> params){
	this ->params = params;
}

template <typename T> std::vector<T> RLAction<T>::getParams(){
	return this ->params;
}

template <typename T> bool RLAction<T>::isZero(){
	return std::all_of(this ->params.begin(), this ->params.end(), zeroCond<T>);
}

#endif