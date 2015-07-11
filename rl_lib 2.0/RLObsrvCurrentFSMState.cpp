#include "RLObsrvCurrentFSMState.h"
#include "RLFSM.h"

using namespace RLFSM_NMSPC;

RLObsrvCurrentFSMState::RLObsrvCurrentFSMState(RLFSMStatesEnum stateName)
{
	this->thisStateName = stateName;
}

void RLObsrvCurrentFSMState::Do(RLFSM* rlfsm)
{
	rlfsm->GetRLEntity()->ObsrvCurrState();
}