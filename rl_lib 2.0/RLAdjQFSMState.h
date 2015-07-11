#ifndef RLADJQFSMSTATE_H
#define RLADJQFSMSTATE_H

#include "RLFSMState.h"

namespace RLFSM_NMSPC
{
	/*in this state Q is recalculated */
	class RLAdjQFSMState : public RLFSMState
	{
	public:
		RLAdjQFSMState(RLFSMStatesEnum);
		/*in this state the Q is recalculated based on old Q, reward, previous and current state as well as
		an action*/
		virtual void Do(RLFSM*) override;
	};
}

#endif