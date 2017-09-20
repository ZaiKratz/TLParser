#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Messages/Public/Chats.h"

//begin namespace block
namespace MESSAGES
{
class GetCommonChats : public TLBaseObject
{
public:
	GetCommonChats();
	GetCommonChats(COMMON::InputUser* user_id, int32 max_id, int32 limit);

	~GetCommonChats();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputUser* user_id;
	 int32 max_id;
	 int32 limit;
	MESSAGES::Chats* result;
};
} //end namespace block
