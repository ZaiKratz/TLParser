#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/Chats.h"

//begin namespace block
namespace MESSAGES
{
class GetAllChats : public TLBaseObject
{
public:
	GetAllChats();
	GetAllChats(TArray<int32> except_ids);

	~GetAllChats();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<int32> except_ids;
	MESSAGES::Chats* result;
};
} //end namespace block
