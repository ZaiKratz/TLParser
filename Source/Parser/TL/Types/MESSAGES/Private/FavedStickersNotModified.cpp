#include "../Public/FavedStickersNotModified.h"


//begin namespace block
namespace MESSAGES
{

FavedStickersNotModified::FavedStickersNotModified()
{
	this->_ConstructorID = -1634752813;
}
void FavedStickersNotModified::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void FavedStickersNotModified::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
FavedStickersNotModified::~FavedStickersNotModified()
{

}
}//end namespace block
