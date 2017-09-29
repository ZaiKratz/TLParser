#include "../Public/UpdateDraftMessage.h"


//begin namespace block
namespace COMMON
{

UpdateDraftMessage::UpdateDraftMessage()
{
	this->_ConstructorID = -299124375;
}

UpdateDraftMessage::UpdateDraftMessage(PRIVATE::Peer*  peer, COMMON::DraftMessage*  draft)
{
	this->_ConstructorID = -299124375;
	this->peer = peer;
	this->draft = draft;
}
void UpdateDraftMessage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	this->draft->OnSend(Writer);
}


void UpdateDraftMessage::OnResponce(BinaryReader& Reader)
{
	peer = reinterpret_cast<PRIVATE::Peer* >(Reader.TGReadObject());
	draft = reinterpret_cast<COMMON::DraftMessage* >(Reader.TGReadObject());
	this->_Responded = true;
}
UpdateDraftMessage::~UpdateDraftMessage()
{

}
}//end namespace block