#include "../Public/GeoPointEmpty.h"


//begin namespace block
namespace COMMON
{

GeoPointEmpty::GeoPointEmpty()
{
	this->_ConstructorID = 1608324881;
}
void GeoPointEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GeoPointEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
GeoPointEmpty::~GeoPointEmpty()
{

}
}//end namespace block
