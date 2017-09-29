#include "../Public/InputMediaVenue.h"


//begin namespace block
namespace COMMON
{

InputMediaVenue::InputMediaVenue()
{
	this->_ConstructorID = 673687578;
}

InputMediaVenue::InputMediaVenue(COMMON::InputGeoPoint*  geo_point, FString title, FString address, FString provider, FString venue_id)
{
	this->_ConstructorID = 673687578;
	this->geo_point = geo_point;
	this->title = title;
	this->address = address;
	this->provider = provider;
	this->venue_id = venue_id;
}
void InputMediaVenue::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->geo_point->OnSend(Writer);
	Writer.TGWriteString(this->title);
	Writer.TGWriteString(this->address);
	Writer.TGWriteString(this->provider);
	Writer.TGWriteString(this->venue_id);
}


void InputMediaVenue::OnResponce(BinaryReader& Reader)
{
	geo_point = reinterpret_cast<COMMON::InputGeoPoint* >(Reader.TGReadObject());
	title = Reader.TGReadString();
	address = Reader.TGReadString();
	provider = Reader.TGReadString();
	venue_id = Reader.TGReadString();
	this->_Responded = true;
}
InputMediaVenue::~InputMediaVenue()
{

}
}//end namespace block
