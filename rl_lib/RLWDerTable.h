//#pragma once
//#ifndef NOXIM_RL_Q_TABLE
//#define NOIXM_RL_Q_TABLE
//
//#include "RLTable.h"
//#include <vector>
//#include <map>
//#include <iostream>
//#include <fstream>
//#include "NoximRLDiscreteAction.h"
//#include "NoximRLState.h"
//#include "NoximRLOpts.h"
//
//template <typename Ty1,
//	typename Ty2,
//	typename Ty3>
//class NoximRLWDerTable : RL::RLTable<Ty1> {
//public:
//	NoximRLWDerTable();
//	//override
//	virtual void put(std::pair<std::vector<Ty1>, double>) override;
//	//override
//	virtual std::pair<std::vector<Ty1>, double> get() override;
//	//get the action which returns the max Q at the certain state
//	NoximRLDiscreteAction<Ty2>* getMaxQAction(NoximRLState<Ty3>);
//	//set an action
//	void setAction(NoximRLDiscreteAction<Ty2>);
//	//checks if empty
//	bool isEmpty();
//
//private:
//	//this is a map
//	//first value is an action
//	//second value is a pair of a vector of weights and derivative
//	std::map<NoximRLDiscreteAction<Ty2>, std::pair<std::vector<Ty1>, double>> wTable;
//	//action we work with
//	NoximRLDiscreteAction<Ty2> action;
//	//lets write the results of the simulation in the file
//	std::ofstream weightsOutFile;
//};
//
//
//template <typename Ty1,
//	typename Ty2,
//	typename Ty3> 
//NoximRLWDerTable<Ty1,Ty2,Ty3>::NoximRLWDerTable() : action(NoximRLOpts::getInstance().actionsNum, 
//																				NoximRLOpts::getInstance().numOfChunks, 
//																				NoximRLOpts::getInstance().ranges){
//	wTable.clear();
//	weightsOutFile.open("RL_Action_Weights_Table.txt");
//}
//
//template <typename Ty1,
//	typename Ty2,
//	typename Ty3> 
//void NoximRLWDerTable<Ty1,Ty2,Ty3>::put(std::pair<std::vector<Ty1>, double> wDer){
//	//check if the element is already in the table
//	if(!wTable.count(this ->action)) wTable.insert(std::make_pair(this ->action, wDer));
//	else wTable[action] = wDer;
//
//	this ->weightsOutFile << "Action vector -> Weights vector  :";
//	for(int i = 0; i < this ->action.getDiscreteVals().size(); i++){
//		this ->weightsOutFile << " " << action.getDiscreteVals()[i] << " ";
//	}
//
//	this ->weightsOutFile << "	->	";
//	for(int i = 0; i < wDer.first.size(); i++){
//		this ->weightsOutFile << " " << wDer.first[i] << " ";
//	}
//	this ->weightsOutFile << endl;
//}
//
//template <typename Ty1,
//	typename Ty2,
//	typename Ty3> 
//std::pair<std::vector<Ty1>, double> NoximRLWDerTable<Ty1,Ty2,Ty3>::get(){
//	std::pair<std::vector<Ty1>, double> w;
//	w.first.clear();
//	//if there is the action in a table
//	if(wTable.count(this ->action)) 
//		return wTable[this ->action];
//	else
//		return w;
//}
//
//template <typename Ty1,
//	typename Ty2,
//	typename Ty3> 
//void NoximRLWDerTable<Ty1,Ty2,Ty3>::setAction(NoximRLDiscreteAction<Ty2> action){
//	this ->action = action;
//}
//
//template <typename Ty1,
//	typename Ty2,
//	typename Ty3> 
//bool NoximRLWDerTable<Ty1,Ty2,Ty3>::isEmpty(){
//	return wTable.empty();
//}
//
//template <typename Ty1,
//	typename Ty2,
//	typename Ty3> 
//NoximRLDiscreteAction<Ty2>* NoximRLWDerTable<Ty1,Ty2,Ty3>::getMaxQAction(NoximRLState<Ty3> state){
//	double qMax = 0.0;
//	NoximRLDiscreteAction<Ty2>* action = new NoximRLDiscreteAction<Ty2>(NoximRLOpts::getInstance().actionsNum, NoximRLOpts::getInstance().numOfChunks, NoximRLOpts::getInstance().ranges);
//	//we need to check it the table is empty!
//	if(!this ->wTable.empty()){
//		//get iterator
//		std::map<NoximRLDiscreteAction<Ty2>, std::pair<std::vector<Ty1>, double>>::iterator it = this ->wTable.begin();
//		//initialize the action
//		*action = it ->first;
//		//iterate!
//		for(;it != wTable.end(); it++){
//			//get Q
//			double qTemp = 0.0;
//			qTemp = state.getQ(it ->second.first);
//			//check if its the new max
//			if(qTemp > qMax){
//				//new max value
//				qMax = qTemp;
//				*action = it ->first;
//			}
//		}
//	}
//	return action;
//}
//
//#endif