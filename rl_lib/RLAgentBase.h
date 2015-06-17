#pragma once
#ifndef RL_AGENT_BASE_H
#define RL_AGENT_BASE_H

#include "RLActionBase.h"

namespace RL {
	///RLAgentBase pure abstract class
	class RLAgentBase {
	public:
		// agent's job is to act, which means to choose the next action
		virtual RLActionBase* act() = 0;

	};
	
}

#endif