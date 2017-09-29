#include "../Public/ChannelParticipantCreator.h"


//begin namespace block
namespace COMMON
{

ChannelParticipantCreator::ChannelParticipantCreator()
{
	this->_ConstructorID = -471670279;
}

ChannelParticipantCreator::ChannelParticipantCreator(int32 user_id)
{
	this->_ConstructorID = -471670279;
	this->user_id = user_id;
}
void ChannelParticipantCreator::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
}


void ChannelParticipantCreator::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	this->_Responded = true;
}
ChannelParticipantCreator::~ChannelParticipantCreator()
{

}
}//end namespace block
