#include "../Public/PageBlockChannel.h"


//begin namespace block
namespace COMMON
{

PageBlockChannel::PageBlockChannel()
{
	this->_ConstructorID = -283684427;
}

PageBlockChannel::PageBlockChannel(COMMON::Chat*  channel)
{
	this->_ConstructorID = -283684427;
	this->channel = channel;
}
void PageBlockChannel::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
}


void PageBlockChannel::OnResponce(BinaryReader& Reader)
{
	channel = reinterpret_cast<COMMON::Chat* >(Reader.TGReadObject());
	this->_Responded = true;
}
PageBlockChannel::~PageBlockChannel()
{

}
}//end namespace block
