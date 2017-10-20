#include "../Public/WebPageNotModified.h"


//begin namespace block
namespace COMMON
{

WebPageNotModified::WebPageNotModified()
{
	this->_ConstructorID = -2054908813;
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
	this->_Responded = true;
}
WebPageNotModified::~WebPageNotModified()
{
}
}//end namespace block
