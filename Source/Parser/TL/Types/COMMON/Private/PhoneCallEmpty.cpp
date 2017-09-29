#include "../Public/PhoneCallEmpty.h"


//begin namespace block
namespace COMMON
{

PhoneCallEmpty::PhoneCallEmpty()
{
	this->_ConstructorID = 1399245077;
}

PhoneCallEmpty::PhoneCallEmpty(unsigned long long id)
{
	this->_ConstructorID = 1399245077;
	this->id = id;
}
void PhoneCallEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
}


void PhoneCallEmpty::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	this->_Responded = true;
}
PhoneCallEmpty::~PhoneCallEmpty()
{

}
}//end namespace block
