#include "../Public/ChatInviteEmpty.h"


//begin namespace block
namespace COMMON
{

ChatInviteEmpty::ChatInviteEmpty()
{
	this->_ConstructorID = 1765269353;
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
}
ChatInviteEmpty::~ChatInviteEmpty()
{

}
}//end namespace block
