#include "../Public/MessageActionChannelCreate.h"


//begin namespace block
namespace COMMON
{

MessageActionChannelCreate::MessageActionChannelCreate()
{
	this->_ConstructorID = -1781355374;
}

MessageActionChannelCreate::MessageActionChannelCreate(FString title)
{
	this->_ConstructorID = -1781355374;
	this->title = title;
}
void MessageActionChannelCreate::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->title);
}


void MessageActionChannelCreate::OnResponce(BinaryReader& Reader)
{
	title = Reader.TGReadString();
	this->_Responded = true;
}
MessageActionChannelCreate::~MessageActionChannelCreate()
{
}
}//end namespace block
