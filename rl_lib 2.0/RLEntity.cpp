#include "RLEntity.h"
#include <iostream>

using namespace RLENTITY_NMSPC;

void RLEntity::ObsrvCurrState()
{
	std::cout << "Observing the current state" << std::endl;
	rlEnv->GetState();
}

void RLEntity::SelAction()
{
	std::cout << "Selecting the action" << std::endl;
	rlAgent->SelAction(rlEnv ->GetStoredCurrState());
}

void RLEntity::PerfAction()
{
	std::cout << "Performing the action" << std::endl;
	rlEnv->PerformAction(rlAgent->GetStoredAction());
}

void RLEntity::ObsrvNextState()
{
	std::cout << "Observing the next state" << std::endl;
	rlEnv->GetState();
}

void RLEntity::GetReward()
{
	std::cout << "Getting the reward" << std::endl;
	rlEnv->GetReward();
}

void RLEntity::AdjQ()
{
	std::cout << "Adjusting Q value" << std::endl;
	rlAgent->AdjQ(rlEnv->GetStoredCurrState(), rlEnv->GetStoredNextState(), rlEnv->GetStoredReward());
}