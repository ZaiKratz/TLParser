#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class ToggleChatAdmins : public TLBaseObject
{
public:
	ToggleChatAdmins();
	ToggleChatAdmins(int32 chat_id, bool enabled);

	~ToggleChatAdmins();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 chat_id;
	 bool enabled;
	COMMON::Updates* result;
};
} //end namespace block