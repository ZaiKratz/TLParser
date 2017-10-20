#include "../Public/InviteToChannel.h"


//begin namespace block
namespace CHANNELS
{

InviteToChannel::InviteToChannel()
{
	this->_ConstructorID = 429865580;
	this->_ContentRelated = true;
}

InviteToChannel::InviteToChannel(COMMON::InputChannel*  channel, TArray<COMMON::InputUser*>  users)
{
	this->_ConstructorID = 429865580;
	this->_ContentRelated = true;
	this->channel = channel;
	this->users = users;
}
void InviteToChannel::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	X->OnSend(Writer);
	}
}


void InviteToChannel::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
InviteToChannel::~InviteToChannel()
{
	if(this->channel)
	{
		delete this->channel;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
