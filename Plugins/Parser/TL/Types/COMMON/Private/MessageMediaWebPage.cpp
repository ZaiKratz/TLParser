#include "../Public/MessageMediaWebPage.h"


//begin namespace block
namespace COMMON
{

MessageMediaWebPage::MessageMediaWebPage()
{
	this->_ConstructorID = 14036387;
}

MessageMediaWebPage::MessageMediaWebPage(COMMON::WebPage* webpage)
{
	this->_ConstructorID = 14036387;
	this->webpage = webpage;
}
void MessageMediaWebPage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->webpage->OnSend(Writer);
}


void MessageMediaWebPage::OnResponce(BinaryReader& Reader)
{
	webpage = reinterpret_cast<COMMON::WebPage*>(Reader.TGReadObject());
}
MessageMediaWebPage::~MessageMediaWebPage()
{

}
}//end namespace block
