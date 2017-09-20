#include "../Public/UpdateChatAdmins.h"


//begin namespace block
namespace COMMON
{

UpdateChatAdmins::UpdateChatAdmins()
{
	this->_ConstructorID = 1098486894;
}

UpdateChatAdmins::UpdateChatAdmins(int32 chat_id, bool enabled, int32 version)
{
	this->_ConstructorID = 1098486894;
	this->chat_id = chat_id;
	this->enabled = enabled;
	this->version = version;
}
void UpdateChatAdmins::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
	Writer.WriteBool(this->enabled);
	Writer.WriteInt(this->version);
}


void UpdateChatAdmins::OnResponce(BinaryReader& Reader)
{
	chat_id = Reader.ReadInt();
	enabled = Reader.ReadBool();
	version = Reader.ReadInt();
}
UpdateChatAdmins::~UpdateChatAdmins()
{

}
}//end namespace block
