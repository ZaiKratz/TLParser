#include "../Public/ExportChatInvite.h"


//begin namespace block
namespace MESSAGES
{

ExportChatInvite::ExportChatInvite()
{
	this->_ConstructorID = 2106086025;
	this->_ContentRelated = true;
}

ExportChatInvite::ExportChatInvite(int32 chat_id)
{
	this->_ConstructorID = 2106086025;
	this->_ContentRelated = true;
	this->chat_id = chat_id;
}
void ExportChatInvite::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
}


void ExportChatInvite::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<PRIVATE::ExportedChatInvite*>(Reader.TGReadObject());
	this->_Responded = true;
}
ExportChatInvite::~ExportChatInvite()
{

}
}//end namespace block