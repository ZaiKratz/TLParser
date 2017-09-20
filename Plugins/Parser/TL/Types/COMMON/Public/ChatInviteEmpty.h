#pragma once
#include "Engine.h"
#include "../../../Types/Private/ExportedChatInvite.h"

#include "../../../Types/Private/ExportedChatInvite.h"

//begin namespace block
namespace COMMON
{
class ChatInviteEmpty : public PRIVATE::ExportedChatInvite
{
public:
	ChatInviteEmpty();
	~ChatInviteEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
