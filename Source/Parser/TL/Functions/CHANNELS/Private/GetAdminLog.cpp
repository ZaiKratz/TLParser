#include "../Public/GetAdminLog.h"


//begin namespace block
namespace CHANNELS
{

GetAdminLog::GetAdminLog()
{
	this->_ConstructorID = 870184064;
	this->_ContentRelated = true;
}

GetAdminLog::GetAdminLog(COMMON::InputChannel*  channel, FString q, COMMON::ChannelAdminLogEventsFilter*  events_filter, TArray<COMMON::InputUser*>  admins, unsigned long long max_id, unsigned long long min_id, int32 limit)
{
	this->_ConstructorID = 870184064;
	this->_ContentRelated = true;
	this->channel = channel;
	this->q = q;
	this->events_filter = events_filter;
	this->admins = admins;
	this->max_id = max_id;
	this->min_id = min_id;
	this->limit = limit;
}
void GetAdminLog::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(events_filter)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(admins.Num())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->channel->OnSend(Writer);
	Writer.TGWriteString(this->q);
	if(!this->events_filter)
	{
	this->events_filter->OnSend(Writer);
	}
	if(this->admins.Num())
	{
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->admins.Num());
	for(auto X : this->admins)
	{
	if(!X)
	{
	X->OnSend(Writer);
	}
	}
	}
	Writer.WriteLong(this->max_id);
	Writer.WriteLong(this->min_id);
	Writer.WriteInt(this->limit);
}


void GetAdminLog::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<CHANNELS::AdminLogResults*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetAdminLog::~GetAdminLog()
{

}
}//end namespace block
