#pragma once
#ifndef RL_Q_TABLE
#define RL_Q_TABLE

#include "RLTableBase.h"
#include <vector>
#include <map>
#include <fstream>
#include "RLDiscreteAction.h"
#include "RLState.h"
#include "RLOpts.h"
#include <math.h>

template <typename Ty1,
	typename Ty2,
	typename Ty3>
class RLWTable : RL::RLTableBase<Ty1> {
public:
	RLWTable();
	//override
	virtual void put(std::vector<Ty1>) override;
	//override
	virtual std::vector<Ty1> get() override;
	//get the action which returns the max Q at the certain state
	RLDiscreteAction<Ty2>* getMaxQAction(RLState<Ty3>);
	//set an action
	void setAction(RLDiscreteAction<Ty2>);
	//checks if empty
	bool isEmpty();

private:
	//this is a map
	//first value is an action
	//second value is a vector of weights
	std::map<RLDiscreteAction<Ty2>, std::vector<Ty1>> wTable;
	//action we work with
	RLDiscreteAction<Ty2> action;
	//lets write the results of the simulation in the file
	std::ofstream weightsOutFile;
};


template <typename Ty1,
	typename Ty2,
	typename Ty3> 
RLWTable<Ty1,Ty2,Ty3>::RLWTable() : action(RLOpts::getInstance().actionsNum, 
																				RLOpts::getInstance().numOfChunks, 
																				RLOpts::getInstance().ranges){
	wTable.clear();
	weightsOutFile.open("RL_Action_Weights_Table.txt");
}

template <typename Ty1,
	typename Ty2,
	typename Ty3> 
void RLWTable<Ty1,Ty2,Ty3>::put(std::vector<Ty1> w){
	//check if the element is already in the table
	if(!wTable.count(this ->action)) wTable.insert(std::make_pair(this ->action, w));
	else {
		wTable[action] = w;
	}
}

template <typename Ty1,
	typename Ty2,
	typename Ty3> 
std::vector<Ty1> RLWTable<Ty1,Ty2,Ty3>::get(){
	std::vector<Ty1> w;
	w.clear();
	int num = wTable.size();
	//if there is the action in a table
	if(wTable.count(this ->action)) 
		return wTable[this ->action];
	else
		return w;
}

template <typename Ty1,
	typename Ty2,
	typename Ty3> 
void RLWTable<Ty1,Ty2,Ty3>::setAction(RLDiscreteAction<Ty2> action){
	this ->action = action;
}

template <typename Ty1,
	typename Ty2,
	typename Ty3> 
bool RLWTable<Ty1,Ty2,Ty3>::isEmpty(){
	return wTable.empty();
}

template <typename Ty1,
	typename Ty2,
	typename Ty3> 
RLDiscreteAction<Ty2>* RLWTable<Ty1,Ty2,Ty3>::getMaxQAction(RLState<Ty3> state){
	bool init = false;
	double qMax = 0.0;
	RLDiscreteAction<Ty2>* action = new RLDiscreteAction<Ty2>(RLOpts::getInstance().actionsNum, RLOpts::getInstance().numOfChunks, RLOpts::getInstance().ranges);
	//we need to check it the table is empty!
	if(!this ->wTable.empty()){
		//get iterator
		std::map<RLDiscreteAction<Ty2>, std::vector<Ty1>>::iterator it = this ->wTable.begin();
		//initialize the action
		*action = it ->first;
		//iterate!
		for(;it != wTable.end(); it++){
			//get Q
			double qTemp = 0.0;
			qTemp = state.getQ(it ->second);
			//check if its the new max
			if(qTemp > qMax || !init){
				//new max value
				init = true;
				qMax = qTemp;
				*action = it ->first;
			}
		}
	}
	return action;
}

#endif