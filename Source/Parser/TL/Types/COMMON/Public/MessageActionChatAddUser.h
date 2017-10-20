#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class MessageActionChatAddUser : public TLBaseObject
{
public:
	MessageActionChatAddUser();
	MessageActionChatAddUser(TArray<int32> users);

	~MessageActionChatAddUser();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<int32>  Getusers() const
	{
		 return this->users;
	}

private:
	TArray<int32> users;
};
} //end namespace block
