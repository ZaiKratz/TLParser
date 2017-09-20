#include "../Public/ChannelParticipant.h"


//begin namespace block
namespace CHANNELS
{

ChannelParticipant::ChannelParticipant()
{
	this->_ConstructorID = 1672600016;
}

ChannelParticipant::ChannelParticipant(COMMON::ChannelParticipant* participant, TArray<COMMON::User*> users)
{
	this->_ConstructorID = 1672600016;
	this->participant = participant;
	this->users = users;
}
void ChannelParticipant::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->participant->OnSend(Writer);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	X->OnSend(Writer);
	}
}


void ChannelParticipant::OnResponce(BinaryReader& Reader)
{
	participant = reinterpret_cast<COMMON::ChannelParticipant*>(Reader.TGReadObject());
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len19404 = Reader.ReadInt();
	for(int32 i = 0; i < Len19404; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
}
ChannelParticipant::~ChannelParticipant()
{

}
}//end namespace block
