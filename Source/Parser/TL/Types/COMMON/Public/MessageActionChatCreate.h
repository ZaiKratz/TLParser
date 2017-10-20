#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class MessageActionChatCreate : public TLBaseObject
{
public:
	MessageActionChatCreate();
	MessageActionChatCreate(FString title, TArray<int32> users);

	~MessageActionChatCreate();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Gettitle() const
	{
		 return this->title;
	}

	TArray<int32>  Getusers() const
	{
		 return this->users;
	}

private:
	FString title;
	 TArray<int32> users;
};
} //end namespace block
