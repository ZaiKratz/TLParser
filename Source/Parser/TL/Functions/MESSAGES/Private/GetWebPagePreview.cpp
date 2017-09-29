#include "../Public/GetWebPagePreview.h"


//begin namespace block
namespace MESSAGES
{

GetWebPagePreview::GetWebPagePreview()
{
	this->_ConstructorID = 623001124;
	this->_ContentRelated = true;
}

GetWebPagePreview::GetWebPagePreview(FString message)
{
	this->_ConstructorID = 623001124;
	this->_ContentRelated = true;
	this->message = message;
}
void GetWebPagePreview::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->message);
}


void GetWebPagePreview::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<PRIVATE::MessageMedia*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetWebPagePreview::~GetWebPagePreview()
{

}
}//end namespace block
