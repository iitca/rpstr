#ifndef RLPERFACTIONFSMSTATE_H
#define RLPERFACTIONFSMSTATE_H

#include "RLFSMState.h"

namespace RLFSM_NMSPC
{
	/*in this state the chosen action is performed */
	class RLPerfActionFSMState : public RLFSMState
	{
	public:
		RLPerfActionFSMState(RLFSMStatesEnum);
		/*in this state the chosen action is performed */

		virtual void Do(RLFSM*) override;
	};
}

#endif