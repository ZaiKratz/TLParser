#include "../Public/ChatParticipantAdmin.h"


//begin namespace block
namespace COMMON
{

ChatParticipantAdmin::ChatParticipantAdmin()
{
	this->_ConstructorID = -489233354;
}

ChatParticipantAdmin::ChatParticipantAdmin(int32 user_id, int32 inviter_id, FDateTime date)
{
	this->_ConstructorID = -489233354;
	this->user_id = user_id;
	this->inviter_id = inviter_id;
	this->date = date;
}
void ChatParticipantAdmin::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
	Writer.WriteInt(this->inviter_id);
	Writer.TGWriteDate(this->date);
}


void ChatParticipantAdmin::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	inviter_id = Reader.ReadInt();
	date = Reader.TGReadDate();
	this->_Responded = true;
}
ChatParticipantAdmin::~ChatParticipantAdmin()
{
}
}//end namespace block
