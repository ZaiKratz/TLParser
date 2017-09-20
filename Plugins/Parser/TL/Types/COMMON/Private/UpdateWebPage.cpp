#include "../Public/UpdateWebPage.h"


//begin namespace block
namespace COMMON
{

UpdateWebPage::UpdateWebPage()
{
	this->_ConstructorID = 319981951;
}

UpdateWebPage::UpdateWebPage(COMMON::WebPage* webpage, int32 pts, int32 pts_count)
{
	this->_ConstructorID = 319981951;
	this->webpage = webpage;
	this->pts = pts;
	this->pts_count = pts_count;
}
void UpdateWebPage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->webpage->OnSend(Writer);
	Writer.WriteInt(this->pts);
	Writer.WriteInt(this->pts_count);
}


void UpdateWebPage::OnResponce(BinaryReader& Reader)
{
	webpage = reinterpret_cast<COMMON::WebPage*>(Reader.TGReadObject());
	pts = Reader.ReadInt();
	pts_count = Reader.ReadInt();
}
UpdateWebPage::~UpdateWebPage()
{

}
}//end namespace block
