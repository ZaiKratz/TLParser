#include "../Public/ChannelParticipantSelf.h"


//begin namespace block
namespace COMMON
{

ChannelParticipantSelf::ChannelParticipantSelf()
{
	this->_ConstructorID = 1838819491;
}

ChannelParticipantSelf::ChannelParticipantSelf(int32 user_id, int32 inviter_id, FDateTime date)
{
	this->_ConstructorID = 1838819491;
	this->user_id = user_id;
	this->inviter_id = inviter_id;
	this->date = date;
}
void ChannelParticipantSelf::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
	Writer.WriteInt(this->inviter_id);
	Writer.TGWriteDate(this->date);
}


void ChannelParticipantSelf::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	inviter_id = Reader.ReadInt();
	date = Reader.TGReadDate();
}
ChannelParticipantSelf::~ChannelParticipantSelf()
{

}
}//end namespace block
