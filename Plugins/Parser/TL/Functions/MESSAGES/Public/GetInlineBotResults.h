#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Common/Public/InputGeoPoint.h"
#include "../../../Types/Messages/Public/BotResults.h"

//begin namespace block
namespace MESSAGES
{
class GetInlineBotResults : public TLBaseObject
{
public:
	GetInlineBotResults();
	GetInlineBotResults(COMMON::InputUser* bot, PRIVATE::InputPeer* peer, COMMON::InputGeoPoint* geo_point, FString query, FString offset);

	~GetInlineBotResults();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputUser* bot;
	 PRIVATE::InputPeer* peer;
	 COMMON::InputGeoPoint* geo_point;
	 FString query;
	 FString offset;
	MESSAGES::BotResults* result;
};
} //end namespace block
