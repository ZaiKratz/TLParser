#include "../Public/UpdatePhoneCall.h"


//begin namespace block
namespace COMMON
{

UpdatePhoneCall::UpdatePhoneCall()
{
	this->_ConstructorID = -1425052898;
}

UpdatePhoneCall::UpdatePhoneCall(COMMON::PhoneCall*  phone_call)
{
	this->_ConstructorID = -1425052898;
	this->phone_call = phone_call;
}
void UpdatePhoneCall::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->phone_call->OnSend(Writer);
}


void UpdatePhoneCall::OnResponce(BinaryReader& Reader)
{
	phone_call = reinterpret_cast<COMMON::PhoneCall* >(Reader.TGReadObject());
	this->_Responded = true;
}
UpdatePhoneCall::~UpdatePhoneCall()
{

}
}//end namespace block
