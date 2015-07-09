#ifndef RLREWARDBASE_H
#define RLREWARDBASE_H

#include "RLStateBase.h"

namespace RLENTITY_NMSPC
{
	class RLRewardBase
	{
	public:
		RLRewardBase(int);
		virtual int GetReward();
		virtual void SetReward();
	private:
		int value;
	};
}

#endif