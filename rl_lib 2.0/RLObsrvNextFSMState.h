#ifndef RLOBSRVNEXTFSMSTATE_H
#define RLOBSRVNEXTFSMSTATE_H

#include "RLFSMState.h"

namespace RLFSM_NMSPC
{
	/*in this state the next rlstate is observed */
	class RLObsrvNextFSMState : public RLFSMState
	{
	public:
		RLObsrvNextFSMState(RLFSMStatesEnum);
		/*in this state the next rl_state is fetched from the environment
		and stored in the rl_agent*/

		virtual void Do(RLFSM*) override;
	};
}
#endif