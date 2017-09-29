#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Common/Public/DataJSON.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateBotWebhookJSON : public PRIVATE::Update
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
