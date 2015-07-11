#ifndef RLLEARNINGBASE_H
#define RLLEARNINGBASE_H

#include "RLStateActionBase.h"
#include "RLRewardBase.h"
#include "RLTableBase.h"

namespace RLENTITY_NMSPC
{
	class RLLearningBase
	{
	public:
		RLLearningBase(RLTableBase* tbl) : table(tbl){};
		virtual void Update(RLStateActionBase*, RLStateBase*, RLRewardBase*) = 0;
	protected:
		RLTableBase* table;
	};
}

#endif