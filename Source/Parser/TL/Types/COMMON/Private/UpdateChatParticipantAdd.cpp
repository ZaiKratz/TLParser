#include "../Public/UpdateChatParticipantAdd.h"


//begin namespace block
namespace COMMON
{

UpdateChatParticipantAdd::UpdateChatParticipantAdd()
{
	this->_ConstructorID = -364179876;
}

UpdateChatParticipantAdd::UpdateChatParticipantAdd(int32 chat_id, int32 user_id, int32 inviter_id, FDateTime date, int32 version)
{
	this->_ConstructorID = -364179876;
	this->chat_id = chat_id;
	this->user_id = user_id;
	this->inviter_id = inviter_id;
	this->date = date;
	this->version = version;
}
void UpdateChatParticipantAdd::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
	Writer.WriteInt(this->user_id);
	Writer.WriteInt(this->inviter_id);
	Writer.TGWriteDate(this->date);
	Writer.WriteInt(this->version);
}


void UpdateChatParticipantAdd::OnResponce(BinaryReader& Reader)
{
	chat_id = Reader.ReadInt();
	user_id = Reader.ReadInt();
	inviter_id = Reader.ReadInt();
	date = Reader.TGReadDate();
	version = Reader.ReadInt();
	this->_Responded = true;
}
UpdateChatParticipantAdd::~UpdateChatParticipantAdd()
{

}
}//end namespace block
