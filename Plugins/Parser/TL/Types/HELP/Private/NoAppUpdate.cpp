#include "../Public/NoAppUpdate.h"


//begin namespace block
namespace HELP
{

NoAppUpdate::NoAppUpdate()
{
	this->_ConstructorID = 912612036;
}
void NoAppUpdate::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void NoAppUpdate::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
NoAppUpdate::~NoAppUpdate()
{

}
}//end namespace block
