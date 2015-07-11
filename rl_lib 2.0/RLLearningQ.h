#ifndef RLLEARNING_H
#define RLLEARNING_H

#include "RLLearningBase.h"

namespace RLENTITY_NMSPC
{
	class RLLearningQ : public RLLearningBase
	{
	public:
		RLLearningQ(RLTableBase* tbl) : RLLearningBase(tbl){};
		virtual void Update(RLStateActionBase*, RLStateBase*, RLRewardBase*) override;
	};
}

#endif