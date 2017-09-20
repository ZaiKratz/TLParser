#include "../Public/PhoneCallEmpty.h"


//begin namespace block
namespace COMMON
{

PhoneCallEmpty::PhoneCallEmpty()
{
	this->_ConstructorID = 365520467;
}

PhoneCallEmpty::PhoneCallEmpty(unsigned long long id)
{
	this->_ConstructorID = 365520467;
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
}
PhoneCallEmpty::~PhoneCallEmpty()
{

}
}//end namespace block
