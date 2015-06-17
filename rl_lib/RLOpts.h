#pragma once
#ifndef RL_OPTS_H
#define RL_OPTS_H

#include <vector>

class RLOpts{
	//singleton class
public:
	static RLOpts& getInstance(){
		static RLOpts rLOpts;
		return rLOpts;
	}
	unsigned int actionsNum;
	unsigned int featuresNum;
	std::vector<double> ranges;
	std::vector<unsigned int> numOfChunks;

private:
	RLOpts(){}
	RLOpts(RLOpts const&);
	void operator=(RLOpts const&);
};

#endif