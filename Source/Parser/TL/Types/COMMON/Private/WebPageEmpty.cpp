#include "../Public/WebPageEmpty.h"


//begin namespace block
namespace COMMON
{

WebPageEmpty::WebPageEmpty()
{
	this->_ConstructorID = -350980120;
}

WebPageEmpty::WebPageEmpty(unsigned long long id)
{
	this->_ConstructorID = -350980120;
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
	this->_Responded = true;
}
WebPageEmpty::~WebPageEmpty()
{
}
}//end namespace block
