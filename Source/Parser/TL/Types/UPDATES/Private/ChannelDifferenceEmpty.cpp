#include "../Public/ChannelDifferenceEmpty.h"


//begin namespace block
namespace UPDATES
{

ChannelDifferenceEmpty::ChannelDifferenceEmpty()
{
	this->_ConstructorID = 1041346555;
}

ChannelDifferenceEmpty::ChannelDifferenceEmpty(bool final, int32 pts, int32 timeout)
{
	this->_ConstructorID = 1041346555;
	this->final = final;
	this->pts = pts;
	this->timeout = timeout;
}
void ChannelDifferenceEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(final)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(timeout)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->pts);
	if(this->timeout)
	{
	Writer.WriteInt(this->timeout);
	}
}


void ChannelDifferenceEmpty::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		final = true;
	}
	pts = Reader.ReadInt();
	if((Flags & (1 << 1)) != 0) 
	{
	timeout = Reader.ReadInt();
	}
	this->_Responded = true;
}
ChannelDifferenceEmpty::~ChannelDifferenceEmpty()
{
}
}//end namespace block
