#ifndef RLFSMSTATE_H
#define RLFSMSTATE_H

#include "RLFSMStatesEnum.h"
#include "RLResources.h"
#include <iostream>


namespace RLFSM_NMSPC
{
	/*forward declaration*/
	class RLFSM;
	/*the base fsm_state class */
	class RLFSMState
	{
	protected:
		RLFSMStatesEnum thisStateName;
		
	public:
		//the state's activity
		virtual void Do(RLFSM*) = 0;
		//transition to the next state
		void Transit(RLFSM*);
		//print the name of the state
		void Print();
	};
}

#endif