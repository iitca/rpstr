#pragma once
#ifndef RL_LEARNING_BASE_H
#define RL_LEARNING_BASE_H

#include <vector>

namespace RL {
	///RLLearningBase pure virtual class
	class RLLearningBase{
	public:
		/* updates the q value
		*/
		virtual void update() = 0;
	};
}
#endif