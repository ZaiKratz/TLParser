#include "../Public/UpdateReadHistoryOutbox.h"


//begin namespace block
namespace COMMON
{

UpdateReadHistoryOutbox::UpdateReadHistoryOutbox()
{
	this->_ConstructorID = 791617983;
}

UpdateReadHistoryOutbox::UpdateReadHistoryOutbox(PRIVATE::Peer*  peer, int32 max_id, int32 pts, int32 pts_count)
{
	this->_ConstructorID = 791617983;
	this->peer = peer;
	this->max_id = max_id;
	this->pts = pts;
	this->pts_count = pts_count;
}
void UpdateReadHistoryOutbox::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.WriteInt(this->max_id);
	Writer.WriteInt(this->pts);
	Writer.WriteInt(this->pts_count);
}


void UpdateReadHistoryOutbox::OnResponce(BinaryReader& Reader)
{
	peer = reinterpret_cast<PRIVATE::Peer* >(Reader.TGReadObject());
	max_id = Reader.ReadInt();
	pts = Reader.ReadInt();
	pts_count = Reader.ReadInt();
	this->_Responded = true;
}
UpdateReadHistoryOutbox::~UpdateReadHistoryOutbox()
{

}
}//end namespace block
