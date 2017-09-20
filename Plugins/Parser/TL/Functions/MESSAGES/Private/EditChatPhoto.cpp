#include "../Public/EditChatPhoto.h"


//begin namespace block
namespace MESSAGES
{

EditChatPhoto::EditChatPhoto()
{
	this->_ConstructorID = -663139126;
	this->_ContentRelated = true;
}

EditChatPhoto::EditChatPhoto(int32 chat_id, COMMON::InputChatPhoto* photo)
{
	this->_ConstructorID = -663139126;
	this->_ContentRelated = true;
	this->chat_id = chat_id;
	this->photo = photo;
}
void EditChatPhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
	this->photo->OnSend(Writer);
}


void EditChatPhoto::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
}
EditChatPhoto::~EditChatPhoto()
{

}
}//end namespace block
