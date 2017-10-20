#include "../Public/EditChatAdmin.h"


//begin namespace block
namespace MESSAGES
{

EditChatAdmin::EditChatAdmin()
{
	this->_ConstructorID = -1444503762;
	this->_ContentRelated = true;
}

EditChatAdmin::EditChatAdmin(int32 chat_id, COMMON::InputUser*  user_id, bool is_admin)
{
	this->_ConstructorID = -1444503762;
	this->_ContentRelated = true;
	this->chat_id = chat_id;
	this->user_id = user_id;
	this->is_admin = is_admin;
}
void EditChatAdmin::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
	this->user_id->OnSend(Writer);
	Writer.WriteBool(this->is_admin);
}


void EditChatAdmin::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
EditChatAdmin::~EditChatAdmin()
{
	if(this->user_id)
	{
		delete this->user_id;
	}
}
}//end namespace block
