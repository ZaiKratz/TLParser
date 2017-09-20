#include "../Public/SearchGlobal.h"


//begin namespace block
namespace MESSAGES
{

SearchGlobal::SearchGlobal()
{
	this->_ConstructorID = -1330889570;
	this->_ContentRelated = true;
}

SearchGlobal::SearchGlobal(FString q, FDateTime offset_date, PRIVATE::InputPeer* offset_peer, int32 offset_id, int32 limit)
{
	this->_ConstructorID = -1330889570;
	this->_ContentRelated = true;
	this->q = q;
	this->offset_date = offset_date;
	this->offset_peer = offset_peer;
	this->offset_id = offset_id;
	this->limit = limit;
}
void SearchGlobal::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->q);
	Writer.TGWriteDate(this->offset_date);
	this->offset_peer->OnSend(Writer);
	Writer.WriteInt(this->offset_id);
	Writer.WriteInt(this->limit);
}


void SearchGlobal::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::Messages*>(Reader.TGReadObject());
}
SearchGlobal::~SearchGlobal()
{

}
}//end namespace block
