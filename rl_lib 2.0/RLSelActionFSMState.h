#ifndef RLSELFACTIONFSMSTATE_H
#define RLSELFACTIONFSMSTATE_H

#include "RLFSMState.h"

namespace RLFSM_NMSPC
{
	/*in this state the action is selected */
	class RLSelActionFSMState : public RLFSMState
	{
	public:
		RLSelActionFSMState(RLFSMStatesEnum);
		/*in this state the action is selected */

		virtual void Do(RLFSM*) override;
	};
}

#endif