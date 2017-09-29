#include "../Public/ForwardMessage.h"


//begin namespace block
namespace MESSAGES
{

ForwardMessage::ForwardMessage()
{
	this->_ConstructorID = 865483769;
	this->_ContentRelated = true;
}

ForwardMessage::ForwardMessage(PRIVATE::InputPeer*  peer, int32 id, unsigned long long random_id)
{
	this->_ConstructorID = 865483769;
	this->_ContentRelated = true;
	this->peer = peer;
	this->id = id;
	this->random_id = random_id;
}
void ForwardMessage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.WriteInt(this->id);
	Writer.WriteLong(this->random_id);
}


void ForwardMessage::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
ForwardMessage::~ForwardMessage()
{

}
}//end namespace block
