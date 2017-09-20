#include "../Public/EncryptedChatDiscarded.h"


//begin namespace block
namespace COMMON
{

EncryptedChatDiscarded::EncryptedChatDiscarded()
{
	this->_ConstructorID = 668849683;
}

EncryptedChatDiscarded::EncryptedChatDiscarded(int32 id)
{
	this->_ConstructorID = 668849683;
	this->id = id;
}
void EncryptedChatDiscarded::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->id);
}


void EncryptedChatDiscarded::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadInt();
}
EncryptedChatDiscarded::~EncryptedChatDiscarded()
{

}
}//end namespace block
