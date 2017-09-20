#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateChannelReadMessagesContents : public PRIVATE::Update
{
public:
	UpdateChannelReadMessagesContents();
	UpdateChannelReadMessagesContents(int32 channel_id, TArray<int32> messages);

	~UpdateChannelReadMessagesContents();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 channel_id;
	 TArray<int32> messages;
};
} //end namespace block
