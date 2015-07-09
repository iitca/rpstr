#include "RLObsrvNextFSMState.h"
#include "RLFSM.h"

using namespace RLFSM_NMSPC;

RLObsrvNextFSMState::RLObsrvNextFSMState(RLFSMStatesEnum stateName)
{
	this->thisStateName = stateName;
}

void RLObsrvNextFSMState::Do(RLFSM* rlfsm)
{
	rlfsm->GetRLEntity()->ObsrvNextState();
}
