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
		this->validate();
	};
	Angle(const T& value = 0)
	{
		this->rValue_ = value;
		this->dValue_ = value * 180 / jck::PI;
		this->validate();
	};
	Angle(const Angle& value)
	{
		this->rValue_ = value.radians();
		this->dValue_ = value.degrees();
		this->validate();
	}
	~Angle(void)
	{
	};
	T radians() const { return this->rValue_; };
	T degrees() const { return this->dValue_; };
	operator const T& () const { return this->rValue_; };
	Angle<T>& operator =(const Angle<T>& lhs)
	{
		this->rValue_ = lhs.radians();
		this->dValue_ = lhs.degrees();
		this->validate();
		return *this;
	}
	Angle<T>& operator =(const T& lhs)
	{
		this->rValue_ = lhs;
		this->dValue_ = lhs * 180 / jck::PI;
		this->validate();
		return *this;
	}

	Angle<T>& operator +=(const T& lhs)
	{
		this->rValue_ = lhs + this->rValue_;
		this->dValue_ = this->rValue_ * 180 / jck::PI;
		this->validate();
		return *this;
	}
	Angle<T>& operator -=(const T& lhs)
	{
		this->rValue_ = -lhs + this->rValue_;
		this->dValue_ = this->rValue_ * 180 / jck::PI;
		this->validate();
		return *this;
	}
	Angle<T>& operator +=(const Angle& lhs)
	{
		this->rValue_ = lhs.radians() + this->rValue_;
		this->dValue_ = this->rValue_ * 180 / jck::PI;
		this->validate();
		return *this;
	}
	Angle<T>& operator -=(const Angle& lhs)
	{
		this->rValue_ = -lhs.radians() + this->rValue_;
		this->dValue_ = this->rValue_ * 180 / jck::PI;
		this->validate();
		return *this;
	}

private:
	T rValue_;
	T dValue_;
	void validate()
	{
		if(this->rValue_ > jck::PI)
		{
			this->rValue_ = -(jck::PI * 2 - this->rValue_);
		} else if(this->rValue_ < -jck::PI)
		{
			this->rValue_ = jck::PI * 2 + this->rValue_;
		}
		this->dValue_ = this->rValue_ * 180 / jck::PI; 
	}
};