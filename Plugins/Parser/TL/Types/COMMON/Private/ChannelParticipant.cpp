#include "../Public/ChannelParticipant.h"


//begin namespace block
namespace COMMON
{

ChannelParticipant::ChannelParticipant()
{
	this->_ConstructorID = 497871637;
}

ChannelParticipant::ChannelParticipant(int32 user_id, FDateTime date)
{
	this->_ConstructorID = 497871637;
	this->user_id = user_id;
	this->date = date;
}
void ChannelParticipant::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
	Writer.TGWriteDate(this->date);
}


void ChannelParticipant::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	date = Reader.TGReadDate();
}
ChannelParticipant::~ChannelParticipant()
{

}
}//end namespace block
