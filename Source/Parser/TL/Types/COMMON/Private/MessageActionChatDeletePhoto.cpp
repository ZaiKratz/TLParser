#include "../Public/MessageActionChatDeletePhoto.h"


//begin namespace block
namespace COMMON
{

MessageActionChatDeletePhoto::MessageActionChatDeletePhoto()
{
	this->_ConstructorID = -1780220945;
}
void MessageActionChatDeletePhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void MessageActionChatDeletePhoto::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
MessageActionChatDeletePhoto::~MessageActionChatDeletePhoto()
{
}
}//end namespace block
