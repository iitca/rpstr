#pragma once
#ifndef RL_LEARNING_H
#define RL_LEARNING_H

#include "RLLearningBase.h"
#include "RLStateBase.h"
#include "RLActionBase.h"
#include "RLState.h"
#include "RLDiscreteAction.h"
#include "RLWTable.h"
#include "RLOpts.h"
#include <vector>

						
#define _RL_ALPHA		0.0001l
#define _RL_ALPHA_DECAY	0.9999999999999999999l
#define _RL_GAMMA		0.9l
#define _RL_ACT_NUM	3u
#define _RL_EXPLORATION_STOP_THRESH 1000000

template <typename Ty1, 
	typename Ty2,
	typename Ty3>
class RLLearning : RL::RLLearningBase{
public:
	RLLearning();
	//override
	virtual void update() override;
	//set current parameters (variables)
	void setState(RLState<Ty3>);
	//set obtained reward
	void setFeedback(std::vector<double>);
	//set action
	void setAction(RLDiscreteAction<Ty1>*);
	//returns best action
	RLDiscreteAction<Ty1>* getBestAction();
	//returns the visit count
	unsigned int getVisitCount(RLState<Ty3>, RLDiscreteAction<Ty1>);

private:
	unsigned long tick;
	//vector of params from the environment, THE CURRENT STATE
	RLState<Ty3> state;
	//the previous state
	RLState<Ty3> prevState;
	//chosen action from THE PREVIOUS STATE!
	RLDiscreteAction<Ty1> action;
	//previous action
	RLDiscreteAction<Ty1> prevAction;
	//number of parameters
	unsigned int paramsNum;
	//reward from environment
	std::vector<double> reward;
	//alpha param
	double alpha;
	//gamma param
	double gamma;
	//returns Qmax
	double getQmax();
	//calculates overall reward
	double getRwrd();
	//w table. weights table
	RLWTable<Ty2,Ty1,Ty3> wTable;
};

template <typename Ty1, 
	typename Ty2,
	typename Ty3> 
RLLearning<Ty1,Ty2,Ty3>::RLLearning() : action(RLOpts::getInstance().actionsNum,
																					RLOpts::getInstance().numOfChunks, 
																					RLOpts::getInstance().ranges),

										prevAction(RLOpts::getInstance().actionsNum,
																					RLOpts::getInstance().numOfChunks, 
																					RLOpts::getInstance().ranges),

										state(RLOpts::getInstance().featuresNum),
										prevState(RLOpts::getInstance().featuresNum)



{
	this ->reward.clear();
	this ->alpha = _RL_ALPHA;
	this ->gamma = _RL_GAMMA;
	this ->paramsNum = _RL_ACT_NUM;
	this ->tick = 0;
}

template <typename Ty1, 
	typename Ty2,
	typename Ty3> 
void RLLearning<Ty1,Ty2,Ty3>::update(){
	if(this ->tick < _RL_EXPLORATION_STOP_THRESH) this ->tick ++;
	//get qmax
	double qMax = this ->getQmax();
	//here we should update the weights of a certain action
	//set the previous action
	if(wTable.isEmpty()) wTable.setAction(this ->action);
	else wTable.setAction(this ->prevAction);
	//fetch the w vector. check if the table is empty or not
	std::vector<Ty2> weights = wTable.get();
	//check if w vector is empty
	if(weights.empty()){
		//it is empty - the action has not been taken yet - means w should be initialized with 0s
		for(int i =0; i < this ->state.features.size(); i++){
			weights.push_back(0.0);
		}
	}
	double diff = (this ->getRwrd() + this ->gamma * qMax) - this ->prevState.getQ(weights);
	//decrease alpha
	this ->alpha *= _RL_ALPHA_DECAY;
	//recalc new weights
	for(int i = 0; i < this ->prevState.features.size(); i++){
		//recalculate the weights
		if(weights.size() == i) weights.push_back((this ->alpha * diff) * prevState.features[i]);
		else weights[i] = weights[i] + this ->alpha * diff * prevState.features[i];
	}
	//put the updated vector of weights back to the wTable
	wTable.put(weights);
	//rewrite the previous state
	this ->prevState = this ->state;
}

template <typename Ty1, 
	typename Ty2,
	typename Ty3> 
void RLLearning<Ty1,Ty2,Ty3>::setState(RLState<Ty3> state){
	this ->state = state;
}

template <typename Ty1, 
	typename Ty2,
	typename Ty3> 
void RLLearning<Ty1,Ty2,Ty3>::setAction(RLDiscreteAction<Ty1>* action){
	this ->prevAction = this ->action;
	this ->action = *action;
}

template <typename Ty1, 
	typename Ty2,
	typename Ty3> 
void RLLearning<Ty1,Ty2,Ty3>::setFeedback(std::vector<double> feedback){
	this ->reward = feedback;
}

template <typename Ty1, 
	typename Ty2,
	typename Ty3> 
double RLLearning<Ty1,Ty2,Ty3>::getQmax(){
	//the hardest part. choose 
	double qMax = 0.0;
	//get action with the max Q
	RLDiscreteAction<Ty1>* maxAction = this ->getBestAction();
	//get w vector
	wTable.setAction(*maxAction);
	std::vector<double> w = wTable.get();
	//get Q
	qMax = this ->state.getQ(w);
	return qMax;
}

template <typename Ty1, 
	typename Ty2,
	typename Ty3> 
RLDiscreteAction<Ty1>* RLLearning<Ty1,Ty2,Ty3>::getBestAction(){
	//get action with the max Q
	return wTable.getMaxQAction(this ->state);
}

template <typename Ty1, 
	typename Ty2,
	typename Ty3> 
double RLLearning<Ty1,Ty2,Ty3>::getRwrd(){
	double rwrd = 0.0;
	for(int i = 0; i < this ->reward.size(); i++)
		rwrd += this ->reward[i];
	return rwrd;
}

#endif