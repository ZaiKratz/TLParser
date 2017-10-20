#include "../Public/MsgsAck.h"


//begin namespace block
namespace COMMON
{

MsgsAck::MsgsAck()
{
	this->_ConstructorID = 1658238041;
}

MsgsAck::MsgsAck(TArray<unsigned long long>  msg_ids)
{
	this->_ConstructorID = 1658238041;
	this->msg_ids = msg_ids;
}
void MsgsAck::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->msg_ids.Num());
	for(auto X : this->msg_ids)
	{
	Writer.WriteLong(X);
	}
}


void MsgsAck::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len7871 = Reader.ReadInt();
	for(int32 i = 0; i < Len7871; i++)
	{
	auto X = Reader.ReadLong();
	msg_ids.Add(X);
	}
	this->_Responded = true;
}
MsgsAck::~MsgsAck()
{
}
}//end namespace block
