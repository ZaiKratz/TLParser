#include "../Public/ChannelParticipantsKicked.h"


//begin namespace block
namespace COMMON
{

ChannelParticipantsKicked::ChannelParticipantsKicked()
{
	this->_ConstructorID = -2058766941;
}

ChannelParticipantsKicked::ChannelParticipantsKicked(FString q)
{
	this->_ConstructorID = -2058766941;
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
}
ChannelParticipantsKicked::~ChannelParticipantsKicked()
{

}
}//end namespace block
