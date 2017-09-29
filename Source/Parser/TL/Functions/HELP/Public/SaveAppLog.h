#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputAppEvent.h"

//begin namespace block
namespace HELP
{
class SaveAppLog : public TLBaseObject
{
public:
	SaveAppLog();
	SaveAppLog(TArray<COMMON::InputAppEvent*> events);

	~SaveAppLog();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<COMMON::InputAppEvent*>  Getevents() const
	{
		 return this->events;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	TArray<COMMON::InputAppEvent*> events;
	bool result;
};
} //end namespace block
