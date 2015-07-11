#include "RLFSM.h"
#include "RLFSMState.h"

using namespace RLFSM_NMSPC;

RLFSM::RLFSM(RLFSMTransitionTable* rltt, RLENTITY_NMSPC::RLEntityBase* rlent)
{
	this->rltt = rltt;
	this->rlent = rlent;
	this->currentFSMState = nullptr;
}

void RLFSM::Update()
{
	for (;;)
	{
		if (currentFSMState != nullptr){
			//print out the state name
			currentFSMState->Print();
			//execute the actions for the state
			currentFSMState->Do(this);
			//transit to another state
			currentFSMState->Transit(this);
		}
	}
}

void RLFSM::SetFSMState(RLFSMState* fsmState)
{
	currentFSMState = fsmState;
}

RLFSMTransitionTable* RLFSM::GetTransitionTable()
{
	return this->rltt;
}

RLENTITY_NMSPC::RLEntityBase* RLFSM::GetRLEntity()
{
	return this->rlent;
}