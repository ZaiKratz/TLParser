#pragma once
#include "Engine.h"
#include "../../../Types/Private/ExportedChatInvite.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Private/ExportedChatInvite.h"

//begin namespace block
namespace CHANNELS
{
class ExportInvite : public PRIVATE::ExportedChatInvite
{
public:
	ExportInvite();
	ExportInvite(COMMON::InputChannel* channel);

	~ExportInvite();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputChannel* channel;
	PRIVATE::ExportedChatInvite* result;
};
} //end namespace block
