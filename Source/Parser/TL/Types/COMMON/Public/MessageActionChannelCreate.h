#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class MessageActionChannelCreate : public TLBaseObject
{
public:
	MessageActionChannelCreate();
	MessageActionChannelCreate(FString title);

	~MessageActionChannelCreate();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Gettitle() const
	{
		 return this->title;
	}

private:
	FString title;
};
} //end namespace block
