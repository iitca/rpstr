#ifndef RLENVIRONMENT_H
#define RLENVIRONMENT_H

#include "RLEnvironmentBase.h"

namespace RLENTITY_NMSPC
{
	class RLEnvironment : public RLEnvironmentBase
	{
	public:
		RLEnvironment() : RLEnvironmentBase(){};
		virtual void GetState() override;
		virtual RLStateBase* GetStoredCurrState() override;
		virtual RLStateBase* GetStoredNextState() override;
		virtual void GetReward() override;
		virtual RLRewardBase* GetStoredReward() override;
		virtual void PerformAction(RLActionBase*) override;
	};
}

#endif