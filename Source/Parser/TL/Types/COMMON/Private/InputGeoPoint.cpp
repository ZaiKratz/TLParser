#include "../Public/InputGeoPoint.h"


//begin namespace block
namespace COMMON
{

InputGeoPoint::InputGeoPoint()
{
	this->_ConstructorID = -206066487;
}

InputGeoPoint::InputGeoPoint(double lat, double Long)
{
	this->_ConstructorID = -206066487;
	this->lat = lat;
	this->Long = Long;
}
void InputGeoPoint::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteDouble(this->lat);
	Writer.WriteDouble(this->Long);
}


void InputGeoPoint::OnResponce(BinaryReader& Reader)
{
	lat = Reader.ReadDouble();
	Long = Reader.ReadDouble();
	this->_Responded = true;
}
InputGeoPoint::~InputGeoPoint()
{
}
}//end namespace block
