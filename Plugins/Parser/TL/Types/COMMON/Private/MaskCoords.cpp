#include "../Public/MaskCoords.h"


//begin namespace block
namespace COMMON
{

MaskCoords::MaskCoords()
{
	this->_ConstructorID = -1294215506;
}

MaskCoords::MaskCoords(int32 n, double x, double y, double zoom)
{
	this->_ConstructorID = -1294215506;
	this->n = n;
	this->x = x;
	this->y = y;
	this->zoom = zoom;
}
void MaskCoords::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->n);
	Writer.WriteDouble(this->x);
	Writer.WriteDouble(this->y);
	Writer.WriteDouble(this->zoom);
}


void MaskCoords::OnResponce(BinaryReader& Reader)
{
	n = Reader.ReadInt();
	x = Reader.ReadDouble();
	y = Reader.ReadDouble();
	zoom = Reader.ReadDouble();
}
MaskCoords::~MaskCoords()
{

}
}//end namespace block
