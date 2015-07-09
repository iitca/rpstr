#ifndef RLFSM_H
#define RLFSM_H

#include "RLFSMStateInput.h"
#include "RLFSMTransitionTable.h"
#include "RLEntityBase.h"


namespace RLFSM_NMSPC
{
	/*forward declaration*/
	class RLFSMState;
	/*fsm for rl*/
	class RLFSM
	{
	public:
		RLFSM(RLFSMTransitionTable*, RLENTITY_NMSPC::RLEntityBase*);
		void Update();
		void SetFSMState(RLFSMState*);
		RLFSMTransitionTable* GetTransitionTable();
		RLENTITY_NMSPC::RLEntityBase* GetRLEntity();
	private:
		RLFSMState* currentFSMState;
		RLFSMTransitionTable* rltt;
		RLENTITY_NMSPC::RLEntityBase* rlent;
	};
}

#endif