#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminLogEventActionToggleSignatures : public TLBaseObject
{
public:
	ChannelAdminLogEventActionToggleSignatures();
	ChannelAdminLogEventActionToggleSignatures(bool new_value);

	~ChannelAdminLogEventActionToggleSignatures();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetNewValue() const
	{
		 return this->new_value;
	}

private:
	bool new_value;
};
} //end namespace block
