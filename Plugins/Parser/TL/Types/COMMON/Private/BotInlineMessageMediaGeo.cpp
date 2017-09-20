#include "../Public/BotInlineMessageMediaGeo.h"


//begin namespace block
namespace COMMON
{

BotInlineMessageMediaGeo::BotInlineMessageMediaGeo()
{
	this->_ConstructorID = -1193767110;
}

BotInlineMessageMediaGeo::BotInlineMessageMediaGeo(COMMON::GeoPoint* geo, PRIVATE::ReplyMarkup* reply_markup)
{
	this->_ConstructorID = -1193767110;
	this->geo = geo;
	this->reply_markup = reply_markup;
}
void BotInlineMessageMediaGeo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!reply_markup)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->geo->OnSend(Writer);
	if(!this->reply_markup)
	{
	this->reply_markup->OnSend(Writer);
	}
}


void BotInlineMessageMediaGeo::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	geo = reinterpret_cast<COMMON::GeoPoint*>(Reader.TGReadObject());
	if((Flags & (1 << 2)) != 0) 
	{
	reply_markup = reinterpret_cast<PRIVATE::ReplyMarkup*>(Reader.TGReadObject());
	}
}
BotInlineMessageMediaGeo::~BotInlineMessageMediaGeo()
{

}
}//end namespace block
