#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class AddChatUser : public TLBaseObject
{
public:
	AddChatUser();
	AddChatUser(int32 chat_id, COMMON::InputUser* user_id, int32 fwd_limit);

	~AddChatUser();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 chat_id;
	 COMMON::InputUser* user_id;
	 int32 fwd_limit;
	COMMON::Updates* result;
};
} //end namespace block
