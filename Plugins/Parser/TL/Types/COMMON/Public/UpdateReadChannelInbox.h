#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateReadChannelInbox : public PRIVATE::Update
{
public:
	UpdateReadChannelInbox();
	UpdateReadChannelInbox(int32 channel_id, int32 max_id);

	~UpdateReadChannelInbox();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 channel_id;
	 int32 max_id;
};
} //end namespace block
