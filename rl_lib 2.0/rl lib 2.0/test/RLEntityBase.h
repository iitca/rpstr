#ifndef RLENTITYBASE_H
#define RLENTITYBASE_H

#include "RLAgentBase.h"
#include "RLEnvironmentBase.h"

namespace RLENTITY_NMSPC
{
	//the interface for the RLFSM to be connected
	class RLEntityBase
	{
	public:
		RLEntityBase(RLAgentBase* agent, RLEnvironmentBase* env) : rlAgent(agent), rlEnv(env){}
		virtual void ObsrvCurrState() = 0;
		virtual void SelAction() = 0;
		virtual void PerfAction() = 0;
		virtual void ObsrvNextState() = 0;
		virtual void GetReward() = 0;
		virtual void AdjQ() = 0;
	protected:
		RLAgentBase* rlAgent;
		RLEnvironmentBase* rlEnv;
	};
}


#endif