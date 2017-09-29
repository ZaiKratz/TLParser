#include "../Public/InputBotInlineMessageMediaVenue.h"


//begin namespace block
namespace COMMON
{

InputBotInlineMessageMediaVenue::InputBotInlineMessageMediaVenue()
{
	this->_ConstructorID = -1431327288;
}

InputBotInlineMessageMediaVenue::InputBotInlineMessageMediaVenue(COMMON::InputGeoPoint*  geo_point, FString title, FString address, FString provider, FString venue_id, PRIVATE::ReplyMarkup*  reply_markup)
{
	this->_ConstructorID = -1431327288;
	this->geo_point = geo_point;
	this->title = title;
	this->address = address;
	this->provider = provider;
	this->venue_id = venue_id;
	this->reply_markup = reply_markup;
}
void InputBotInlineMessageMediaVenue::OnSend(BinaryWriter& Writer)
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

	this->geo_point->OnSend(Writer);
	Writer.TGWriteString(this->title);
	Writer.TGWriteString(this->address);
	Writer.TGWriteString(this->provider);
	Writer.TGWriteString(this->venue_id);
	if(!this->reply_markup)
	{
	this->reply_markup->OnSend(Writer);
	}
}


void InputBotInlineMessageMediaVenue::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	geo_point = reinterpret_cast<COMMON::InputGeoPoint* >(Reader.TGReadObject());
	title = Reader.TGReadString();
	address = Reader.TGReadString();
	provider = Reader.TGReadString();
	venue_id = Reader.TGReadString();
	if((Flags & (1 << 2)) != 0) 
	{
	reply_markup = reinterpret_cast<PRIVATE::ReplyMarkup* >(Reader.TGReadObject());
	}
	this->_Responded = true;
}
InputBotInlineMessageMediaVenue::~InputBotInlineMessageMediaVenue()
{

}
}//end namespace block