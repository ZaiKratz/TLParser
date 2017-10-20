#include "../Public/UpdateEncryption.h"


//begin namespace block
namespace COMMON
{

UpdateEncryption::UpdateEncryption()
{
	this->_ConstructorID = -1264392051;
}

UpdateEncryption::UpdateEncryption(COMMON::EncryptedChat*  chat, FDateTime date)
{
	this->_ConstructorID = -1264392051;
	this->chat = chat;
	this->date = date;
}
void UpdateEncryption::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->chat->OnSend(Writer);
	Writer.TGWriteDate(this->date);
}


void UpdateEncryption::OnResponce(BinaryReader& Reader)
{
	chat = reinterpret_cast<COMMON::EncryptedChat* >(Reader.TGReadObject());
	date = Reader.TGReadDate();
	this->_Responded = true;
}
UpdateEncryption::~UpdateEncryption()
{
	if(this->chat)
	{
		delete this->chat;
	}
}
}//end namespace block
