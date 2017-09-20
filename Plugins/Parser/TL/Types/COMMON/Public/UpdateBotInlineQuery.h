#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Common/Public/GeoPoint.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateBotInlineQuery : public PRIVATE::Update
{
public:
	UpdateBotInlineQuery();
	UpdateBotInlineQuery(unsigned long long query_id, int32 user_id, FString query, COMMON::GeoPoint* geo, FString offset);

	~UpdateBotInlineQuery();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long query_id;
	 int32 user_id;
	 FString query;
	 COMMON::GeoPoint* geo;
	 FString offset;
};
} //end namespace block
