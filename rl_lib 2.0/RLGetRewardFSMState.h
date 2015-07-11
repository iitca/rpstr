#ifndef RLGETREWARDFSMSTATE_H
#define RLGETREWARDFSMSTATE_H

#include "RLFSMState.h"

namespace RLFSM_NMSPC
{
	/*in this state the reward is obtained for the environment */
	class RLGetRewardFSMState : public RLFSMState
	{
	public:
		RLGetRewardFSMState(RLFSMStatesEnum);
		/*in this state the rewarde is fetched from the environment
		to recalculate Q*/

		virtual void Do(RLFSM*) override;
	};
}

#endif