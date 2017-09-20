#include "../Public/EncryptedChatWaiting.h"


//begin namespace block
namespace COMMON
{

EncryptedChatWaiting::EncryptedChatWaiting()
{
	this->_ConstructorID = -603719877;
}

EncryptedChatWaiting::EncryptedChatWaiting(int32 id, unsigned long long access_hash, FDateTime date, int32 admin_id, int32 participant_id)
{
	this->_ConstructorID = -603719877;
	this->id = id;
	this->access_hash = access_hash;
	this->date = date;
	this->admin_id = admin_id;
	this->participant_id = participant_id;
}
void EncryptedChatWaiting::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->id);
	Writer.WriteLong(this->access_hash);
	Writer.TGWriteDate(this->date);
	Writer.WriteInt(this->admin_id);
	Writer.WriteInt(this->participant_id);
}


void EncryptedChatWaiting::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadInt();
	access_hash = Reader.ReadLong();
	date = Reader.TGReadDate();
	admin_id = Reader.ReadInt();
	participant_id = Reader.ReadInt();
}
EncryptedChatWaiting::~EncryptedChatWaiting()
{

}
}//end namespace block
