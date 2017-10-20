#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputMessagesFilterPhoneCalls : public TLBaseObject
{
public:
	InputMessagesFilterPhoneCalls();
	InputMessagesFilterPhoneCalls(bool missed);

	~InputMessagesFilterPhoneCalls();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getmissed() const
	{
		 return this->missed;
	}

private:
	bool missed;
};
} //end namespace block
