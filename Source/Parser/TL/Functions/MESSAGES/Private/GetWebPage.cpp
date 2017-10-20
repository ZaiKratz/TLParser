#include "../Public/GetWebPage.h"


//begin namespace block
namespace MESSAGES
{

GetWebPage::GetWebPage()
{
	this->_ConstructorID = 852135825;
	this->_ContentRelated = true;
}

GetWebPage::GetWebPage(FString url, int32 hash)
{
	this->_ConstructorID = 852135825;
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
	this->_Responded = true;
}
GetWebPage::~GetWebPage()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
