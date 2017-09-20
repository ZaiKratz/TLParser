#include "../Public/AffectedMessages.h"


//begin namespace block
namespace MESSAGES
{

AffectedMessages::AffectedMessages()
{
	this->_ConstructorID = -2054041212;
}

AffectedMessages::AffectedMessages(int32 pts, int32 pts_count)
{
	this->_ConstructorID = -2054041212;
	this->pts = pts;
	this->pts_count = pts_count;
}
void AffectedMessages::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->pts);
	Writer.WriteInt(this->pts_count);
}


void AffectedMessages::OnResponce(BinaryReader& Reader)
{
	pts = Reader.ReadInt();
	pts_count = Reader.ReadInt();
}
AffectedMessages::~AffectedMessages()
{

}
}//end namespace block
