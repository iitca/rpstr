#ifndef RLSTATEBASE_H
#define RLSTATEBASE_H

namespace RLENTITY_NMSPC
{
	class RLStateBase
	{
	public:
		virtual bool operator==(RLStateBase&) const = 0;
	};
}

#endif