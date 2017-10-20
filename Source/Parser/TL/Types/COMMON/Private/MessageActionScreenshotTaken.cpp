#include "../Public/MessageActionScreenshotTaken.h"


//begin namespace block
namespace COMMON
{

MessageActionScreenshotTaken::MessageActionScreenshotTaken()
{
	this->_ConstructorID = 1200788123;
}
void MessageActionScreenshotTaken::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void MessageActionScreenshotTaken::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
MessageActionScreenshotTaken::~MessageActionScreenshotTaken()
{
}
}//end namespace block
