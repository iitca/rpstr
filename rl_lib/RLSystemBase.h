#pragma once
#ifndef RL_SYSTEM_BASE_H
#define RL_SYSTEM_BASE_H

namespace RL {
	///RLEnvironmentBase pure abstract class
	class RLSystemBase {

	public:

		/*do the next iteration
		*/
		virtual void doNextIteration() = 0;
	};

}
#endif