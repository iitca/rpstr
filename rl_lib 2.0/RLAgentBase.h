#ifndef RLAGENTBASE_H
#define RLAGENTBASE_H

#include "RLStateBase.h"
#include "RLLearningBase.h"
#include "RLActionBase.h"

namespace RLENTITY_NMSPC
{
	class RLAgentBase
	{
	public:
		RLAgentBase(RLLearningBase* learning) : rlLearning(learning), rlAction(nullptr){};
		virtual void SelAction(RLStateBase*) = 0;
		virtual RLActionBase* GetStoredAction() = 0;
		virtual void AdjQ(RLStateBase*, RLStateBase*, RLRewardBase*) = 0;
	protected:
		RLLearningBase* rlLearning;
		RLActionBase* rlAction;
	};
}

#endif 