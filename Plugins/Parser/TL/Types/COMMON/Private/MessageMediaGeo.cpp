#include "../Public/MessageMediaGeo.h"


//begin namespace block
namespace COMMON
{

MessageMediaGeo::MessageMediaGeo()
{
	this->_ConstructorID = 1960108118;
}

MessageMediaGeo::MessageMediaGeo(COMMON::GeoPoint* geo)
{
	this->_ConstructorID = 1960108118;
	this->geo = geo;
}
void MessageMediaGeo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->geo->OnSend(Writer);
}


void MessageMediaGeo::OnResponce(BinaryReader& Reader)
{
	geo = reinterpret_cast<COMMON::GeoPoint*>(Reader.TGReadObject());
}
MessageMediaGeo::~MessageMediaGeo()
{

}
}//end namespace block
