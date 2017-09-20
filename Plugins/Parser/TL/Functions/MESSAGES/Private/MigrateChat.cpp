#include "../Public/MigrateChat.h"


//begin namespace block
namespace MESSAGES
{

MigrateChat::MigrateChat()
{
	this->_ConstructorID = -474438891;
	this->_ContentRelated = true;
}

MigrateChat::MigrateChat(int32 chat_id)
{
	this->_ConstructorID = -474438891;
	this->_ContentRelated = true;
	this->chat_id = chat_id;
}
void MigrateChat::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
}


void MigrateChat::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
}
MigrateChat::~MigrateChat()
{

}
}//end namespace block
