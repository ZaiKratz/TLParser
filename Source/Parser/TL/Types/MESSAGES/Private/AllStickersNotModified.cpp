#include "../Public/AllStickersNotModified.h"


//begin namespace block
namespace MESSAGES
{

AllStickersNotModified::AllStickersNotModified()
{
	this->_ConstructorID = -395967805;
}
void AllStickersNotModified::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void AllStickersNotModified::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
AllStickersNotModified::~AllStickersNotModified()
{
}
}//end namespace block
