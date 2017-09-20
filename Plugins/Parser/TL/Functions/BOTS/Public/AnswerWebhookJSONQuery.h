#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/DataJSON.h"

//begin namespace block
namespace BOTS
{
class AnswerWebhookJSONQuery : public TLBaseObject
{
public:
	AnswerWebhookJSONQuery();
	AnswerWebhookJSONQuery(unsigned long long query_id, COMMON::DataJSON* data);

	~AnswerWebhookJSONQuery();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long query_id;
	 COMMON::DataJSON* data;
	bool result;
};
} //end namespace block
