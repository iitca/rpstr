#ifndef RLLEARNING_H
#define RLLEARNING_H

#include "RLLearningBase.h"

namespace RLENTITY_NMSPC
{
	class RLLearning : public RLLearningBase
	{
	public:
		virtual void Update(RLStateBase*, RLStateBase*, RLRewardBase*) override;
	};
}

#endif