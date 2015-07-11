#ifndef RLTABLEBASE_H
#define RLTABLEBASE_H

#include "RLStateActionBase.h"
#include <map>

namespace RLENTITY_NMSPC
{
	class RLTableBase
	{
	public:
		virtual double Get(RLStateActionBase*) = 0;
		virtual void Set(RLStateActionBase*, double) = 0;
		virtual double GetMax(RLStateBase*) = 0;
	protected:
		std::map<RLStateActionBase*, double> table;
	};
}

#endif