#include "RLAdjQFSMState.h"
#include "RLFSM.h"

using namespace RLFSM_NMSPC;

RLAdjQFSMState::RLAdjQFSMState(RLFSMStatesEnum stateName)
{
	this->thisStateName = stateName;
}

void RLAdjQFSMState::Do(RLFSM* rlfsm)
{
	rlfsm->GetRLEntity()->AdjQ();
}