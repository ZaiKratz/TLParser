#include "../Public/EncryptedChat.h"


//begin namespace block
namespace COMMON
{

EncryptedChat::EncryptedChat()
{
	this->_ConstructorID = -94974410;
}

EncryptedChat::EncryptedChat(int32 id, unsigned long long access_hash, FDateTime date, int32 admin_id, int32 participant_id, TArray<uint8>  g_a_or_b, unsigned long long key_fingerprint)
{
	this->_ConstructorID = -94974410;
	this->id = id;
	this->access_hash = access_hash;
	this->date = date;
	this->admin_id = admin_id;
	this->participant_id = participant_id;
	this->g_a_or_b = g_a_or_b;
	this->key_fingerprint = key_fingerprint;
}
void EncryptedChat::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->id);
	Writer.WriteLong(this->access_hash);
	Writer.TGWriteDate(this->date);
	Writer.WriteInt(this->admin_id);
	Writer.WriteInt(this->participant_id);
	Writer.TGWriteBytes((unsigned char*)this->g_a_or_b.GetData(), this->g_a_or_b.Num());
	Writer.WriteLong(this->key_fingerprint);
}


void EncryptedChat::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadInt();
	access_hash = Reader.ReadLong();
	date = Reader.TGReadDate();
	admin_id = Reader.ReadInt();
	participant_id = Reader.ReadInt();
	g_a_or_b = Reader.TGReadBytes();
	key_fingerprint = Reader.ReadLong();
	this->_Responded = true;
}
EncryptedChat::~EncryptedChat()
{
}
}//end namespace block
