#include "../Public/ReceivedCall.h"


//begin namespace block
namespace PHONE
{

ReceivedCall::ReceivedCall()
{
	this->_ConstructorID = 1632621847;
	this->_ContentRelated = true;
}

ReceivedCall::ReceivedCall(COMMON::InputPhoneCall* peer)
{
	this->_ConstructorID = 1632621847;
	this->_ContentRelated = true;
	this->peer = peer;
}
void ReceivedCall::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
}


void ReceivedCall::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
}
ReceivedCall::~ReceivedCall()
{

}
}//end namespace block
