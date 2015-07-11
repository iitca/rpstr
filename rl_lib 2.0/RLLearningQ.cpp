#include "RLLearningQ.h"

using namespace RLENTITY_NMSPC;

void RLLearningQ::Update(RLStateActionBase* stateActionPrev, RLStateBase* state, RLRewardBase* reward)
{
	/*
	here we update a table with a new value, calculated according to:
	diff = (r + gamma*Qmax)-Q -> Q here is the value, 
	assigned to the previous state with the current action
	Q := Q + alpha * diff
	*/

	//old Q of the previous state-action
	double Qold = this->table->Get(stateActionPrev);
	//Qmax of the current state
	double Qmax = this->table->GetMax(state);
	
	//arbitrary learning rate and discount factor
	double alpha = 0.1;
	double gamma = 0.9;

	//new Q
	double Qnew = Qold + alpha * (reward ->GetValue() + gamma * Qmax - Qold);

	//set the new value to the table
	this->table->Set(stateActionPrev, Qnew);
	
}