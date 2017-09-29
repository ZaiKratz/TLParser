#include "../Public/UpdateDeleteChannelMessages.h"


//begin namespace block
namespace COMMON
{

UpdateDeleteChannelMessages::UpdateDeleteChannelMessages()
{
	this->_ConstructorID = -1015733815;
}

UpdateDeleteChannelMessages::UpdateDeleteChannelMessages(int32 channel_id, TArray<int32>  messages, int32 pts, int32 pts_count)
{
	this->_ConstructorID = -1015733815;
	this->channel_id = channel_id;
	this->messages = messages;
	this->pts = pts;
	this->pts_count = pts_count;
}
void UpdateDeleteChannelMessages::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->channel_id);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->messages.Num());
	for(auto X : this->messages)
	{
	Writer.WriteInt(X);
	}
	Writer.WriteInt(this->pts);
	Writer.WriteInt(this->pts_count);
}


void UpdateDeleteChannelMessages::OnResponce(BinaryReader& Reader)
{
	channel_id = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len25734 = Reader.ReadInt();
	for(int32 i = 0; i < Len25734; i++)
	{
	auto X = Reader.ReadInt();
	messages.Add(X);
	}
	pts = Reader.ReadInt();
	pts_count = Reader.ReadInt();
	this->_Responded = true;
}
UpdateDeleteChannelMessages::~UpdateDeleteChannelMessages()
{

}
}//end namespace block
