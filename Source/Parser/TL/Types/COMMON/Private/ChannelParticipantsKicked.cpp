#include "../Public/ChannelParticipantsKicked.h"


//begin namespace block
namespace COMMON
{

ChannelParticipantsKicked::ChannelParticipantsKicked()
{
	this->_ConstructorID = -1548400251;
}

ChannelParticipantsKicked::ChannelParticipantsKicked(FString q)
{
	this->_ConstructorID = -1548400251;
	this->q = q;
}
void ChannelParticipantsKicked::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->q);
}


void ChannelParticipantsKicked::OnResponce(BinaryReader& Reader)
{
	q = Reader.TGReadString();
	this->_Responded = true;
}
ChannelParticipantsKicked::~ChannelParticipantsKicked()
{

}
}//end namespace block
