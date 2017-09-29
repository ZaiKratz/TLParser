#include "../Public/UpdateChannelTooLong.h"


//begin namespace block
namespace COMMON
{

UpdateChannelTooLong::UpdateChannelTooLong()
{
	this->_ConstructorID = -352032773;
}

UpdateChannelTooLong::UpdateChannelTooLong(int32 channel_id, int32 pts)
{
	this->_ConstructorID = -352032773;
	this->channel_id = channel_id;
	this->pts = pts;
}
void UpdateChannelTooLong::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(pts)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->channel_id);
	if(!this->pts)
	{
	Writer.WriteInt(this->pts);
	}
}


void UpdateChannelTooLong::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	channel_id = Reader.ReadInt();
	if((Flags & (1 << 0)) != 0) 
	{
	pts = Reader.ReadInt();
	}
	this->_Responded = true;
}
UpdateChannelTooLong::~UpdateChannelTooLong()
{

}
}//end namespace block
