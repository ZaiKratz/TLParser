#include "../Public/ChatInviteEmpty.h"


//begin namespace block
namespace COMMON
{

ChatInviteEmpty::ChatInviteEmpty()
{
	this->_ConstructorID = 1776236393;
}
void ChatInviteEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void ChatInviteEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
ChatInviteEmpty::~ChatInviteEmpty()
{

}
}//end namespace block
