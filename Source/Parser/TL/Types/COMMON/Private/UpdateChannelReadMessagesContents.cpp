#include "../Public/UpdateChannelReadMessagesContents.h"


//begin namespace block
namespace COMMON
{

UpdateChannelReadMessagesContents::UpdateChannelReadMessagesContents()
{
	this->_ConstructorID = -1987495099;
}

UpdateChannelReadMessagesContents::UpdateChannelReadMessagesContents(int32 channel_id, TArray<int32>  messages)
{
	this->_ConstructorID = -1987495099;
	this->channel_id = channel_id;
	this->messages = messages;
}
void UpdateChannelReadMessagesContents::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->channel_id);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->messages.Num());
	for(auto X : this->messages)
	{
	Writer.WriteInt(X);
	}
}


void UpdateChannelReadMessagesContents::OnResponce(BinaryReader& Reader)
{
	channel_id = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len9194 = Reader.ReadInt();
	for(int32 i = 0; i < Len9194; i++)
	{
	auto X = Reader.ReadInt();
	messages.Add(X);
	}
	this->_Responded = true;
}
UpdateChannelReadMessagesContents::~UpdateChannelReadMessagesContents()
{
}
}//end namespace block
