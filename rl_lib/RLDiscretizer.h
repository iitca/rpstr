#pragma once
#ifndef RL_DISCRETIZER_H
#define RL_DISCRETIZER_H

#include <vector>

class RLDiscretizer{
public:
	virtual void setNumberOfChunks(const std::vector<unsigned int>) = 0;
	virtual void setRanges(const std::vector<double>) = 0;
};

#endif