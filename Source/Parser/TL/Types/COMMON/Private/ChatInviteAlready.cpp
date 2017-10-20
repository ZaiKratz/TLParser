#include "../Public/ChatInviteAlready.h"


//begin namespace block
namespace COMMON
{

ChatInviteAlready::ChatInviteAlready()
{
	this->_ConstructorID = 1516793212;
}

ChatInviteAlready::ChatInviteAlready(COMMON::Chat*  chat)
{
	this->_ConstructorID = 1516793212;
	this->chat = chat;
}
void ChatInviteAlready::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->chat->OnSend(Writer);
}


void ChatInviteAlready::OnResponce(BinaryReader& Reader)
{
	chat = reinterpret_cast<COMMON::Chat* >(Reader.TGReadObject());
	this->_Responded = true;
}
ChatInviteAlready::~ChatInviteAlready()
{
	if(this->chat)
	{
		delete this->chat;
	}
}
}//end namespace block
