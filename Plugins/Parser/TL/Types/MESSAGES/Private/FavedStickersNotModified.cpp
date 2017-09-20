#include "../Public/FavedStickersNotModified.h"


//begin namespace block
namespace MESSAGES
{

FavedStickersNotModified::FavedStickersNotModified()
{
	this->_ConstructorID = -744058978;
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
}
FavedStickersNotModified::~FavedStickersNotModified()
{

}
}//end namespace block
