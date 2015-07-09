#ifndef RLLEARNINGBASE_H
#define RLLEARNINGBASE_H

#include "RLStateBase.h"
#include "RLRewardBase.h"

namespace RLENTITY_NMSPC
{
	class RLLearningBase
	{
		virtual void Update(RLStateBase*, RLStateBase*, RLRewardBase*) = 0;
	};
}

#endif