#pragma once
#ifndef RL_STATE_H
#define RL_STATE_H

#include "RLStateBase.h"
#include <vector>
#include <functional>

template<typename T = double>
class RLState : RL::RLStateBase{

public:
	RLState(){};
	RLState(unsigned int);
	bool operator==(const RLStateBase&);
	//here is some hash function implementation
	operator size_t () const;
	//calculate the Q value as a multiplication of 2 vectors
	double getQ(std::vector<double>);
	//features
	std::vector<T> features;
private:
	
};

template<typename T> RLState<T>::RLState(unsigned int numOfFeatures){
	this ->features.resize(numOfFeatures);
}

template<typename T> bool  RLState<T>::operator==(const RLStateBase& val){
		return (this ->features == ((RLState<T>&)val).features);
	}

template<typename T> RLState<T>::operator size_t () const {
	std::hash<double> hash;
	std::size_t result = 0;
	for(int i = 0; i < this ->features.size(); i++){
		result ^= hash(this ->features[i]);
	}
	return result;
}

template<typename T> double RLState<T>::getQ(std::vector<double> w){
	double q = 0.0;
	//if the size of the features is 0 - return 0
	if(this ->features.size() == 0) return 0.0;
	for(int i = 0; i < w.size(); i++)
		q += w[i]* this->features[i];
	return q;
}


#endif