#include "../Public/MsgsStateInfo.h"


//begin namespace block
namespace COMMON
{

MsgsStateInfo::MsgsStateInfo()
{
	this->_ConstructorID = 2109070852;
}

MsgsStateInfo::MsgsStateInfo(unsigned long long req_msg_id, FString info)
{
	this->_ConstructorID = 2109070852;
	this->req_msg_id = req_msg_id;
	this->info = info;
}
void MsgsStateInfo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->req_msg_id);
	Writer.TGWriteString(this->info);
}


void MsgsStateInfo::OnResponce(BinaryReader& Reader)
{
	req_msg_id = Reader.ReadLong();
	info = Reader.TGReadString();
}
MsgsStateInfo::~MsgsStateInfo()
{

}
}//end namespace block
