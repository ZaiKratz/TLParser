#include "../Public/WebPageNotModified.h"


//begin namespace block
namespace COMMON
{

WebPageNotModified::WebPageNotModified()
{
	this->_ConstructorID = 1939113093;
}
void WebPageNotModified::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void WebPageNotModified::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
WebPageNotModified::~WebPageNotModified()
{

}
}//end namespace block
