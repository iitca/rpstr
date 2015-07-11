#ifndef RLOBSRVCURRENTFSMSTATE_H
#define RLOBSRVCURRENTFSMSTATE_H

#include "RLFSMState.h"

namespace RLFSM_NMSPC
{
	/*in this state the current rlstate is observed */
	class RLObsrvCurrentFSMState : public RLFSMState
	{
	public:
		RLObsrvCurrentFSMState(RLFSMStatesEnum);
		/*in this state the current rl_state is fetched from the environment
		and stored in the rl_agent*/

		virtual void Do(RLFSM*) override;
	};
}

#endif