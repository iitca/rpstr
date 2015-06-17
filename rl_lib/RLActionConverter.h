#pragma once
#ifndef RL_ACTION_CONVERTER_H
#define RL_ACTION_CONVERTER_H

#include "RLConverter.h"
#include "RLAction.h"
#include <math.h>
#include <stdlib.h>
#include <vector>

#define PI 3.14159265

//direction to move in from node to node if the node is occupied


template<typename Ty1>
class RLActionConverter{
public:
	//constructor
	RLActionConverter();
	//converts an action to a node
	void convert(RLAction<Ty1>);
	//takes into accout the extra information
	void consider(std::vector<double>);
	//get result
	std::vector<double> getRes();
private:
	std::vector<double> consData;
	//output
	std::vector<double> res;

};

template<typename Ty1>
RLActionConverter<Ty1>::RLActionConverter(){
}

template<typename Ty1>
void RLActionConverter<Ty1>::convert(RLAction<Ty1> action){
	//we need to return the center of one of 4 cells
	this ->res.clear();
	if(action.getParams()[0] == 0){
		this ->res.push_back(this ->consData[2]/4);
		this ->res.push_back(this ->consData[3]/4);
	}else if(action.getParams()[0] == 1){
		this ->res.push_back(this ->consData[2]/4);
		this ->res.push_back(this ->consData[3]*3/4);
	}else if(action.getParams()[0] == 2){
		this ->res.push_back(this ->consData[2]*3/4);
		this ->res.push_back(this ->consData[3]*3/4);
	}else if(action.getParams()[0] == 3){
		this ->res.push_back(this ->consData[2]*3/4);
		this ->res.push_back(this ->consData[3]/4);
	}
}

template<typename Ty1>
std::vector<double> RLActionConverter<Ty1>::getRes(){
	return this ->res;
}

template<typename Ty1>
void RLActionConverter<Ty1>::consider(std::vector<double> data){
	this ->consData = data;
}


#endif