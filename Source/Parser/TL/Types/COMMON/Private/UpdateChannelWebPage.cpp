#include "../Public/UpdateChannelWebPage.h"


//begin namespace block
namespace COMMON
{

UpdateChannelWebPage::UpdateChannelWebPage()
{
	this->_ConstructorID = 1081547008;
}

UpdateChannelWebPage::UpdateChannelWebPage(int32 channel_id, COMMON::WebPage*  webpage, int32 pts, int32 pts_count)
{
	this->_ConstructorID = 1081547008;
	this->channel_id = channel_id;
	this->webpage = webpage;
	this->pts = pts;
	this->pts_count = pts_count;
}
void UpdateChannelWebPage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->channel_id);
	this->webpage->OnSend(Writer);
	Writer.WriteInt(this->pts);
	Writer.WriteInt(this->pts_count);
}


void UpdateChannelWebPage::OnResponce(BinaryReader& Reader)
{
	channel_id = Reader.ReadInt();
	webpage = reinterpret_cast<COMMON::WebPage* >(Reader.TGReadObject());
	pts = Reader.ReadInt();
	pts_count = Reader.ReadInt();
	this->_Responded = true;
}
UpdateChannelWebPage::~UpdateChannelWebPage()
{
	if(this->webpage)
	{
		delete this->webpage;
	}
}
}//end namespace block
