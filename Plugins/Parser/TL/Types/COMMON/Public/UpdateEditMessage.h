#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Common/Public/Message.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateEditMessage : public PRIVATE::Update
{
public:
	UpdateEditMessage();
	UpdateEditMessage(COMMON::Message* message, int32 pts, int32 pts_count);

	~UpdateEditMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::Message* message;
	 int32 pts;
	 int32 pts_count;
};
} //end namespace block
