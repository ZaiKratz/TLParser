#include "../Public/GeoPoint.h"


//begin namespace block
namespace COMMON
{

GeoPoint::GeoPoint()
{
	this->_ConstructorID = 541710092;
}

GeoPoint::GeoPoint(double Long, double lat)
{
	this->_ConstructorID = 541710092;
	this->Long = Long;
	this->lat = lat;
}
void GeoPoint::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteDouble(this->Long);
	Writer.WriteDouble(this->lat);
}


void GeoPoint::OnResponce(BinaryReader& Reader)
{
	Long = Reader.ReadDouble();
	lat = Reader.ReadDouble();
	this->_Responded = true;
}
GeoPoint::~GeoPoint()
{

}
}//end namespace block
