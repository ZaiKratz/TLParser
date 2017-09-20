#include "../Public/PhoneCall.h"


//begin namespace block
namespace COMMON
{

PhoneCall::PhoneCall()
{
	this->_ConstructorID = 1739319039;
}

PhoneCall::PhoneCall(unsigned long long id, unsigned long long access_hash, FDateTime date, int32 admin_id, int32 participant_id, TArray<uint8> g_a_or_b, unsigned long long key_fingerprint, COMMON::PhoneCallProtocol* protocol, COMMON::PhoneConnection* connection, TArray<COMMON::PhoneConnection*> alternative_connections, FDateTime start_date)
{
	this->_ConstructorID = 1739319039;
	this->id = id;
	this->access_hash = access_hash;
	this->date = date;
	this->admin_id = admin_id;
	this->participant_id = participant_id;
	this->g_a_or_b = g_a_or_b;
	this->key_fingerprint = key_fingerprint;
	this->protocol = protocol;
	this->connection = connection;
	this->alternative_connections = alternative_connections;
	this->start_date = start_date;
}
void PhoneCall::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.WriteLong(this->access_hash);
	Writer.TGWriteDate(this->date);
	Writer.WriteInt(this->admin_id);
	Writer.WriteInt(this->participant_id);
	Writer.TGWriteBytes((unsigned char*)this->g_a_or_b.GetData(), this->g_a_or_b.Num());
	Writer.WriteLong(this->key_fingerprint);
	this->protocol->OnSend(Writer);
	this->connection->OnSend(Writer);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->alternative_connections.Num());
	for(auto X : this->alternative_connections)
	{
	X->OnSend(Writer);
	}
	Writer.TGWriteDate(this->start_date);
}


void PhoneCall::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	access_hash = Reader.ReadLong();
	date = Reader.TGReadDate();
	admin_id = Reader.ReadInt();
	participant_id = Reader.ReadInt();
	g_a_or_b = Reader.TGReadBytes();
	key_fingerprint = Reader.ReadLong();
	protocol = reinterpret_cast<COMMON::PhoneCallProtocol*>(Reader.TGReadObject());
	connection = reinterpret_cast<COMMON::PhoneConnection*>(Reader.TGReadObject());
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len22208 = Reader.ReadInt();
	for(int32 i = 0; i < Len22208; i++)
	{
	auto X = reinterpret_cast<COMMON::PhoneConnection*>(Reader.TGReadObject());
	alternative_connections.Add(X);
	}
	start_date = Reader.TGReadDate();
}
PhoneCall::~PhoneCall()
{

}
}//end namespace block
