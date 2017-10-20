#include "../Public/InputPeerChat.h"


//begin namespace block
namespace COMMON
{

InputPeerChat::InputPeerChat()
{
	this->_ConstructorID = 396093539;
}

InputPeerChat::InputPeerChat(int32 chat_id)
{
	this->_ConstructorID = 396093539;
	this->chat_id = chat_id;
}
void InputPeerChat::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
}


void InputPeerChat::OnResponce(BinaryReader& Reader)
{
	chat_id = Reader.ReadInt();
	this->_Responded = true;
}
InputPeerChat::~InputPeerChat()
{
}
}//end namespace block
