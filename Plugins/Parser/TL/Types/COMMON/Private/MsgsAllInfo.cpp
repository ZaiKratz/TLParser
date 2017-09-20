#include "../Public/MsgsAllInfo.h"


//begin namespace block
namespace COMMON
{

MsgsAllInfo::MsgsAllInfo()
{
	this->_ConstructorID = 835829900;
}

MsgsAllInfo::MsgsAllInfo(TArray<unsigned long long> msg_ids, FString info)
{
	this->_ConstructorID = 835829900;
	this->msg_ids = msg_ids;
	this->info = info;
}
void MsgsAllInfo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->msg_ids.Num());
	for(auto X : this->msg_ids)
	{
	Writer.WriteLong(X);
	}
	Writer.TGWriteString(this->info);
}


void MsgsAllInfo::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len24143 = Reader.ReadInt();
	for(int32 i = 0; i < Len24143; i++)
	{
	auto X = Reader.ReadLong();
	msg_ids.Add(X);
	}
	info = Reader.TGReadString();
}
MsgsAllInfo::~MsgsAllInfo()
{

}
}//end namespace block
