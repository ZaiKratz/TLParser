#pragma once
#include "Engine.h"
#include "../../../Types/Private/ChannelAdminLogEventAction.h"

#include "../../../Types/Private/ChannelAdminLogEventAction.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminLogEventActionChangeAbout : public PRIVATE::ChannelAdminLogEventAction
{
public:
	ChannelAdminLogEventActionChangeAbout();
	ChannelAdminLogEventActionChangeAbout(FString prev_value, FString new_value);

	~ChannelAdminLogEventActionChangeAbout();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString GetPrevValue() const
	{
		 return this->prev_value;
	}

	FString GetNewValue() const
	{
		 return this->new_value;
	}

private:
	FString prev_value;
	 FString new_value;
};
} //end namespace block
