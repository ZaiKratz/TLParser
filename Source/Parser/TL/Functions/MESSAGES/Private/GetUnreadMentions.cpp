#include "../Public/GetUnreadMentions.h"


//begin namespace block
namespace MESSAGES
{

GetUnreadMentions::GetUnreadMentions()
{
	this->_ConstructorID = 1180140658;
	this->_ContentRelated = true;
}

GetUnreadMentions::GetUnreadMentions(TLBaseObject*  peer, int32 offset_id, int32 add_offset, int32 limit, int32 max_id, int32 min_id)
{
	this->_ConstructorID = 1180140658;
	this->_ContentRelated = true;
	this->peer = peer;
	this->offset_id = offset_id;
	this->add_offset = add_offset;
	this->limit = limit;
	this->max_id = max_id;
	this->min_id = min_id;
}
void GetUnreadMentions::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.WriteInt(this->offset_id);
	Writer.WriteInt(this->add_offset);
	Writer.WriteInt(this->limit);
	Writer.WriteInt(this->max_id);
	Writer.WriteInt(this->min_id);
}


void GetUnreadMentions::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::Messages*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetUnreadMentions::~GetUnreadMentions()
{
	if(this->peer)
	{
		delete this->peer;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
