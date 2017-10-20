#include "../Public/EditChatPhoto.h"


//begin namespace block
namespace MESSAGES
{

EditChatPhoto::EditChatPhoto()
{
	this->_ConstructorID = -900957736;
	this->_ContentRelated = true;
}

EditChatPhoto::EditChatPhoto(int32 chat_id, COMMON::InputChatPhoto*  photo)
{
	this->_ConstructorID = -900957736;
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
	this->_Responded = true;
}
EditChatPhoto::~EditChatPhoto()
{
	if(this->photo)
	{
		delete this->photo;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
