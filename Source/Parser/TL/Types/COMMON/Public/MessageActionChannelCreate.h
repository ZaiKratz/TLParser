#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageAction.h"

#include "../../../Types/Private/MessageAction.h"

//begin namespace block
namespace COMMON
{
class MessageActionChannelCreate : public PRIVATE::MessageAction
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
