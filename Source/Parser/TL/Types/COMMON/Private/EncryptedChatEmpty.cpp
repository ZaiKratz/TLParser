#include "../Public/EncryptedChatEmpty.h"


//begin namespace block
namespace COMMON
{

EncryptedChatEmpty::EncryptedChatEmpty()
{
	this->_ConstructorID = -1417756512;
}

EncryptedChatEmpty::EncryptedChatEmpty(int32 id)
{
	this->_ConstructorID = -1417756512;
	this->id = id;
}
void EncryptedChatEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->id);
}


void EncryptedChatEmpty::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadInt();
	this->_Responded = true;
}
EncryptedChatEmpty::~EncryptedChatEmpty()
{
}
}//end namespace block
