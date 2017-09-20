#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Common/Public/DataJSON.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateBotWebhookJSONQuery : public PRIVATE::Update
{
public:
	UpdateBotWebhookJSONQuery();
	UpdateBotWebhookJSONQuery(unsigned long long query_id, COMMON::DataJSON* data, int32 timeout);

	~UpdateBotWebhookJSONQuery();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long query_id;
	 COMMON::DataJSON* data;
	 int32 timeout;
};
} //end namespace block
