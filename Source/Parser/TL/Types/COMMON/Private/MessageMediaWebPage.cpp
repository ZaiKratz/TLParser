#include "../Public/MessageMediaWebPage.h"


//begin namespace block
namespace COMMON
{

MessageMediaWebPage::MessageMediaWebPage()
{
	this->_ConstructorID = -1557277184;
}

MessageMediaWebPage::MessageMediaWebPage(COMMON::WebPage*  webpage)
{
	this->_ConstructorID = -1557277184;
	this->webpage = webpage;
}
void MessageMediaWebPage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->webpage->OnSend(Writer);
}


void MessageMediaWebPage::OnResponce(BinaryReader& Reader)
{
	webpage = reinterpret_cast<COMMON::WebPage* >(Reader.TGReadObject());
	this->_Responded = true;
}
MessageMediaWebPage::~MessageMediaWebPage()
{

}
}//end namespace block
