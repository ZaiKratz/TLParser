#include "../Public/DocumentEmpty.h"


//begin namespace block
namespace COMMON
{

DocumentEmpty::DocumentEmpty()
{
	this->_ConstructorID = 1908996150;
}

DocumentEmpty::DocumentEmpty(unsigned long long id)
{
	this->_ConstructorID = 1908996150;
	this->id = id;
}
void DocumentEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
}


void DocumentEmpty::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
}
DocumentEmpty::~DocumentEmpty()
{

}
}//end namespace block
