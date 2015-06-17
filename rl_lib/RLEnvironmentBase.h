#pragma once
#ifndef RL_ENVIRONMENT_BASE_H
#define RL_ENVIRONMENT_BASE_H

#include "RLActionBase.h"

namespace RL {
	///RLExperimentBase pure abstract class
	class RLEnvironmentBase {

	private:

		/*function is called by the outer code to return the action*/
		virtual RLActionBase* getAction() = 0;
		
	};
}

#endif