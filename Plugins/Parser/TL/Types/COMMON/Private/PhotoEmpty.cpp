#include "../Public/PhotoEmpty.h"


//begin namespace block
namespace COMMON
{

PhotoEmpty::PhotoEmpty()
{
	this->_ConstructorID = 766652707;
}

PhotoEmpty::PhotoEmpty(unsigned long long id)
{
	this->_ConstructorID = 766652707;
	this->id = id;
}
void PhotoEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
}


void PhotoEmpty::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
}
PhotoEmpty::~PhotoEmpty()
{

}
}//end namespace block
