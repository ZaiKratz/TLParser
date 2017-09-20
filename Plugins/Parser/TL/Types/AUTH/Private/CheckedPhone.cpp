#include "../Public/CheckedPhone.h"


//begin namespace block
namespace AUTH
{

CheckedPhone::CheckedPhone()
{
	this->_ConstructorID = -1901977983;
}

CheckedPhone::CheckedPhone(bool phone_registered)
{
	this->_ConstructorID = -1901977983;
	this->phone_registered = phone_registered;
}
void CheckedPhone::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteBool(this->phone_registered);
}


void CheckedPhone::OnResponce(BinaryReader& Reader)
{
	phone_registered = Reader.ReadBool();
}
CheckedPhone::~CheckedPhone()
{

}
}//end namespace block
