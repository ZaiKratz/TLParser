#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/Chats.h"

//begin namespace block
namespace MESSAGES
{
class GetChats : public TLBaseObject
{
public:
	GetChats();
	GetChats(TArray<int32> id);

	~GetChats();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<int32> id;
	MESSAGES::Chats* result;
};
} //end namespace block
