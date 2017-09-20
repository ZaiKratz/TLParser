#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChannelAdminLogEvent.h"
#include "../../../Types/Common/Public/Chat.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace CHANNELS
{
class AdminLogResults : public TLBaseObject
{
public:
	AdminLogResults();
	AdminLogResults(TArray<COMMON::ChannelAdminLogEvent*> events, TArray<COMMON::Chat*> chats, TArray<COMMON::User*> users);

	~AdminLogResults();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<COMMON::ChannelAdminLogEvent*> events;
	 TArray<COMMON::Chat*> chats;
	 TArray<COMMON::User*> users;
};
} //end namespace block
