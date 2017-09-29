#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Chat.h"

//begin namespace block
namespace MESSAGES
{
class Chats : public TLBaseObject
{
public:
	Chats();
	Chats(TArray<COMMON::Chat*> chats);

	~Chats();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<COMMON::Chat*>  Getchats() const
	{
		 return this->chats;
	}

private:
	TArray<COMMON::Chat*> chats;
};
} //end namespace block
