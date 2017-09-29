#include "../Public/MessageActionChatEditTitle.h"


//begin namespace block
namespace COMMON
{

MessageActionChatEditTitle::MessageActionChatEditTitle()
{
	this->_ConstructorID = -1247687078;
}

MessageActionChatEditTitle::MessageActionChatEditTitle(FString title)
{
	this->_ConstructorID = -1247687078;
	this->title = title;
}
void MessageActionChatEditTitle::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->title);
}


void MessageActionChatEditTitle::OnResponce(BinaryReader& Reader)
{
	title = Reader.TGReadString();
	this->_Responded = true;
}
MessageActionChatEditTitle::~MessageActionChatEditTitle()
{

}
}//end namespace block
