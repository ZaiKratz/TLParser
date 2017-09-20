#include "../Public/SetTyping.h"


//begin namespace block
namespace MESSAGES
{

SetTyping::SetTyping()
{
	this->_ConstructorID = 1348371107;
	this->_ContentRelated = true;
}

SetTyping::SetTyping(PRIVATE::InputPeer* peer, PRIVATE::SendMessageAction* action)
{
	this->_ConstructorID = 1348371107;
	this->_ContentRelated = true;
	this->peer = peer;
	this->action = action;
}
void SetTyping::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	this->action->OnSend(Writer);
}


void SetTyping::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
}
SetTyping::~SetTyping()
{

}
}//end namespace block
