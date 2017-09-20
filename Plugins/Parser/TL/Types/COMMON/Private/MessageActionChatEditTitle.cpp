#include "../Public/MessageActionChatEditTitle.h"


//begin namespace block
namespace COMMON
{

MessageActionChatEditTitle::MessageActionChatEditTitle()
{
	this->_ConstructorID = 1523491253;
}

MessageActionChatEditTitle::MessageActionChatEditTitle(FString title)
{
	this->_ConstructorID = 1523491253;
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
}
MessageActionChatEditTitle::~MessageActionChatEditTitle()
{

}
}//end namespace block
