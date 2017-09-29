#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/ChatFull.h"

//begin namespace block
namespace MESSAGES
{
class GetFullChat : public TLBaseObject
{
public:
	GetFullChat();
	GetFullChat(int32 chat_id);

	~GetFullChat();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChatId() const
	{
		 return this->chat_id;
	}

	MESSAGES::ChatFull* GetResult() const
	{
		 return this->result;
	}

private:
	int32 chat_id;
	MESSAGES::ChatFull* result;
};
} //end namespace block
