#ifndef RLENVIRONMENTBASE_H
#define RLENVIRONMENTBASE_H

#include "RLActionBase.h"
#include "RLStateBase.h"
#include "RLRewardBase.h"

namespace RLENTITY_NMSPC
{
	class RLEnvironmentBase
	{
	public:
		RLEnvironmentBase() : currState(nullptr), nextState(nullptr), reward(nullptr){};
		virtual void GetState() = 0;
		virtual RLStateBase* GetStoredCurrState() = 0;
		virtual RLStateBase* GetStoredNextState() = 0;
		virtual void GetReward() = 0;
		virtual RLRewardBase* GetStoredReward() = 0;
		virtual void PerformAction(RLActionBase*) = 0;
	protected:
		RLStateBase* currState;
		RLStateBase* nextState;
		RLRewardBase* reward;
	};
}

#endif 