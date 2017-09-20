#pragma once
#include "Engine.h"
#include "../../../Types/Private/ExportedChatInvite.h"

#include "../../../Types/Private/ExportedChatInvite.h"

//begin namespace block
namespace MESSAGES
{
class ExportChatInvite : public PRIVATE::ExportedChatInvite
{
public:
	ExportChatInvite();
	ExportChatInvite(int32 chat_id);

	~ExportChatInvite();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 chat_id;
	PRIVATE::ExportedChatInvite* result;
};
} //end namespace block
