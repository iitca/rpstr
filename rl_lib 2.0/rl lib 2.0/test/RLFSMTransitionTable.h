#ifndef RLFSMTRANSITIONTABLE_H
#define RLFSMTRANSITIONTABLE_H

#include "RLFSMFactory.h"
#include <vector>

namespace RLFSM_NMSPC
{
	/*this class represents a transition sequence*/
	class RLFSMTransitionTable
	{
	public:
		RLFSMTransitionTable();
		RLFSMStatesEnum GetNextFSMState(RLFSMStatesEnum);
	private:
		std::vector<RLFSMStatesEnum> trans;
	};
}

#endif