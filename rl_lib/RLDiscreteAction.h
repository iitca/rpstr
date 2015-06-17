#pragma once
#ifndef RL_DISCRETIZER_ACTION_H
#define RL_DISCRETIZER_ACTION_H

#include "RLDiscretizer.h"
#include "RLAction.h"
#include "RLActionBase.h"
#include <vector>
#include <tuple>

template <typename T>
class RLDiscreteAction : public RLAction<T>, RLDiscretizer {
public:
	RLDiscreteAction(unsigned int, std::vector<unsigned int>, std::vector<double> );
	//override
	virtual void setNumberOfChunks(const std::vector<unsigned int>) override;
	std::vector<unsigned int> getNumberOfChunks();
	//override
	virtual void setRanges(const std::vector<double>) override;
	std::vector<double> getRanges();
	//override the set function of the RLAction
	virtual void setParams(const std::vector<T>) override;
	//override the get function of the RLAction
	virtual std::vector<T> getParams() override;
	//get discrete params
	std::vector<unsigned int> getDiscreteVals();
	//need also to override "<" operator to be able to use this class in an std::map
	bool operator <(const RLDiscreteAction& val) const;
	//need also to override "==" operator to be able to use this class in an std::map
	bool operator ==(const RLDiscreteAction& val) const;
	//override = operator
	//size_t override for some hash function implementation
	operator size_t () const;
private:
	///number of slots we divide rahnges to
	std::vector<unsigned int> chunks;
	///our ranges
	std::vector<double> ranges;
	std::vector<unsigned int> discrParams;
};

template <typename T> RLDiscreteAction<T>::RLDiscreteAction(unsigned int actionsParamSize, std::vector<unsigned int> numOfChunks, std::vector<double> ranges) : RLAction(actionsParamSize), chunks(numOfChunks), ranges(ranges){
	for(int i = 0; i < actionsParamSize; i++) this ->discrParams.push_back(0);
}

template <typename T> void RLDiscreteAction<T>::setNumberOfChunks(const std::vector<unsigned int> chunks){
	this ->chunks = chunks;
}

template <typename T> void RLDiscreteAction<T>::setRanges(const std::vector<double> ranges){
	this ->ranges = ranges;
}

//overriden
template <typename T> void RLDiscreteAction<T>::setParams(const std::vector<T> params){
	this ->params = params;

	std::vector<unsigned int> discrParams;
	discrParams.resize(this ->getParams().size());

	for(int i = 0; i < this ->getParams().size(); i++){
		double up = 0.0;
		double step = this ->ranges[i]/this ->chunks[i];
		while(this ->getParams()[i] > up){
			up += step;
		}
		discrParams[i] = static_cast<unsigned int>(up);
	}
	this ->discrParams = discrParams;
}

template <typename T> std::vector<T> RLDiscreteAction<T>::getParams(){
	return this ->params;
}

template <typename T> std::vector<unsigned int> RLDiscreteAction<T>::getDiscreteVals(){
	return this ->discrParams;
}


template <typename T> bool RLDiscreteAction<T>::operator<(const RLDiscreteAction<T> &val) const{
	return this ->params < val.params;
}

template <typename T> bool RLDiscreteAction<T>::operator==(const RLDiscreteAction<T> &val) const{
	return this ->params == val.params;
}

template <typename T> RLDiscreteAction<T>::operator size_t() const{
	std::hash<unsigned int> hash;
	std::size_t result = 0;
	for(int i = 0; i < this ->discrParams.size(); i++){
		result ^= hash(this ->discrParams[i]);
	}
	return result;
}

template <typename T> std::vector<unsigned int> RLDiscreteAction<T>::getNumberOfChunks(){
	return this ->chunks;
}

template <typename T> std::vector<double> RLDiscreteAction<T>::getRanges(){
	return this ->ranges;
}
#endif