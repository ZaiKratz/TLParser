#include "../Public/Search.h"


//begin namespace block
namespace MESSAGES
{

Search::Search()
{
	this->_ConstructorID = 60726944;
	this->_ContentRelated = true;
}

Search::Search(TLBaseObject*  peer, FString q, COMMON::InputUser*  from_id, TLBaseObject*  filter, FDateTime min_date, FDateTime max_date, int32 offset_id, int32 add_offset, int32 limit, int32 max_id, int32 min_id)
{
	this->_ConstructorID = 60726944;
	this->_ContentRelated = true;
	this->peer = peer;
	this->q = q;
	this->from_id = from_id;
	this->filter = filter;
	this->min_date = min_date;
	this->max_date = max_date;
	this->offset_id = offset_id;
	this->add_offset = add_offset;
	this->limit = limit;
	this->max_id = max_id;
	this->min_id = min_id;
}
void Search::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(from_id)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->peer->OnSend(Writer);
	Writer.TGWriteString(this->q);
	if(this->from_id)
	{
	this->from_id->OnSend(Writer);
	}
	this->filter->OnSend(Writer);
	Writer.TGWriteDate(this->min_date);
	Writer.TGWriteDate(this->max_date);
	Writer.WriteInt(this->offset_id);
	Writer.WriteInt(this->add_offset);
	Writer.WriteInt(this->limit);
	Writer.WriteInt(this->max_id);
	Writer.WriteInt(this->min_id);
}


void Search::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::Messages*>(Reader.TGReadObject());
	this->_Responded = true;
}
Search::~Search()
{
	if(this->peer)
	{
		delete this->peer;
	}
	if(this->from_id)
	{
		delete this->from_id;
	}
	if(this->filter)
	{
		delete this->filter;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
