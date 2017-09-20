#include "../Public/MsgResendReq.h"


//begin namespace block
namespace COMMON
{

MsgResendReq::MsgResendReq()
{
	this->_ConstructorID = 135956093;
}

MsgResendReq::MsgResendReq(TArray<unsigned long long> msg_ids)
{
	this->_ConstructorID = 135956093;
	this->msg_ids = msg_ids;
}
void MsgResendReq::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->msg_ids.Num());
	for(auto X : this->msg_ids)
	{
	Writer.WriteLong(X);
	}
}


void MsgResendReq::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len6461 = Reader.ReadInt();
	for(int32 i = 0; i < Len6461; i++)
	{
	auto X = Reader.ReadLong();
	msg_ids.Add(X);
	}
}
MsgResendReq::~MsgResendReq()
{

}
}//end namespace block
