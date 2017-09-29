#include "../Public/UpdateChatParticipantDelete.h"


//begin namespace block
namespace COMMON
{

UpdateChatParticipantDelete::UpdateChatParticipantDelete()
{
	this->_ConstructorID = 1851755554;
}

UpdateChatParticipantDelete::UpdateChatParticipantDelete(int32 chat_id, int32 user_id, int32 version)
{
	this->_ConstructorID = 1851755554;
	this->chat_id = chat_id;
	this->user_id = user_id;
	this->version = version;
}
void UpdateChatParticipantDelete::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
	Writer.WriteInt(this->user_id);
	Writer.WriteInt(this->version);
}


void UpdateChatParticipantDelete::OnResponce(BinaryReader& Reader)
{
	chat_id = Reader.ReadInt();
	user_id = Reader.ReadInt();
	version = Reader.ReadInt();
	this->_Responded = true;
}
UpdateChatParticipantDelete::~UpdateChatParticipantDelete()
{

}
}//end namespace block
