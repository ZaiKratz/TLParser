#include "../Public/WebPageEmpty.h"


//begin namespace block
namespace COMMON
{

WebPageEmpty::WebPageEmpty()
{
	this->_ConstructorID = -394849045;
}

WebPageEmpty::WebPageEmpty(unsigned long long id)
{
	this->_ConstructorID = -394849045;
	this->id = id;
}
void WebPageEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
}


void WebPageEmpty::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
}
WebPageEmpty::~WebPageEmpty()
{

}
}//end namespace block
