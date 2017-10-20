#include "../Public/AffectedMessages.h"


//begin namespace block
namespace MESSAGES
{

AffectedMessages::AffectedMessages()
{
	this->_ConstructorID = -2066640507;
}

AffectedMessages::AffectedMessages(int32 pts, int32 pts_count)
{
	this->_ConstructorID = -2066640507;
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
	this->_Responded = true;
}
AffectedMessages::~AffectedMessages()
{
}
}//end namespace block
