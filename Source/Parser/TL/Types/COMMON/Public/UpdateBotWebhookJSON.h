#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/DataJSON.h"

//begin namespace block
namespace COMMON
{
class UpdateBotWebhookJSON : public TLBaseObject
{
public:
	UpdateBotWebhookJSON();
	UpdateBotWebhookJSON(COMMON::DataJSON* data);

	~UpdateBotWebhookJSON();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::DataJSON*  Getdata() const
	{
		 return this->data;
	}

private:
	COMMON::DataJSON* data;
};
} //end namespace block
