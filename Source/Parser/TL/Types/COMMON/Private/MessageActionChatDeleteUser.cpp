#include "../Public/MessageActionChatDeleteUser.h"


//begin namespace block
namespace COMMON
{

MessageActionChatDeleteUser::MessageActionChatDeleteUser()
{
	this->_ConstructorID = -1297179892;
}

MessageActionChatDeleteUser::MessageActionChatDeleteUser(int32 user_id)
{
	this->_ConstructorID = -1297179892;
	this->user_id = user_id;
}
void MessageActionChatDeleteUser::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
}


void MessageActionChatDeleteUser::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	this->_Responded = true;
}
MessageActionChatDeleteUser::~MessageActionChatDeleteUser()
{

}
}//end namespace block
