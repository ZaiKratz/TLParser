#include "../Public/MessageActionChatEditPhoto.h"


//begin namespace block
namespace COMMON
{

MessageActionChatEditPhoto::MessageActionChatEditPhoto()
{
	this->_ConstructorID = -1475097729;
}

MessageActionChatEditPhoto::MessageActionChatEditPhoto(COMMON::Photo* photo)
{
	this->_ConstructorID = -1475097729;
	this->photo = photo;
}
void MessageActionChatEditPhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->photo->OnSend(Writer);
}


void MessageActionChatEditPhoto::OnResponce(BinaryReader& Reader)
{
	photo = reinterpret_cast<COMMON::Photo*>(Reader.TGReadObject());
}
MessageActionChatEditPhoto::~MessageActionChatEditPhoto()
{

}
}//end namespace block
