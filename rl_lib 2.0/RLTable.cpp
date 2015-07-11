#include "RLTable.h"

using namespace RLENTITY_NMSPC;

double RLTable::Get(RLStateActionBase* stateAction)
{
	//check if the element exists
	if (this->table.count(stateAction))
		return this->table[stateAction];
	return 0.0;
}

void RLTable::Set(RLStateActionBase* stateAction, double q)
{
	//check if the element exists
	if (this->table.count(stateAction))
		this->table[stateAction] = q;
	else
		this->table.insert(std::make_pair(stateAction, q));
}

double RLTable::GetMax(RLStateBase* state)
{
	double Qmax = 0.0;
	bool init = false;
	if (this->table.empty()) return Qmax;
	//get the iterator
	std::map<RLStateActionBase*, double>::iterator it = this->table.begin();
	//iterate through all table's entries
	for (; it != table.end(); it++){
		if (it->first->GetState() == state){
			if (!init){
				//initialize Qmax with the first value
				init = true;
				Qmax = this->Get(it->first);
			}
			else{
				//choose the max Q
				if (this->Get(it->first) > Qmax)
					Qmax = this->Get(it->first);
			}
		}
	}
	return Qmax;
}