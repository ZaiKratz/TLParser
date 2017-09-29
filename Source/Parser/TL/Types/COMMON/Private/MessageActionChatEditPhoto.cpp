#include "../Public/MessageActionChatEditPhoto.h"


//begin namespace block
namespace COMMON
{

MessageActionChatEditPhoto::MessageActionChatEditPhoto()
{
	this->_ConstructorID = 2144015272;
}

MessageActionChatEditPhoto::MessageActionChatEditPhoto(COMMON::Photo*  photo)
{
	this->_ConstructorID = 2144015272;
	this->photo = photo;
}
void MessageActionChatEditPhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->photo->OnSend(Writer);
}


void MessageActionChatEditPhoto::OnResponce(BinaryReader& Reader)
{
	photo = reinterpret_cast<COMMON::Photo* >(Reader.TGReadObject());
	this->_Responded = true;
}
MessageActionChatEditPhoto::~MessageActionChatEditPhoto()
{

}
}//end namespace block
