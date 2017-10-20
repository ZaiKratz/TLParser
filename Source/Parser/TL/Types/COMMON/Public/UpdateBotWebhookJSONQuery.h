#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/DataJSON.h"

//begin namespace block
namespace COMMON
{
class UpdateBotWebhookJSONQuery : public TLBaseObject
{
public:
	UpdateBotWebhookJSONQuery();
	UpdateBotWebhookJSONQuery(unsigned long long query_id, COMMON::DataJSON* data, int32 timeout);

	~UpdateBotWebhookJSONQuery();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetQueryId() const
	{
		 return this->query_id;
	}

	COMMON::DataJSON*  Getdata() const
	{
		 return this->data;
	}

	int32 Gettimeout() const
	{
		 return this->timeout;
	}

private:
	unsigned long long query_id;
	 COMMON::DataJSON* data;
	 int32 timeout;
};
} //end namespace block
