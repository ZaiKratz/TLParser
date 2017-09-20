#include "../Public/FutureSalts.h"


//begin namespace block
namespace COMMON
{

FutureSalts::FutureSalts()
{
	this->_ConstructorID = -1794617170;
}

FutureSalts::FutureSalts(unsigned long long req_msg_id, int32 now, TArray<COMMON::FutureSalt*> salts)
{
	this->_ConstructorID = -1794617170;
	this->req_msg_id = req_msg_id;
	this->now = now;
	this->salts = salts;
}
void FutureSalts::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->req_msg_id);
	Writer.WriteInt(this->now);
	Writer.WriteInt(this->salts.Num());
	for(auto X : this->salts)
	{
	X->OnSend(Writer);
	}
}


void FutureSalts::OnResponce(BinaryReader& Reader)
{
	req_msg_id = Reader.ReadLong();
	now = Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len10130 = Reader.ReadInt();
	for(int32 i = 0; i < Len10130; i++)
	{
	auto X = reinterpret_cast<COMMON::FutureSalt*>(Reader.TGReadObject());
	salts.Add(X);
	}
}
FutureSalts::~FutureSalts()
{

}
}//end namespace block