#include "../Public/State.h"


//begin namespace block
namespace UPDATES
{

State::State()
{
	this->_ConstructorID = -1519637954;
}

State::State(int32 pts, int32 qts, FDateTime date, int32 seq, int32 unread_count)
{
	this->_ConstructorID = -1519637954;
	this->pts = pts;
	this->qts = qts;
	this->date = date;
	this->seq = seq;
	this->unread_count = unread_count;
}
void State::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->pts);
	Writer.WriteInt(this->qts);
	Writer.TGWriteDate(this->date);
	Writer.WriteInt(this->seq);
	Writer.WriteInt(this->unread_count);
}


void State::OnResponce(BinaryReader& Reader)
{
	pts = Reader.ReadInt();
	qts = Reader.ReadInt();
	date = Reader.TGReadDate();
	seq = Reader.ReadInt();
	unread_count = Reader.ReadInt();
	this->_Responded = true;
}
State::~State()
{

}
}//end namespace block
