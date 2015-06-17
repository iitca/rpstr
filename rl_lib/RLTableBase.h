#pragma once
#ifndef RL_QTABLE_BASE_H
#define RL_QTABLE_BASE_H

#include <vector>


namespace RL {
	///RLQTableBase pure abstract class
	template <typename T> 
	class RLTableBase {
	public:
		/* puts value into the table
		*/
		virtual void put(std::vector<T>) = 0;

		/*gets value from the table
		*/
		virtual std::vector<T> get() = 0;
	};
}
#endif