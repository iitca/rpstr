#ifndef RLTABLE_H
#define RLTABLE_H

#include "RLTableBase.h"

namespace RLENTITY_NMSPC
{
	class RLTable : public RLTableBase
	{
	public:
		virtual double Get(RLStateActionBase*) override;
		virtual void Set(RLStateActionBase*, double) override;
		virtual double GetMax(RLStateBase*) override;
	};
}

#endif