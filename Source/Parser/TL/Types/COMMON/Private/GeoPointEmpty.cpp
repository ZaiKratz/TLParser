#include "../Public/GeoPointEmpty.h"


//begin namespace block
namespace COMMON
{

GeoPointEmpty::GeoPointEmpty()
{
	this->_ConstructorID = 286776671;
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
	this->_Responded = true;
}
GeoPointEmpty::~GeoPointEmpty()
{
}
}//end namespace block
