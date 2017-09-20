#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateChatAdmins : public PRIVATE::Update
{
public:
	UpdateChatAdmins();
	UpdateChatAdmins(int32 chat_id, bool enabled, int32 version);

	~UpdateChatAdmins();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 chat_id;
	 bool enabled;
	 int32 version;
};
} //end namespace block
