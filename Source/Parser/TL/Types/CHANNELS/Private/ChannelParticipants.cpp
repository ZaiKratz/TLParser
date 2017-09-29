#include "../Public/ChannelParticipants.h"


//begin namespace block
namespace CHANNELS
{

ChannelParticipants::ChannelParticipants()
{
	this->_ConstructorID = -177282392;
}

ChannelParticipants::ChannelParticipants(int32 count, TArray<COMMON::ChannelParticipant*>  participants, TArray<COMMON::User*>  users)
{
	this->_ConstructorID = -177282392;
	this->count = count;
	this->participants = participants;
	this->users = users;
}
void ChannelParticipants::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->count);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->participants.Num());
	for(auto X : this->participants)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	X->OnSend(Writer);
	}
}


void ChannelParticipants::OnResponce(BinaryReader& Reader)
{
	count = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len21241 = Reader.ReadInt();
	for(int32 i = 0; i < Len21241; i++)
	{
	auto X = reinterpret_cast<COMMON::ChannelParticipant*>(Reader.TGReadObject());
	participants.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len26276 = Reader.ReadInt();
	for(int32 i = 0; i < Len26276; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	this->_Responded = true;
}
ChannelParticipants::~ChannelParticipants()
{

}
}//end namespace block
