#pragma once
#ifndef RL_CONVERTER_H
#define RL_CONVERTER_H

template<typename Ty1, 
	typename Ty2>
class RLConverter{
public:
	virtual Ty1 convert(Ty2) = 0;
};

#endif