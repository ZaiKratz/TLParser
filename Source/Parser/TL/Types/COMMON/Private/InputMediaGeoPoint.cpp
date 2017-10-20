#include "../Public/InputMediaGeoPoint.h"


//begin namespace block
namespace COMMON
{

InputMediaGeoPoint::InputMediaGeoPoint()
{
	this->_ConstructorID = -104578748;
}

InputMediaGeoPoint::InputMediaGeoPoint(COMMON::InputGeoPoint*  geo_point)
{
	this->_ConstructorID = -104578748;
	this->geo_point = geo_point;
}
void InputMediaGeoPoint::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->geo_point->OnSend(Writer);
}


void InputMediaGeoPoint::OnResponce(BinaryReader& Reader)
{
	geo_point = reinterpret_cast<COMMON::InputGeoPoint* >(Reader.TGReadObject());
	this->_Responded = true;
}
InputMediaGeoPoint::~InputMediaGeoPoint()
{
	if(this->geo_point)
	{
		delete this->geo_point;
	}
}
}//end namespace block
