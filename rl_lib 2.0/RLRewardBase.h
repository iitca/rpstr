#ifndef RLREWARDBASE_H
#define RLREWARDBASE_H

#include "RLStateBase.h"

namespace RLENTITY_NMSPC
{
	class RLRewardBase
	{
	public:
		RLRewardBase(double val) : value(val){};
		virtual double GetValue() = 0;
	protected:
		double value;
	};
}

#endif