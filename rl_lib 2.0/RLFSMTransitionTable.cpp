#include "RLFSMTransitionTable.h"

using namespace RLFSM_NMSPC;

RLFSMTransitionTable::RLFSMTransitionTable()
{
	trans = { RLFSMStatesEnum::RL_OBSRV_CURR_FSM_STATE,
		RLFSMStatesEnum::RL_SEL_ACTION_FSM_STATE,
		RLFSMStatesEnum::RL_PERF_ACTION_FSM_STATE,
		RLFSMStatesEnum::RL_OBSRV_NEXT_FSM_STATE,
		RLFSMStatesEnum::RL_GET_REWARD_FSM_STATE,
		RLFSMStatesEnum::RL_ADJUST_Q_FSM_STATE
	};
}

RLFSMStatesEnum RLFSMTransitionTable::GetNextFSMState(RLFSMStatesEnum state)
{
	for (unsigned int i = 0; i < trans.size(); i++){
		if (trans[i] == state){
			if (i == trans.size() - 1) 
				return trans[0];
			else 
				return trans[i + 1];
		}
	}
	return trans[0];
}