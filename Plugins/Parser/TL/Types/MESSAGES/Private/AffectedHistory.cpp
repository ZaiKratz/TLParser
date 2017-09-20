#include "../Public/AffectedHistory.h"


//begin namespace block
namespace MESSAGES
{

AffectedHistory::AffectedHistory()
{
	this->_ConstructorID = -781624140;
}

AffectedHistory::AffectedHistory(int32 pts, int32 pts_count, int32 offset)
{
	this->_ConstructorID = -781624140;
	this->pts = pts;
	this->pts_count = pts_count;
	this->offset = offset;
}
void AffectedHistory::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->pts);
	Writer.WriteInt(this->pts_count);
	Writer.WriteInt(this->offset);
}


void AffectedHistory::OnResponce(BinaryReader& Reader)
{
	pts = Reader.ReadInt();
	pts_count = Reader.ReadInt();
	offset = Reader.ReadInt();
}
AffectedHistory::~AffectedHistory()
{

}
}//end namespace block
