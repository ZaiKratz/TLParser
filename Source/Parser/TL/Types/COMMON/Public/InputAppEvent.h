#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputAppEvent : public TLBaseObject
{
public:
	InputAppEvent();
	InputAppEvent(double time, FString type, unsigned long long peer, FString data);

	~InputAppEvent();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	double Gettime() const
	{
		 return this->time;
	}

	FString Gettype() const
	{
		 return this->type;
	}

	unsigned long long Getpeer() const
	{
		 return this->peer;
	}

	FString Getdata() const
	{
		 return this->data;
	}

private:
	double time;
	 FString type;
	 unsigned long long peer;
	 FString data;
};
} //end namespace block
