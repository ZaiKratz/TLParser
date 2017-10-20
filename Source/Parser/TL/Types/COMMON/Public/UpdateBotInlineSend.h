#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/GeoPoint.h"
#include "../../../Types/Common/Public/InputBotInlineMessageID.h"

//begin namespace block
namespace COMMON
{
class UpdateBotInlineSend : public TLBaseObject
{
public:
	UpdateBotInlineSend();
	UpdateBotInlineSend(int32 user_id, FString query, COMMON::GeoPoint* geo, FString id, COMMON::InputBotInlineMessageID* msg_id);

	~UpdateBotInlineSend();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetUserId() const
	{
		 return this->user_id;
	}

	FString Getquery() const
	{
		 return this->query;
	}

	COMMON::GeoPoint*  Getgeo() const
	{
		 return this->geo;
	}

	FString Getid() const
	{
		 return this->id;
	}

	COMMON::InputBotInlineMessageID*  GetMsgId() const
	{
		 return this->msg_id;
	}

private:
	int32 user_id;
	 FString query;
	 COMMON::GeoPoint* geo;
	 FString id;
	 COMMON::InputBotInlineMessageID* msg_id;
};
} //end namespace block
