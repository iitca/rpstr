#ifndef RLFSMFACTORY_H
#define RLFSMFACTORY_H

#include "RLFSMStatesEnum.h"


namespace RLFSM_NMSPC
{
	class RLFSMState;
	class RLFSMFactory
	{
	public:
		static RLFSMState* CreateState(RLFSMStatesEnum);
	};
}

#endif