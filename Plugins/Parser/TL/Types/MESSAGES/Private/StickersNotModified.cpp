#include "../Public/StickersNotModified.h"


//begin namespace block
namespace MESSAGES
{

StickersNotModified::StickersNotModified()
{
	this->_ConstructorID = 580547825;
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
}
StickersNotModified::~StickersNotModified()
{

}
}//end namespace block
