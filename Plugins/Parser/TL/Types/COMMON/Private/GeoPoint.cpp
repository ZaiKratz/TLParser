#include "../Public/GeoPoint.h"


//begin namespace block
namespace COMMON
{

GeoPoint::GeoPoint()
{
	this->_ConstructorID = 215435552;
}

GeoPoint::GeoPoint(double Long, double lat)
{
	this->_ConstructorID = 215435552;
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
}
GeoPoint::~GeoPoint()
{

}
}//end namespace block
