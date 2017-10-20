#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Common/Public/InputGeoPoint.h"
#include "../../../Types/Messages/Public/BotResults.h"

//begin namespace block
namespace MESSAGES
{
class GetInlineBotResults : public TLBaseObject
{
public:
	GetInlineBotResults();
	GetInlineBotResults(COMMON::InputUser* bot, TLBaseObject* peer, COMMON::InputGeoPoint* geo_point, FString query, FString offset);

	~GetInlineBotResults();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputUser*  Getbot() const
	{
		 return this->bot;
	}

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

	COMMON::InputGeoPoint*  GetGeoPoint() const
	{
		 return this->geo_point;
	}

	FString Getquery() const
	{
		 return this->query;
	}

	FString Getoffset() const
	{
		 return this->offset;
	}

	MESSAGES::BotResults* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputUser* bot;
	 TLBaseObject* peer;
	 COMMON::InputGeoPoint* geo_point;
	 FString query;
	 FString offset;
	MESSAGES::BotResults* result;
};
} //end namespace block
