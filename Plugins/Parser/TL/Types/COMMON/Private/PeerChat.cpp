#include "../Public/PeerChat.h"


//begin namespace block
namespace COMMON
{

PeerChat::PeerChat()
{
	this->_ConstructorID = -1142566726;
}

PeerChat::PeerChat(int32 chat_id)
{
	this->_ConstructorID = -1142566726;
	this->chat_id = chat_id;
}
void PeerChat::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
}


void PeerChat::OnResponce(BinaryReader& Reader)
{
	chat_id = Reader.ReadInt();
}
PeerChat::~PeerChat()
{

}
}//end namespace block
