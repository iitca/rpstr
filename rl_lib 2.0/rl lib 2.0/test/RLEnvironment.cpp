#include "RLEnvironment.h"

using namespace RLENTITY_NMSPC;

void RLEnvironment::GetState()
{

}
RLStateBase* RLEnvironment::GetStoredCurrState()
{
	return this->currState;
}

RLStateBase* RLEnvironment::GetStoredNextState()
{
	return this->nextState;
}
void RLEnvironment::GetReward()
{

}
RLRewardBase* RLEnvironment::GetStoredReward()
{
	return this->reward;
}
void RLEnvironment::PerformAction(RLActionBase*)
{

}