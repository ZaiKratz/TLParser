#include "../Public/MessageActionChannelCreate.h"


//begin namespace block
namespace COMMON
{

MessageActionChannelCreate::MessageActionChannelCreate()
{
	this->_ConstructorID = -1834167659;
}

MessageActionChannelCreate::MessageActionChannelCreate(FString title)
{
	this->_ConstructorID = -1834167659;
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
}
MessageActionChannelCreate::~MessageActionChannelCreate()
{

}
}//end namespace block
