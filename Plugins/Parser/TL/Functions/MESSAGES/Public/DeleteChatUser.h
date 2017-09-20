#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class DeleteChatUser : public TLBaseObject
{
public:
	DeleteChatUser();
	DeleteChatUser(int32 chat_id, COMMON::InputUser* user_id);

	~DeleteChatUser();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 chat_id;
	 COMMON::InputUser* user_id;
	COMMON::Updates* result;
};
} //end namespace block
