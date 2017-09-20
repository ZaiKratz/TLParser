#include "../Public/GetMessages.h"


//begin namespace block
namespace CHANNELS
{

GetMessages::GetMessages()
{
	this->_ConstructorID = 1202968467;
	this->_ContentRelated = true;
}

GetMessages::GetMessages(COMMON::InputChannel* channel, TArray<int32> id)
{
	this->_ConstructorID = 1202968467;
	this->_ContentRelated = true;
	this->channel = channel;
	this->id = id;
}
void GetMessages::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->id.Num());
	for(auto X : this->id)
	{
	Writer.WriteInt(X);
	}
}


void GetMessages::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::Messages*>(Reader.TGReadObject());
}
GetMessages::~GetMessages()
{

}
}//end namespace block
