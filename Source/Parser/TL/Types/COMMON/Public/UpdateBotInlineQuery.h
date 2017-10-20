#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/GeoPoint.h"

//begin namespace block
namespace COMMON
{
class UpdateBotInlineQuery : public TLBaseObject
{
public:
	UpdateBotInlineQuery();
	UpdateBotInlineQuery(unsigned long long query_id, int32 user_id, FString query, COMMON::GeoPoint* geo, FString offset);

	~UpdateBotInlineQuery();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetQueryId() const
	{
		 return this->query_id;
	}

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

	FString Getoffset() const
	{
		 return this->offset;
	}

private:
	unsigned long long query_id;
	 int32 user_id;
	 FString query;
	 COMMON::GeoPoint* geo;
	 FString offset;
};
} //end namespace block
