#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"

//begin namespace block
namespace MESSAGES
{
class EditChatAdmin : public TLBaseObject
{
public:
	EditChatAdmin();
	EditChatAdmin(int32 chat_id, COMMON::InputUser* user_id, bool is_admin);

	~EditChatAdmin();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 chat_id;
	 COMMON::InputUser* user_id;
	 bool is_admin;
	bool result;
};
} //end namespace block
