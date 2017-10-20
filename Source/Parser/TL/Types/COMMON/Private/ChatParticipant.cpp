#include "../Public/ChatParticipant.h"


//begin namespace block
namespace COMMON
{

ChatParticipant::ChatParticipant()
{
	this->_ConstructorID = -925415106;
}

ChatParticipant::ChatParticipant(int32 user_id, int32 inviter_id, FDateTime date)
{
	this->_ConstructorID = -925415106;
	this->user_id = user_id;
	this->inviter_id = inviter_id;
	this->date = date;
}
void ChatParticipant::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
	Writer.WriteInt(this->inviter_id);
	Writer.TGWriteDate(this->date);
}


void ChatParticipant::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	inviter_id = Reader.ReadInt();
	date = Reader.TGReadDate();
	this->_Responded = true;
}
ChatParticipant::~ChatParticipant()
{
}
}//end namespace block
