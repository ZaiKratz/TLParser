#include "../Public/MessageMediaContact.h"


//begin namespace block
namespace COMMON
{

MessageMediaContact::MessageMediaContact()
{
	this->_ConstructorID = 1585262393;
}

MessageMediaContact::MessageMediaContact(FString phone_number, FString first_name, FString last_name, int32 user_id)
{
	this->_ConstructorID = 1585262393;
	this->phone_number = phone_number;
	this->first_name = first_name;
	this->last_name = last_name;
	this->user_id = user_id;
}
void MessageMediaContact::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->phone_number);
	Writer.TGWriteString(this->first_name);
	Writer.TGWriteString(this->last_name);
	Writer.WriteInt(this->user_id);
}


void MessageMediaContact::OnResponce(BinaryReader& Reader)
{
	phone_number = Reader.TGReadString();
	first_name = Reader.TGReadString();
	last_name = Reader.TGReadString();
	user_id = Reader.ReadInt();
	this->_Responded = true;
}
MessageMediaContact::~MessageMediaContact()
{
}
}//end namespace block
