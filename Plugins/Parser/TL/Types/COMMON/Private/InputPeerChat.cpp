#include "../Public/InputPeerChat.h"


//begin namespace block
namespace COMMON
{

InputPeerChat::InputPeerChat()
{
	this->_ConstructorID = 1676188439;
}

InputPeerChat::InputPeerChat(int32 chat_id)
{
	this->_ConstructorID = 1676188439;
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
}
InputPeerChat::~InputPeerChat()
{

}
}//end namespace block
