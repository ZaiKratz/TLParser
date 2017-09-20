#include "../Public/GetInlineBotResults.h"


//begin namespace block
namespace MESSAGES
{

GetInlineBotResults::GetInlineBotResults()
{
	this->_ConstructorID = -1650897327;
	this->_ContentRelated = true;
}

GetInlineBotResults::GetInlineBotResults(COMMON::InputUser* bot, PRIVATE::InputPeer* peer, COMMON::InputGeoPoint* geo_point, FString query, FString offset)
{
	this->_ConstructorID = -1650897327;
	this->_ContentRelated = true;
	this->bot = bot;
	this->peer = peer;
	this->geo_point = geo_point;
	this->query = query;
	this->offset = offset;
}
void GetInlineBotResults::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!geo_point)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->bot->OnSend(Writer);
	this->peer->OnSend(Writer);
	if(!this->geo_point)
	{
	this->geo_point->OnSend(Writer);
	}
	Writer.TGWriteString(this->query);
	Writer.TGWriteString(this->offset);
}


void GetInlineBotResults::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::BotResults*>(Reader.TGReadObject());
}
GetInlineBotResults::~GetInlineBotResults()
{

}
}//end namespace block
