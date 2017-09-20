#include "../Public/UpdateEncryptedMessagesRead.h"


//begin namespace block
namespace COMMON
{

UpdateEncryptedMessagesRead::UpdateEncryptedMessagesRead()
{
	this->_ConstructorID = -1222246856;
}

UpdateEncryptedMessagesRead::UpdateEncryptedMessagesRead(int32 chat_id, FDateTime max_date, FDateTime date)
{
	this->_ConstructorID = -1222246856;
	this->chat_id = chat_id;
	this->max_date = max_date;
	this->date = date;
}
void UpdateEncryptedMessagesRead::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
	Writer.TGWriteDate(this->max_date);
	Writer.TGWriteDate(this->date);
}


void UpdateEncryptedMessagesRead::OnResponce(BinaryReader& Reader)
{
	chat_id = Reader.ReadInt();
	max_date = Reader.TGReadDate();
	date = Reader.TGReadDate();
}
UpdateEncryptedMessagesRead::~UpdateEncryptedMessagesRead()
{

}
}//end namespace block
