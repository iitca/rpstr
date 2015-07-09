#include "RLFSMFactory.h"
#include "RLFSMState.h"
#include "RLObsrvCurrentFSMState.h"
#include "RLObsrvNextFSMState.h"
#include "RLSelActionFSMState.h"
#include "RLPerfActionFSMState.h"
#include "RLGetRewardFSMState.h"
#include "RLAdjQFSMState.h"

using namespace RLFSM_NMSPC;

RLFSMState* RLFSMFactory::CreateState(RLFSMStatesEnum stateEnum)
{
	RLFSMState* state;
	switch (stateEnum)
	{
	case RLFSMStatesEnum::RL_OBSRV_CURR_FSM_STATE:
		{
			state = new	RLObsrvCurrentFSMState(RLFSMStatesEnum::RL_OBSRV_CURR_FSM_STATE);
			break;
		}
	case RLFSMStatesEnum::RL_SEL_ACTION_FSM_STATE:
		{
			state = new RLSelActionFSMState(RLFSMStatesEnum::RL_SEL_ACTION_FSM_STATE);
			break;
		}
	case RLFSMStatesEnum::RL_PERF_ACTION_FSM_STATE:
		{
			state = new RLPerfActionFSMState(RLFSMStatesEnum::RL_PERF_ACTION_FSM_STATE);
			break;
		}
	case RLFSMStatesEnum::RL_OBSRV_NEXT_FSM_STATE:
		{
			state = new RLObsrvNextFSMState(RLFSMStatesEnum::RL_OBSRV_NEXT_FSM_STATE);
			break;
		}
	case RLFSMStatesEnum::RL_GET_REWARD_FSM_STATE:
		{
			state = new RLGetRewardFSMState(RLFSMStatesEnum::RL_GET_REWARD_FSM_STATE);
			break;
		}
	case RLFSMStatesEnum::RL_ADJUST_Q_FSM_STATE:
		{
			state = new RLAdjQFSMState(RLFSMStatesEnum::RL_ADJUST_Q_FSM_STATE);
			break;
		}
	default:{}
	}
	return state;
}