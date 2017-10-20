#include "../Public/StickersNotModified.h"


//begin namespace block
namespace MESSAGES
{

StickersNotModified::StickersNotModified()
{
	this->_ConstructorID = -244016606;
}
void StickersNotModified::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void StickersNotModified::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
StickersNotModified::~StickersNotModified()
{
}
}//end namespace block
