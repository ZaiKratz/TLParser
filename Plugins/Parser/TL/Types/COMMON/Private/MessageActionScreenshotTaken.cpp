#include "../Public/MessageActionScreenshotTaken.h"


//begin namespace block
namespace COMMON
{

MessageActionScreenshotTaken::MessageActionScreenshotTaken()
{
	this->_ConstructorID = -1684893113;
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
}
MessageActionScreenshotTaken::~MessageActionScreenshotTaken()
{

}
}//end namespace block
