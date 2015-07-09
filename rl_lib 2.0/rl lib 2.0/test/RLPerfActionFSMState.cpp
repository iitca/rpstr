#include "RLPerfActionFSMState.h"
#include "RLFSM.h"

using namespace RLFSM_NMSPC;


RLPerfActionFSMState::RLPerfActionFSMState(RLFSMStatesEnum stateName)
{
	this->thisStateName = stateName;
}

void RLPerfActionFSMState::Do(RLFSM* rlfsm)
{
	rlfsm->GetRLEntity()->PerfAction();
}