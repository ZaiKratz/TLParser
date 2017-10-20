#include "../Public/NoAppUpdate.h"


//begin namespace block
namespace HELP
{

NoAppUpdate::NoAppUpdate()
{
	this->_ConstructorID = -1000708810;
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
	this->_Responded = true;
}
NoAppUpdate::~NoAppUpdate()
{
}
}//end namespace block
