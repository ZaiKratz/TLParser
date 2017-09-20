#include "../Public/PhoneCallRequested.h"


//begin namespace block
namespace COMMON
{

PhoneCallRequested::PhoneCallRequested()
{
	this->_ConstructorID = -467896701;
}

PhoneCallRequested::PhoneCallRequested(unsigned long long id, unsigned long long access_hash, FDateTime date, int32 admin_id, int32 participant_id, TArray<uint8> g_a_hash, COMMON::PhoneCallProtocol* protocol)
{
	this->_ConstructorID = -467896701;
	this->id = id;
	this->access_hash = access_hash;
	this->date = date;
	this->admin_id = admin_id;
	this->participant_id = participant_id;
	this->g_a_hash = g_a_hash;
	this->protocol = protocol;
}
void PhoneCallRequested::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.WriteLong(this->access_hash);
	Writer.TGWriteDate(this->date);
	Writer.WriteInt(this->admin_id);
	Writer.WriteInt(this->participant_id);
	Writer.TGWriteBytes((unsigned char*)this->g_a_hash.GetData(), this->g_a_hash.Num());
	this->protocol->OnSend(Writer);
}


void PhoneCallRequested::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	access_hash = Reader.ReadLong();
	date = Reader.TGReadDate();
	admin_id = Reader.ReadInt();
	participant_id = Reader.ReadInt();
	g_a_hash = Reader.TGReadBytes();
	protocol = reinterpret_cast<COMMON::PhoneCallProtocol*>(Reader.TGReadObject());
}
PhoneCallRequested::~PhoneCallRequested()
{

}
}//end namespace block
