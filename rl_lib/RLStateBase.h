#pragma once
#ifndef RL_STATE_BASE_H
#define RL_STATE_BASE_H

namespace RL {
	///RLStateBase pure abstract class
	class RLStateBase{

	public:
		virtual bool operator==(const RLStateBase&) = 0;
	};
}

#endif