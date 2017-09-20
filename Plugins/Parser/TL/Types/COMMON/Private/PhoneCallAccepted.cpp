#include "../Public/PhoneCallAccepted.h"


//begin namespace block
namespace COMMON
{

PhoneCallAccepted::PhoneCallAccepted()
{
	this->_ConstructorID = 1060962413;
}

PhoneCallAccepted::PhoneCallAccepted(unsigned long long id, unsigned long long access_hash, FDateTime date, int32 admin_id, int32 participant_id, TArray<uint8> g_b, COMMON::PhoneCallProtocol* protocol)
{
	this->_ConstructorID = 1060962413;
	this->id = id;
	this->access_hash = access_hash;
	this->date = date;
	this->admin_id = admin_id;
	this->participant_id = participant_id;
	this->g_b = g_b;
	this->protocol = protocol;
}
void PhoneCallAccepted::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.WriteLong(this->access_hash);
	Writer.TGWriteDate(this->date);
	Writer.WriteInt(this->admin_id);
	Writer.WriteInt(this->participant_id);
	Writer.TGWriteBytes((unsigned char*)this->g_b.GetData(), this->g_b.Num());
	this->protocol->OnSend(Writer);
}


void PhoneCallAccepted::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	access_hash = Reader.ReadLong();
	date = Reader.TGReadDate();
	admin_id = Reader.ReadInt();
	participant_id = Reader.ReadInt();
	g_b = Reader.TGReadBytes();
	protocol = reinterpret_cast<COMMON::PhoneCallProtocol*>(Reader.TGReadObject());
}
PhoneCallAccepted::~PhoneCallAccepted()
{

}
}//end namespace block
