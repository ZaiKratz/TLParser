#include "../Public/ChannelAdminLogEventsFilter.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventsFilter::ChannelAdminLogEventsFilter()
{
	this->_ConstructorID = -461762326;
}

ChannelAdminLogEventsFilter::ChannelAdminLogEventsFilter(bool join, bool leave, bool invite, bool ban, bool unban, bool kick, bool unkick, bool promote, bool demote, bool info, bool settings, bool pinned, bool edit, bool Delete)
{
	this->_ConstructorID = -461762326;
	this->join = join;
	this->leave = leave;
	this->invite = invite;
	this->ban = ban;
	this->unban = unban;
	this->kick = kick;
	this->unkick = unkick;
	this->promote = promote;
	this->demote = demote;
	this->info = info;
	this->settings = settings;
	this->pinned = pinned;
	this->edit = edit;
	this->Delete = Delete;
}
void ChannelAdminLogEventsFilter::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!join)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!leave)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!invite)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(!ban)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	if(!unban)
	{
		Flags |= (1 << 4);
	}
	else
	{
		Flags |= 0;
	}
	if(!kick)
	{
		Flags |= (1 << 5);
	}
	else
	{
		Flags |= 0;
	}
	if(!unkick)
	{
		Flags |= (1 << 6);
	}
	else
	{
		Flags |= 0;
	}
	if(!promote)
	{
		Flags |= (1 << 7);
	}
	else
	{
		Flags |= 0;
	}
	if(!demote)
	{
		Flags |= (1 << 8);
	}
	else
	{
		Flags |= 0;
	}
	if(!info)
	{
		Flags |= (1 << 9);
	}
	else
	{
		Flags |= 0;
	}
	if(!settings)
	{
		Flags |= (1 << 10);
	}
	else
	{
		Flags |= 0;
	}
	if(!pinned)
	{
		Flags |= (1 << 11);
	}
	else
	{
		Flags |= 0;
	}
	if(!edit)
	{
		Flags |= (1 << 12);
	}
	else
	{
		Flags |= 0;
	}
	if(!Delete)
	{
		Flags |= (1 << 13);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

}


void ChannelAdminLogEventsFilter::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		join = true;
	}
	if((Flags & (1 << 1)) != 0) 
	{
		leave = true;
	}
	if((Flags & (1 << 2)) != 0) 
	{
		invite = true;
	}
	if((Flags & (1 << 3)) != 0) 
	{
		ban = true;
	}
	if((Flags & (1 << 4)) != 0) 
	{
		unban = true;
	}
	if((Flags & (1 << 5)) != 0) 
	{
		kick = true;
	}
	if((Flags & (1 << 6)) != 0) 
	{
		unkick = true;
	}
	if((Flags & (1 << 7)) != 0) 
	{
		promote = true;
	}
	if((Flags & (1 << 8)) != 0) 
	{
		demote = true;
	}
	if((Flags & (1 << 9)) != 0) 
	{
		info = true;
	}
	if((Flags & (1 << 10)) != 0) 
	{
		settings = true;
	}
	if((Flags & (1 << 11)) != 0) 
	{
		pinned = true;
	}
	if((Flags & (1 << 12)) != 0) 
	{
		edit = true;
	}
	if((Flags & (1 << 13)) != 0) 
	{
		Delete = true;
	}
}
ChannelAdminLogEventsFilter::~ChannelAdminLogEventsFilter()
{

}
}//end namespace block
