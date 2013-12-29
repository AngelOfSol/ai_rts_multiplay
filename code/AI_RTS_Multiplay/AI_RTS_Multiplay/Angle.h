#pragma once
#include "pi.h"

enum ANGLE_MODE
{
	RADIAN,
	DEGREE
};

template <class T>
class Angle
{
public:
	Angle(ANGLE_MODE mode, T value)
	{
		if(mode == RADIAN)
		{
			this->rValue_ = value;
			this->dValue_ = value * 180 / jck::PI; 
		} else
		{
			this->rValue_ = value * jck::PI / 180 ; 
			this->dValue_ = value; 
		}
	};
	Angle(const T& value)
	{
		this->rValue_ = value;
		this->dValue_ = value * 180 / jck::PI;
	};
	Angle(const Angle& value)
	{
		this->rValue_ = value.radians();
		this->dValue_ = value.degrees();
	}
	~Angle(void)
	{
	};
	T radians() const { return this->rValue_; };
	T degrees() const { return this->dValue_; };
	operator T& () { return this->rValue_; };
private:
	T rValue_;
	T dValue_;
};