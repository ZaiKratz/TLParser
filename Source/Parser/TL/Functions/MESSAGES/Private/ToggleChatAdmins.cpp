#include "../Public/ToggleChatAdmins.h"


//begin namespace block
namespace MESSAGES
{

ToggleChatAdmins::ToggleChatAdmins()
{
	this->_ConstructorID = -326379039;
	this->_ContentRelated = true;
}

ToggleChatAdmins::ToggleChatAdmins(int32 chat_id, bool enabled)
{
	this->_ConstructorID = -326379039;
	this->_ContentRelated = true;
	this->chat_id = chat_id;
	this->enabled = enabled;
}
void ToggleChatAdmins::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
	Writer.WriteBool(this->enabled);
}


void ToggleChatAdmins::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
ToggleChatAdmins::~ToggleChatAdmins()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
