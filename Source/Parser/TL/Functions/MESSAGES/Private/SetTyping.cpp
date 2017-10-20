#include "../Public/SetTyping.h"


//begin namespace block
namespace MESSAGES
{

SetTyping::SetTyping()
{
	this->_ConstructorID = -1551737264;
	this->_ContentRelated = true;
}

SetTyping::SetTyping(TLBaseObject*  peer, TLBaseObject*  action)
{
	this->_ConstructorID = -1551737264;
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
	this->_Responded = true;
}
SetTyping::~SetTyping()
{
	if(this->peer)
	{
		delete this->peer;
	}
	if(this->action)
	{
		delete this->action;
	}
}
}//end namespace block
