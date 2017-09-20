#include "../Public/InputMediaGeoPoint.h"


//begin namespace block
namespace COMMON
{

InputMediaGeoPoint::InputMediaGeoPoint()
{
	this->_ConstructorID = 1145160953;
}

InputMediaGeoPoint::InputMediaGeoPoint(COMMON::InputGeoPoint* geo_point)
{
	this->_ConstructorID = 1145160953;
	this->geo_point = geo_point;
}
void InputMediaGeoPoint::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->geo_point->OnSend(Writer);
}


void InputMediaGeoPoint::OnResponce(BinaryReader& Reader)
{
	geo_point = reinterpret_cast<COMMON::InputGeoPoint*>(Reader.TGReadObject());
}
InputMediaGeoPoint::~InputMediaGeoPoint()
{

}
}//end namespace block
