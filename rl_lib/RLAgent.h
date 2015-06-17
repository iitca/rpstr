#pragma once
#ifndef RL_AGENT_H
#define RL_AGENT_H

#include "RLAgentBase.h"
#include "RLActionBase.h"
#include "RLAction.h"
#include "RLState.h"
#include "RLLearning.h"
#include "RLDiscreteAction.h"
#include "RLOpts.h"
#include <stdlib.h>
#include <time.h>
#include <vector>



template<typename Ty1, 
	typename Ty2,
	typename Ty3>
class RLAgent : RL::RLAgentBase{
public:
	//constructor set the number of actions
	RLAgent();
	//act method - the main one
	virtual RL::RLActionBase* act() override;
	//set params(features) from the outer world
	void setState(RLState<Ty3>);
	//set reward from the outer world
	void setFeedback(std::vector<double>);
	//choose the action
	RLDiscreteAction<Ty1>* chooseAction(unsigned int);
private:
	//current state
	RLState<Ty3> state;
	//chosen action
	RLDiscreteAction<Ty1>* action;
	//RLDiscreteAction
	RLLearning<Ty1, Ty2, Ty3> apprQLearning;
};


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
RLAgent<Ty1,Ty2,Ty3>::RLAgent(){
	//randomizer initialization
	srand(time(NULL));
}

template<typename Ty1, 
	typename Ty2,
	typename Ty3> 
RL::RLActionBase* RLAgent<Ty1,Ty2,Ty3>::act(){
	//agents learns while acting
	this ->apprQLearning.setAction(this ->action);
	//update set of weights
	this ->apprQLearning.update();
	return (RL::RLActionBase*)action;
}

template<typename Ty1, 
	typename Ty2,
	typename Ty3> 
void RLAgent<Ty1,Ty2,Ty3>::setState(RLState<Ty3> state){
	this ->state = state;
	this ->apprQLearning.setState(state);
}

template<typename Ty1, 
	typename Ty2,
	typename Ty3>
void RLAgent<Ty1,Ty2,Ty3>::setFeedback(std::vector<double> reward){
	this ->apprQLearning.setFeedback(reward);
}

template<typename Ty1, 
	typename Ty2,
	typename Ty3> 
RLDiscreteAction<Ty1>* RLAgent<Ty1,Ty2,Ty3>::chooseAction(unsigned int epsilon){
	//choose the best action at the current state. if the table is empty the returned action will be empty
	RLDiscreteAction<Ty1>* action = this ->apprQLearning.getBestAction();
	//lets throw dices to decide if we want to go off the best action
	float p = (rand()%MAX_GEN_RL + 1);
	if((unsigned int)p > epsilon || action ->isZero()){
		//yes, we are going off the direction
		//now we decide on how much we want to diverge from the best action
		vector<Ty1> contVals;
		contVals.resize(action ->getParams().size());
		for(int i = 0; i < action ->getParams().size(); i++){
			//to choose a random action we just generate a random number from 1 to the numberOfChunks/4 for each parameter of the action
			unsigned int t = (rand()%action ->getNumberOfChunks()[i]);
			contVals[i] = t * action ->getRanges()[i]/action ->getNumberOfChunks()[i];
		}
		//set the chosen action
		action ->setParams(contVals);
	}
	this ->action = action;
	return action;	
}


#endif