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
private:
	double time;
	 FString type;
	 unsigned long long peer;
	 FString data;
};
} //end namespace block
