#include "../Public/ChannelParticipant.h"


//begin namespace block
namespace CHANNELS
{

ChannelParticipant::ChannelParticipant()
{
	this->_ConstructorID = -791039645;
}

ChannelParticipant::ChannelParticipant(COMMON::ChannelParticipant*  participant, TArray<COMMON::User*>  users)
{
	this->_ConstructorID = -791039645;
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
	participant = reinterpret_cast<COMMON::ChannelParticipant* >(Reader.TGReadObject());
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len29604 = Reader.ReadInt();
	for(int32 i = 0; i < Len29604; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	this->_Responded = true;
}
ChannelParticipant::~ChannelParticipant()
{
	if(this->participant)
	{
		delete this->participant;
	}
}
}//end namespace block
