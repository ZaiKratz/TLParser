#include "../Public/InputPhoneCall.h"


//begin namespace block
namespace COMMON
{

InputPhoneCall::InputPhoneCall()
{
	this->_ConstructorID = -302172642;
}

InputPhoneCall::InputPhoneCall(unsigned long long id, unsigned long long access_hash)
{
	this->_ConstructorID = -302172642;
	this->id = id;
	this->access_hash = access_hash;
}
void InputPhoneCall::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.WriteLong(this->access_hash);
}


void InputPhoneCall::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	access_hash = Reader.ReadLong();
}
InputPhoneCall::~InputPhoneCall()
{

}
}//end namespace block
