#include "../Public/GetChannelDifference.h"


//begin namespace block
namespace UPDATES
{

GetChannelDifference::GetChannelDifference()
{
	this->_ConstructorID = 51854712;
	this->_ContentRelated = true;
}

GetChannelDifference::GetChannelDifference(bool force, COMMON::InputChannel*  channel, COMMON::ChannelMessagesFilter*  filter, int32 pts, int32 limit)
{
	this->_ConstructorID = 51854712;
	this->_ContentRelated = true;
	this->force = force;
	this->channel = channel;
	this->filter = filter;
	this->pts = pts;
	this->limit = limit;
}
void GetChannelDifference::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(force)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->channel->OnSend(Writer);
	this->filter->OnSend(Writer);
	Writer.WriteInt(this->pts);
	Writer.WriteInt(this->limit);
}


void GetChannelDifference::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<UPDATES::ChannelDifference*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetChannelDifference::~GetChannelDifference()
{

}
}//end namespace block
