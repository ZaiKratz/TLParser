#include "../Public/GetTopPeers.h"


//begin namespace block
namespace CONTACTS
{

GetTopPeers::GetTopPeers()
{
	this->_ConstructorID = -728224331;
	this->_ContentRelated = true;
}

GetTopPeers::GetTopPeers(bool correspondents, bool bots_pm, bool bots_inline, bool phone_calls, bool groups, bool channels, int32 offset, int32 limit, int32 hash)
{
	this->_ConstructorID = -728224331;
	this->_ContentRelated = true;
	this->correspondents = correspondents;
	this->bots_pm = bots_pm;
	this->bots_inline = bots_inline;
	this->phone_calls = phone_calls;
	this->groups = groups;
	this->channels = channels;
	this->offset = offset;
	this->limit = limit;
	this->hash = hash;
}
void GetTopPeers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(correspondents)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(bots_pm)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(bots_inline)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(phone_calls)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	if(groups)
	{
		Flags |= (1 << 10);
	}
	else
	{
		Flags |= 0;
	}
	if(channels)
	{
		Flags |= (1 << 15);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->limit);
	Writer.WriteInt(this->hash);
}


void GetTopPeers::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<CONTACTS::TopPeers*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetTopPeers::~GetTopPeers()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
