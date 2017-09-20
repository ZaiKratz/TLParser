#include "../Public/AddChatUser.h"


//begin namespace block
namespace MESSAGES
{

AddChatUser::AddChatUser()
{
	this->_ConstructorID = 162177273;
	this->_ContentRelated = true;
}

AddChatUser::AddChatUser(int32 chat_id, COMMON::InputUser* user_id, int32 fwd_limit)
{
	this->_ConstructorID = 162177273;
	this->_ContentRelated = true;
	this->chat_id = chat_id;
	this->user_id = user_id;
	this->fwd_limit = fwd_limit;
}
void AddChatUser::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
	this->user_id->OnSend(Writer);
	Writer.WriteInt(this->fwd_limit);
}


void AddChatUser::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
}
AddChatUser::~AddChatUser()
{

}
}//end namespace block
