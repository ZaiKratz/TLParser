#include "../Public/PeerChat.h"


//begin namespace block
namespace COMMON
{

PeerChat::PeerChat()
{
	this->_ConstructorID = -1160714821;
}

PeerChat::PeerChat(int32 chat_id)
{
	this->_ConstructorID = -1160714821;
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
	this->_Responded = true;
}
PeerChat::~PeerChat()
{
}
}//end namespace block
