#include "../Public/EncryptedChatRequested.h"


//begin namespace block
namespace COMMON
{

EncryptedChatRequested::EncryptedChatRequested()
{
	this->_ConstructorID = -931638658;
}

EncryptedChatRequested::EncryptedChatRequested(int32 id, unsigned long long access_hash, FDateTime date, int32 admin_id, int32 participant_id, TArray<uint8>  g_a)
{
	this->_ConstructorID = -931638658;
	this->id = id;
	this->access_hash = access_hash;
	this->date = date;
	this->admin_id = admin_id;
	this->participant_id = participant_id;
	this->g_a = g_a;
}
void EncryptedChatRequested::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->id);
	Writer.WriteLong(this->access_hash);
	Writer.TGWriteDate(this->date);
	Writer.WriteInt(this->admin_id);
	Writer.WriteInt(this->participant_id);
	Writer.TGWriteBytes((unsigned char*)this->g_a.GetData(), this->g_a.Num());
}


void EncryptedChatRequested::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadInt();
	access_hash = Reader.ReadLong();
	date = Reader.TGReadDate();
	admin_id = Reader.ReadInt();
	participant_id = Reader.ReadInt();
	g_a = Reader.TGReadBytes();
	this->_Responded = true;
}
EncryptedChatRequested::~EncryptedChatRequested()
{
}
}//end namespace block
