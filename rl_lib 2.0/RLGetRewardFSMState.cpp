#include "RLGetRewardFSMState.h"
#include "RLFSM.h"

using namespace RLFSM_NMSPC;

RLGetRewardFSMState::RLGetRewardFSMState(RLFSMStatesEnum stateName)
{
	this->thisStateName = stateName;
}

void RLGetRewardFSMState::Do(RLFSM* rlfsm)
{
	rlfsm->GetRLEntity()->GetReward();
}