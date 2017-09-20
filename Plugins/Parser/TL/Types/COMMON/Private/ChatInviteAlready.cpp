#include "../Public/ChatInviteAlready.h"


//begin namespace block
namespace COMMON
{

ChatInviteAlready::ChatInviteAlready()
{
	this->_ConstructorID = 2087544922;
}

ChatInviteAlready::ChatInviteAlready(COMMON::Chat* chat)
{
	this->_ConstructorID = 2087544922;
	this->chat = chat;
}
void ChatInviteAlready::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->chat->OnSend(Writer);
}


void ChatInviteAlready::OnResponce(BinaryReader& Reader)
{
	chat = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
}
ChatInviteAlready::~ChatInviteAlready()
{

}
}//end namespace block