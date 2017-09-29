#pragma once
#include "Engine.h"
#include "../../../Types/Private/ExportedChatInvite.h"

#include "../../../Types/Private/ExportedChatInvite.h"

//begin namespace block
namespace COMMON
{
class ChatInviteExported : public PRIVATE::ExportedChatInvite
{
public:
	ChatInviteExported();
	ChatInviteExported(FString link);

	~ChatInviteExported();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getlink() const
	{
		 return this->link;
	}

private:
	FString link;
};
} //end namespace block
