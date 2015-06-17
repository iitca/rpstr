#pragma once
#ifndef RL_ACTION_BASE_H
#define RL_ACTION_BASE_H

#include "RLActionBase.h"

namespace RL {
	///RLActionBase pure abstract class
	class RLActionBase{

	public:
		virtual bool operator== (const RLActionBase&) = 0;
	};
}
#endif