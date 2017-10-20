#include "../Public/UpdateChatParticipantAdmin.h"


//begin namespace block
namespace COMMON
{

UpdateChatParticipantAdmin::UpdateChatParticipantAdmin()
{
	this->_ConstructorID = -1232070311;
}

UpdateChatParticipantAdmin::UpdateChatParticipantAdmin(int32 chat_id, int32 user_id, bool is_admin, int32 version)
{
	this->_ConstructorID = -1232070311;
	this->chat_id = chat_id;
	this->user_id = user_id;
	this->is_admin = is_admin;
	this->version = version;
}
void UpdateChatParticipantAdmin::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
	Writer.WriteInt(this->user_id);
	Writer.WriteBool(this->is_admin);
	Writer.WriteInt(this->version);
}


void UpdateChatParticipantAdmin::OnResponce(BinaryReader& Reader)
{
	chat_id = Reader.ReadInt();
	user_id = Reader.ReadInt();
	is_admin = Reader.ReadBool();
	version = Reader.ReadInt();
	this->_Responded = true;
}
UpdateChatParticipantAdmin::~UpdateChatParticipantAdmin()
{
}
}//end namespace block
