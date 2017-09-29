#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Chat.h"
#include "../../../Types/Messages/Public/Chats.h"

//begin namespace block
namespace MESSAGES
{
class ChatsSlice : public TLBaseObject
{
public:
	ChatsSlice();
	ChatsSlice(int32 count, TArray<COMMON::Chat*> chats);

	~ChatsSlice();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getcount() const
	{
		 return this->count;
	}

	TArray<COMMON::Chat*>  Getchats() const
	{
		 return this->chats;
	}

private:
	int32 count;
	 TArray<COMMON::Chat*> chats;
};
} //end namespace block