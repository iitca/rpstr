#include "RLFSM.h"
#include "RLEntity.h"
#include "RLAgent.h"
#include "RLEnvironment.h"
#include "RLLearning.h"


using namespace RLFSM_NMSPC;
using namespace RLENTITY_NMSPC;

int main()
{
	RLFSMTransitionTable* rltt = new RLFSMTransitionTable();
	RLLearning* rlLearn = new RLLearning();
	RLAgent* rlAgent = new RLAgent(rlLearn);
	RLEnvironment* rlEnv = new RLEnvironment();

	RLEntity* rlent = new RLEntity(rlAgent, rlEnv);
	RLFSM rlfsm(rltt, rlent);

	RLFSMState* state = RLFSMFactory::CreateState(RLFSMStatesEnum::RL_OBSRV_CURR_FSM_STATE);
	rlfsm.SetFSMState(state);
	rlfsm.Update();
}