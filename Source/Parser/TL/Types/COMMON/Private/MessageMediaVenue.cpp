#include "../Public/MessageMediaVenue.h"


//begin namespace block
namespace COMMON
{

MessageMediaVenue::MessageMediaVenue()
{
	this->_ConstructorID = 2031269663;
}

MessageMediaVenue::MessageMediaVenue(COMMON::GeoPoint*  geo, FString title, FString address, FString provider, FString venue_id)
{
	this->_ConstructorID = 2031269663;
	this->geo = geo;
	this->title = title;
	this->address = address;
	this->provider = provider;
	this->venue_id = venue_id;
}
void MessageMediaVenue::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->geo->OnSend(Writer);
	Writer.TGWriteString(this->title);
	Writer.TGWriteString(this->address);
	Writer.TGWriteString(this->provider);
	Writer.TGWriteString(this->venue_id);
}


void MessageMediaVenue::OnResponce(BinaryReader& Reader)
{
	geo = reinterpret_cast<COMMON::GeoPoint* >(Reader.TGReadObject());
	title = Reader.TGReadString();
	address = Reader.TGReadString();
	provider = Reader.TGReadString();
	venue_id = Reader.TGReadString();
	this->_Responded = true;
}
MessageMediaVenue::~MessageMediaVenue()
{

}
}//end namespace block
