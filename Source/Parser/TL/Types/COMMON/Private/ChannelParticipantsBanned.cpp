#include "../Public/ChannelParticipantsBanned.h"


//begin namespace block
namespace COMMON
{

ChannelParticipantsBanned::ChannelParticipantsBanned()
{
	this->_ConstructorID = 338142689;
}

ChannelParticipantsBanned::ChannelParticipantsBanned(FString q)
{
	this->_ConstructorID = 338142689;
	this->q = q;
}
void ChannelParticipantsBanned::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->q);
}


void ChannelParticipantsBanned::OnResponce(BinaryReader& Reader)
{
	q = Reader.TGReadString();
	this->_Responded = true;
}
ChannelParticipantsBanned::~ChannelParticipantsBanned()
{
}
}//end namespace block
