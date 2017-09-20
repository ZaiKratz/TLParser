#include "../Public/UpdateChannelMessageViews.h"


//begin namespace block
namespace COMMON
{

UpdateChannelMessageViews::UpdateChannelMessageViews()
{
	this->_ConstructorID = 1261150616;
}

UpdateChannelMessageViews::UpdateChannelMessageViews(int32 channel_id, int32 id, int32 views)
{
	this->_ConstructorID = 1261150616;
	this->channel_id = channel_id;
	this->id = id;
	this->views = views;
}
void UpdateChannelMessageViews::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->channel_id);
	Writer.WriteInt(this->id);
	Writer.WriteInt(this->views);
}


void UpdateChannelMessageViews::OnResponce(BinaryReader& Reader)
{
	channel_id = Reader.ReadInt();
	id = Reader.ReadInt();
	views = Reader.ReadInt();
}
UpdateChannelMessageViews::~UpdateChannelMessageViews()
{

}
}//end namespace block
