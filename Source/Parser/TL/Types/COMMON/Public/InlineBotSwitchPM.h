#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InlineBotSwitchPM : public TLBaseObject
{
public:
	InlineBotSwitchPM();
	InlineBotSwitchPM(FString text, FString start_param);

	~InlineBotSwitchPM();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Gettext() const
	{
		 return this->text;
	}

	FString GetStartParam() const
	{
		 return this->start_param;
	}

private:
	FString text;
	 FString start_param;
};
} //end namespace block
