#ifndef RLENTITY_H
#define RLENTITY_H

#include "RLEntityBase.h"
#include "RLAgentBase.h"
#include "RLEnvironmentBase.h"

namespace RLENTITY_NMSPC
{
	class RLEntity : public RLEntityBase
	{
	public:
		RLEntity(RLAgentBase* agent, RLEnvironmentBase* env) : RLEntityBase(agent, env){};
		virtual void ObsrvCurrState() override;
		virtual void SelAction() override;
		virtual void PerfAction() override;
		virtual void ObsrvNextState() override;
		virtual void GetReward() override;
		virtual void AdjQ() override;
	};
}

#endif