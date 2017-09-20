#include "../Public/MsgsStateReq.h"


//begin namespace block
namespace COMMON
{

MsgsStateReq::MsgsStateReq()
{
	this->_ConstructorID = 1392208346;
}

MsgsStateReq::MsgsStateReq(TArray<unsigned long long> msg_ids)
{
	this->_ConstructorID = 1392208346;
	this->msg_ids = msg_ids;
}
void MsgsStateReq::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->msg_ids.Num());
	for(auto X : this->msg_ids)
	{
	Writer.WriteLong(X);
	}
}


void MsgsStateReq::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len7673 = Reader.ReadInt();
	for(int32 i = 0; i < Len7673; i++)
	{
	auto X = Reader.ReadLong();
	msg_ids.Add(X);
	}
}
MsgsStateReq::~MsgsStateReq()
{

}
}//end namespace block
