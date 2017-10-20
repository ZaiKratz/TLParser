#include "../Public/InputBotInlineResultPhoto.h"


//begin namespace block
namespace COMMON
{

InputBotInlineResultPhoto::InputBotInlineResultPhoto()
{
	this->_ConstructorID = -1462213465;
}

InputBotInlineResultPhoto::InputBotInlineResultPhoto(FString id, FString type, COMMON::InputPhoto*  photo, TLBaseObject*  send_message)
{
	this->_ConstructorID = -1462213465;
	this->id = id;
	this->type = type;
	this->photo = photo;
	this->send_message = send_message;
}
void InputBotInlineResultPhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->id);
	Writer.TGWriteString(this->type);
	this->photo->OnSend(Writer);
	this->send_message->OnSend(Writer);
}


void InputBotInlineResultPhoto::OnResponce(BinaryReader& Reader)
{
	id = Reader.TGReadString();
	type = Reader.TGReadString();
	photo = reinterpret_cast<COMMON::InputPhoto* >(Reader.TGReadObject());
	send_message = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
InputBotInlineResultPhoto::~InputBotInlineResultPhoto()
{
	if(this->photo)
	{
		delete this->photo;
	}
	if(this->send_message)
	{
		delete this->send_message;
	}
}
}//end namespace block
