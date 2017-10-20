#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class MessageActionChatDeleteUser : public TLBaseObject
{
public:
	MessageActionChatDeleteUser();
	MessageActionChatDeleteUser(int32 user_id);

	~MessageActionChatDeleteUser();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetUserId() const
	{
		 return this->user_id;
	}

private:
	int32 user_id;
};
} //end namespace block
