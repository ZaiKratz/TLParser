#include "../Public/PageBlockChannel.h"


//begin namespace block
namespace COMMON
{

PageBlockChannel::PageBlockChannel()
{
	this->_ConstructorID = -1252976657;
}

PageBlockChannel::PageBlockChannel(COMMON::Chat* channel)
{
	this->_ConstructorID = -1252976657;
	this->channel = channel;
}
void PageBlockChannel::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
}


void PageBlockChannel::OnResponce(BinaryReader& Reader)
{
	channel = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
}
PageBlockChannel::~PageBlockChannel()
{

}
}//end namespace block
