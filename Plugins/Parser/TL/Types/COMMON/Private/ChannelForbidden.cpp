#include "../Public/ChannelForbidden.h"


//begin namespace block
namespace COMMON
{

ChannelForbidden::ChannelForbidden()
{
	this->_ConstructorID = 849845544;
}

ChannelForbidden::ChannelForbidden(bool broadcast, bool megagroup, int32 id, unsigned long long access_hash, FString title, FDateTime until_date)
{
	this->_ConstructorID = 849845544;
	this->broadcast = broadcast;
	this->megagroup = megagroup;
	this->id = id;
	this->access_hash = access_hash;
	this->title = title;
	this->until_date = until_date;
}
void ChannelForbidden::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!broadcast)
	{
		Flags |= (1 << 5);
	}
	else
	{
		Flags |= 0;
	}
	if(!megagroup)
	{
		Flags |= (1 << 8);
	}
	else
	{
		Flags |= 0;
	}
	if(!until_date.ToString().IsEmpty())
	{
		Flags |= (1 << 16);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->id);
	Writer.WriteLong(this->access_hash);
	Writer.TGWriteString(this->title);
	if(!until_date.ToString().IsEmpty())
	{
	Writer.TGWriteDate(this->until_date);
	}
}


void ChannelForbidden::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 5)) != 0) 
	{
		broadcast = true;
	}
	if((Flags & (1 << 8)) != 0) 
	{
		megagroup = true;
	}
	id = Reader.ReadInt();
	access_hash = Reader.ReadLong();
	title = Reader.TGReadString();
	if((Flags & (1 << 16)) != 0) 
	{
	until_date = Reader.TGReadDate();
	}
}
ChannelForbidden::~ChannelForbidden()
{

}
}//end namespace block
