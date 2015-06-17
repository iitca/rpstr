#pragma once
#ifndef RL_SYSTEM_H
#define RL_SYSTEM_H


#include "RLSystemBase.h"
#include "RLAgent.h"
#include "RLState.h"
#include "RLDiscreteAction.h"
#include "RLOpts.h"
#include <vector>
#include <math.h>

#ifndef MAX_GEN_RL
	#define MAX_GEN_RL			100
#endif

#ifndef THRESH_RL
	#define THRESH_RL			2
#endif

#ifndef EPSILON_RL
	#define EPSILON_RL			MAX_GEN_RL/THRESH_RL
#endif

template<typename Ty1, 
	typename Ty2,
	typename Ty3>
class RLSystem : RL::RLSystemBase{

public:
	RLSystem();
	//override
	void doNextIteration();
	//sets the current state from the outer world
	void setState(RLState<Ty3>);
	//sets the reward from the outer world
	void setFeedback(std::vector<double>);
	//returns the chosen action to the outer world
	RLDiscreteAction<Ty1>* getAction();

private:
	RLAgent<Ty1,Ty2,Ty3> agent;
	RLDiscreteAction<Ty1> action;
	std::vector<double> rwrd;
	double p;
	unsigned long tick;
	//this function returns the probability, that reflects the ratio exploration/exploitation
	double getProbability();
};

template<typename Ty1, 
	typename Ty2,
	typename Ty3> 
RLSystem<Ty1,Ty2,Ty3>::RLSystem() : action(RLOpts::getInstance().actionsNum, RLOpts::getInstance().numOfChunks, RLOpts::getInstance().ranges){
	p = 0;
	tick = 0;
}

template<typename Ty1, 
	typename Ty2,
	typename Ty3> 
void RLSystem<Ty1,Ty2,Ty3>::doNextIteration(){
	//agent acts
	this ->agent.act();
	tick++;
}

template<typename Ty1, 
	typename Ty2,
	typename Ty3> 
void RLSystem<Ty1,Ty2,Ty3>::setState(RLState<Ty3> state){
	this ->agent.setState(state);
}

template<typename Ty1, 
	typename Ty2,
	typename Ty3> 
void RLSystem<Ty1,Ty2,Ty3>::setFeedback(std::vector<double> feedback){
	this ->rwrd = feedback;
	this ->agent.setFeedback(feedback);
}

template<typename Ty1, 
	typename Ty2,
	typename Ty3> 
RLDiscreteAction<Ty1>* RLSystem<Ty1,Ty2,Ty3>::getAction(){
	RLDiscreteAction<Ty1>* action = agent.chooseAction(this ->getProbability());
	this ->action = *action;
	return &this ->action;
}

template<typename Ty1, 
	typename Ty2,
	typename Ty3> 
double RLSystem<Ty1,Ty2,Ty3>::getProbability(){
	return 50;
}

#endif