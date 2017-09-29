#include "../Public/MessageMediaGeo.h"


//begin namespace block
namespace COMMON
{

MessageMediaGeo::MessageMediaGeo()
{
	this->_ConstructorID = 1457575028;
}

MessageMediaGeo::MessageMediaGeo(COMMON::GeoPoint*  geo)
{
	this->_ConstructorID = 1457575028;
	this->geo = geo;
}
void MessageMediaGeo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->geo->OnSend(Writer);
}


void MessageMediaGeo::OnResponce(BinaryReader& Reader)
{
	geo = reinterpret_cast<COMMON::GeoPoint* >(Reader.TGReadObject());
	this->_Responded = true;
}
MessageMediaGeo::~MessageMediaGeo()
{

}
}//end namespace block
