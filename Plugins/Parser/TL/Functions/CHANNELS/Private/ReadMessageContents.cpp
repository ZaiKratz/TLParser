#include "../Public/ReadMessageContents.h"


//begin namespace block
namespace CHANNELS
{

ReadMessageContents::ReadMessageContents()
{
	this->_ConstructorID = 953988586;
	this->_ContentRelated = true;
}

ReadMessageContents::ReadMessageContents(COMMON::InputChannel* channel, TArray<int32> id)
{
	this->_ConstructorID = 953988586;
	this->_ContentRelated = true;
	this->channel = channel;
	this->id = id;
}
void ReadMessageContents::OnSend(BinaryWriter& Writer)
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


void ReadMessageContents::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
}
ReadMessageContents::~ReadMessageContents()
{

}
}//end namespace block
