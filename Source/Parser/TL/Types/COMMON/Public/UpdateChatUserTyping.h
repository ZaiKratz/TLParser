#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateChatUserTyping : public TLBaseObject
{
public:
	UpdateChatUserTyping();
	UpdateChatUserTyping(int32 chat_id, int32 user_id, TLBaseObject* action);

	~UpdateChatUserTyping();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChatId() const
	{
		 return this->chat_id;
	}

	int32 GetUserId() const
	{
		 return this->user_id;
	}

	TLBaseObject*  Getaction() const
	{
		 return this->action;
	}

private:
	int32 chat_id;
	 int32 user_id;
	 TLBaseObject* action;
};
} //end namespace block
