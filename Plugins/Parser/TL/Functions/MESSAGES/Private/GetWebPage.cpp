#include "../Public/GetWebPage.h"


//begin namespace block
namespace MESSAGES
{

GetWebPage::GetWebPage()
{
	this->_ConstructorID = -1852847566;
	this->_ContentRelated = true;
}

GetWebPage::GetWebPage(FString url, int32 hash)
{
	this->_ConstructorID = -1852847566;
	this->_ContentRelated = true;
	this->url = url;
	this->hash = hash;
}
void GetWebPage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->url);
	Writer.WriteInt(this->hash);
}


void GetWebPage::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::WebPage*>(Reader.TGReadObject());
}
GetWebPage::~GetWebPage()
{

}
}//end namespace block
