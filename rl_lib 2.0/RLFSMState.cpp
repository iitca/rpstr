#include "RLFSMState.h"
#include "RLFSM.h"
#include "RLFSMFactory.h"
#include "RLFSMTransitionTable.h"


using namespace RLFSM_NMSPC;


void RLFSMState::Print()
{
	std::cout << "State name : " << this ->thisStateName << std::endl;
}

void RLFSMState::Transit(RLFSM* rlfsm)
{
	/*here we get the next state from the transition table
	and create an instance of the new state through the factory*/
	//get the next state's name
	RLFSMStatesEnum nextStateName = rlfsm->GetTransitionTable()->GetNextFSMState(this->thisStateName);
	//create the next state instance
	RLFSMState* state = RLFSMFactory::CreateState(nextStateName);
	//assign the next state to the FSM
	rlfsm->SetFSMState(state);
	//delete this object
	delete this;
}