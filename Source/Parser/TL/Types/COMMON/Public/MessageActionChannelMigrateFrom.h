#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class MessageActionChannelMigrateFrom : public TLBaseObject
{
public:
	MessageActionChannelMigrateFrom();
	MessageActionChannelMigrateFrom(FString title, int32 chat_id);

	~MessageActionChannelMigrateFrom();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Gettitle() const
	{
		 return this->title;
	}

	int32 GetChatId() const
	{
		 return this->chat_id;
	}

private:
	FString title;
	 int32 chat_id;
};
} //end namespace block
