#include "../Public/BotInlineMessageMediaVenue.h"


//begin namespace block
namespace COMMON
{

BotInlineMessageMediaVenue::BotInlineMessageMediaVenue()
{
	this->_ConstructorID = 1130767150;
}

BotInlineMessageMediaVenue::BotInlineMessageMediaVenue(COMMON::GeoPoint*  geo, FString title, FString address, FString provider, FString venue_id, TLBaseObject*  reply_markup)
{
	this->_ConstructorID = 1130767150;
	this->geo = geo;
	this->title = title;
	this->address = address;
	this->provider = provider;
	this->venue_id = venue_id;
	this->reply_markup = reply_markup;
}
void BotInlineMessageMediaVenue::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(reply_markup)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->geo->OnSend(Writer);
	Writer.TGWriteString(this->title);
	Writer.TGWriteString(this->address);
	Writer.TGWriteString(this->provider);
	Writer.TGWriteString(this->venue_id);
	if(this->reply_markup)
	{
	this->reply_markup->OnSend(Writer);
	}
}


void BotInlineMessageMediaVenue::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	geo = reinterpret_cast<COMMON::GeoPoint* >(Reader.TGReadObject());
	title = Reader.TGReadString();
	address = Reader.TGReadString();
	provider = Reader.TGReadString();
	venue_id = Reader.TGReadString();
	if((Flags & (1 << 2)) != 0) 
	{
	reply_markup = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	}
	this->_Responded = true;
}
BotInlineMessageMediaVenue::~BotInlineMessageMediaVenue()
{
	if(this->geo)
	{
		delete this->geo;
	}
	if(this->reply_markup)
	{
		delete this->reply_markup;
	}
}
}//end namespace block
