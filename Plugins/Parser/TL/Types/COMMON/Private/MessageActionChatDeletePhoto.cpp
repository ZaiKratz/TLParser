#include "../Public/MessageActionChatDeletePhoto.h"


//begin namespace block
namespace COMMON
{

MessageActionChatDeletePhoto::MessageActionChatDeletePhoto()
{
	this->_ConstructorID = -268704875;
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
}
MessageActionChatDeletePhoto::~MessageActionChatDeletePhoto()
{

}
}//end namespace block
