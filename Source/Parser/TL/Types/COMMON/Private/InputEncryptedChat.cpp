#include "../Public/InputEncryptedChat.h"


//begin namespace block
namespace COMMON
{

InputEncryptedChat::InputEncryptedChat()
{
	this->_ConstructorID = -247351839;
}

InputEncryptedChat::InputEncryptedChat(int32 chat_id, unsigned long long access_hash)
{
	this->_ConstructorID = -247351839;
	this->chat_id = chat_id;
	this->access_hash = access_hash;
}
void InputEncryptedChat::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
	Writer.WriteLong(this->access_hash);
}


void InputEncryptedChat::OnResponce(BinaryReader& Reader)
{
	chat_id = Reader.ReadInt();
	access_hash = Reader.ReadLong();
	this->_Responded = true;
}
InputEncryptedChat::~InputEncryptedChat()
{
}
}//end namespace block
