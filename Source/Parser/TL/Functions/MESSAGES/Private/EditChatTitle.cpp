#include "../Public/EditChatTitle.h"


//begin namespace block
namespace MESSAGES
{

EditChatTitle::EditChatTitle()
{
	this->_ConstructorID = -599447467;
	this->_ContentRelated = true;
}

EditChatTitle::EditChatTitle(int32 chat_id, FString title)
{
	this->_ConstructorID = -599447467;
	this->_ContentRelated = true;
	this->chat_id = chat_id;
	this->title = title;
}
void EditChatTitle::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
	Writer.TGWriteString(this->title);
}


void EditChatTitle::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
EditChatTitle::~EditChatTitle()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
