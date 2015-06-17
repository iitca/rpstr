#pragma once
#ifndef RL_ENVIRONMENT_H
#define RL_ENVIRONMENT_H

#include "RLEnvironmentBase.h"
#include "RLActionBase.h"
#include "RLDiscreteAction.h"
#include "RLState.h"
#include "RLSystem.h"
#include "RLActionConverter.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

template<typename Ty1, 
	typename Ty2, 
	typename Ty3>
class RLEnvironment : RL::RLEnvironmentBase{

public:
	RLEnvironment(RLActionConverter<Ty1>);

	//the method is called by the outer code
	void setState(std::vector<double>);

	//the method is called by the outer code
	void setFeedback(std::vector<double>);

	//returns the resulting number
	vector<double> getResultVec();

	void setConsider(std::vector<double>);

	//drives the wheel
	void drive();

private:
	vector<double> feedback;
	RLState<Ty3> rlState;
	RLSystem<Ty1,Ty2,Ty3> rlSystem;
	RLActionConverter<Ty1> actionConverter;

	//override.
	virtual RL::RLActionBase* getAction() override;
};

template<typename Ty1, 
	typename Ty2, 
	typename Ty3> 
RLEnvironment<Ty1,Ty2,Ty3>::RLEnvironment(RLActionConverter<Ty1> conv){
	this ->actionConverter = conv;
}

template<typename Ty1, 
	typename Ty2, 
	typename Ty3> 
RL::RLActionBase* RLEnvironment<Ty1,Ty2,Ty3>::getAction(){
	//retrive the action from the system
	return (RL::RLActionBase*)rlSystem.getAction();
}

template<typename Ty1, 
	typename Ty2, 
	typename Ty3> 
void RLEnvironment<Ty1,Ty2,Ty3>::setFeedback(std::vector<double> fdb){
	//set the feedback
	this ->feedback = fdb;
	this ->rlSystem.setFeedback(fdb);
}

template<typename Ty1, 
	typename Ty2, 
	typename Ty3> 
void RLEnvironment<Ty1,Ty2,Ty3>::setState(std::vector<double> features){
	//set the new state
	this ->rlState.features = features;
	//get RLState out of features
	RLState<Ty3> state;
	state.features = features;
	this ->rlSystem.setState(state);
}

template<typename Ty1, 
	typename Ty2, 
	typename Ty3> 
void RLEnvironment<Ty1,Ty2,Ty3>::drive(){
	//make the next iteration
	this ->rlSystem.doNextIteration();	
}

template<typename Ty1, 
	typename Ty2, 
	typename Ty3> 
std::vector<double> RLEnvironment<Ty1,Ty2,Ty3>::getResultVec(){
	//lets get the resulting vector
	RLDiscreteAction<Ty1>* action = (RLDiscreteAction<Ty1>*)this ->getAction();
	this ->actionConverter.convert(*action);
	//return the resulting vector
	return this ->actionConverter.getRes();
}

template<typename Ty1, 
	typename Ty2, 
	typename Ty3>
void RLEnvironment<Ty1,Ty2,Ty3>::setConsider(std::vector<double> consVec){
	this ->actionConverter.consider(consVec);
}

#endif