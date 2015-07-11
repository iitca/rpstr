#ifndef RLSYSTEM_H
#define RLSYSTEM_H

#include "RLFSM.h"
#include "RLEntity.h"

namespace RLSYSTEM_NMSPC
{
	class RLSystem
	{
	public:
		RLSystem(RLFSM_NMSPC::RLFSM*, RLENTITY_NMSPC::RLEntity*);
		void Do(void);
	private:

		RLFSM_NMSPC::RLFSM* rlFSM;
		RLENTITY_NMSPC::RLEntity* rlEntity;

	};
}

#endif