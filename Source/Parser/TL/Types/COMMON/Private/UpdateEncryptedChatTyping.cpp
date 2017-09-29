#include "../Public/UpdateEncryptedChatTyping.h"


//begin namespace block
namespace COMMON
{

UpdateEncryptedChatTyping::UpdateEncryptedChatTyping()
{
	this->_ConstructorID = 386986326;
}

UpdateEncryptedChatTyping::UpdateEncryptedChatTyping(int32 chat_id)
{
	this->_ConstructorID = 386986326;
	this->chat_id = chat_id;
}
void UpdateEncryptedChatTyping::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
}


void UpdateEncryptedChatTyping::OnResponce(BinaryReader& Reader)
{
	chat_id = Reader.ReadInt();
	this->_Responded = true;
}
UpdateEncryptedChatTyping::~UpdateEncryptedChatTyping()
{

}
}//end namespace block
