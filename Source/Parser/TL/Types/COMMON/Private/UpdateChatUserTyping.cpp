#include "../Public/UpdateChatUserTyping.h"


//begin namespace block
namespace COMMON
{

UpdateChatUserTyping::UpdateChatUserTyping()
{
	this->_ConstructorID = -1704596961;
}

UpdateChatUserTyping::UpdateChatUserTyping(int32 chat_id, int32 user_id, TLBaseObject*  action)
{
	this->_ConstructorID = -1704596961;
	this->chat_id = chat_id;
	this->user_id = user_id;
	this->action = action;
}
void UpdateChatUserTyping::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
	Writer.WriteInt(this->user_id);
	this->action->OnSend(Writer);
}


void UpdateChatUserTyping::OnResponce(BinaryReader& Reader)
{
	chat_id = Reader.ReadInt();
	user_id = Reader.ReadInt();
	action = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
UpdateChatUserTyping::~UpdateChatUserTyping()
{
	if(this->action)
	{
		delete this->action;
	}
}
}//end namespace block
