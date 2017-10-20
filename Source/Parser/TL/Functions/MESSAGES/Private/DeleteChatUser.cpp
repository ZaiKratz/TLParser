#include "../Public/DeleteChatUser.h"


//begin namespace block
namespace MESSAGES
{

DeleteChatUser::DeleteChatUser()
{
	this->_ConstructorID = -530505962;
	this->_ContentRelated = true;
}

DeleteChatUser::DeleteChatUser(int32 chat_id, COMMON::InputUser*  user_id)
{
	this->_ConstructorID = -530505962;
	this->_ContentRelated = true;
	this->chat_id = chat_id;
	this->user_id = user_id;
}
void DeleteChatUser::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
	this->user_id->OnSend(Writer);
}


void DeleteChatUser::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
DeleteChatUser::~DeleteChatUser()
{
	if(this->user_id)
	{
		delete this->user_id;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
