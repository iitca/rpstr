#include "RLSelActionFSMState.h"
#include "RLFSM.h"

using namespace RLFSM_NMSPC;

RLSelActionFSMState::RLSelActionFSMState(RLFSMStatesEnum stateName)
{
	this->thisStateName = stateName;
}

void RLSelActionFSMState::Do(RLFSM* rlfsm)
{
	rlfsm->GetRLEntity()->SelAction();
}