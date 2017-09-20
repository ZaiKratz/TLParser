#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateDeleteChannelMessages : public PRIVATE::Update
{
public:
	UpdateDeleteChannelMessages();
	UpdateDeleteChannelMessages(int32 channel_id, TArray<int32> messages, int32 pts, int32 pts_count);

	~UpdateDeleteChannelMessages();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 channel_id;
	 TArray<int32> messages;
	 int32 pts;
	 int32 pts_count;
};
} //end namespace block
