#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Common/Public/PostAddress.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateBotShippingQuery : public PRIVATE::Update
{
public:
	UpdateBotShippingQuery();
	UpdateBotShippingQuery(unsigned long long query_id, int32 user_id, TArray<uint8> payload, COMMON::PostAddress* shipping_address);

	~UpdateBotShippingQuery();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long query_id;
	 int32 user_id;
	 TArray<uint8> payload;
	 COMMON::PostAddress* shipping_address;
};
} //end namespace block
