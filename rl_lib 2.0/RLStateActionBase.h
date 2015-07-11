#ifndef RLSTATEACTION_H
#define RLSTATEACTION_H

#include "RLStateBase.h"
#include "RLActionBase.h"

namespace RLENTITY_NMSPC
{
	class RLStateActionBase
	{
	public:
		virtual bool operator==(RLStateActionBase&) const = 0;
		virtual RLStateBase* GetState() = 0;
		virtual RLActionBase* GetAction() = 0;
	private:
		RLStateBase* state;
		RLActionBase* action;
	};
}

#endif