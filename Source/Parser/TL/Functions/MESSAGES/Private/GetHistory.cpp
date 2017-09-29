#include "../Public/GetHistory.h"


//begin namespace block
namespace MESSAGES
{

GetHistory::GetHistory()
{
	this->_ConstructorID = -1347868602;
	this->_ContentRelated = true;
}

GetHistory::GetHistory(PRIVATE::InputPeer*  peer, int32 offset_id, FDateTime offset_date, int32 add_offset, int32 limit, int32 max_id, int32 min_id)
{
	this->_ConstructorID = -1347868602;
	this->_ContentRelated = true;
	this->peer = peer;
	this->offset_id = offset_id;
	this->offset_date = offset_date;
	this->add_offset = add_offset;
	this->limit = limit;
	this->max_id = max_id;
	this->min_id = min_id;
}
void GetHistory::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.WriteInt(this->offset_id);
	Writer.TGWriteDate(this->offset_date);
	Writer.WriteInt(this->add_offset);
	Writer.WriteInt(this->limit);
	Writer.WriteInt(this->max_id);
	Writer.WriteInt(this->min_id);
}


void GetHistory::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::Messages*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetHistory::~GetHistory()
{

}
}//end namespace block
