#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/Update.h"
#include "../../../Types/Common/Public/User.h"
#include "../../../Types/Common/Public/Chat.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace COMMON
{
class UpdatesCombined : public TLBaseObject
{
public:
	UpdatesCombined();
	UpdatesCombined(TArray<PRIVATE::Update*> updates, TArray<COMMON::User*> users, TArray<COMMON::Chat*> chats, FDateTime date, int32 seq_start, int32 seq);

	~UpdatesCombined();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<PRIVATE::Update*> updates;
	 TArray<COMMON::User*> users;
	 TArray<COMMON::Chat*> chats;
	 FDateTime date;
	 int32 seq_start;
	 int32 seq;
};
} //end namespace block
