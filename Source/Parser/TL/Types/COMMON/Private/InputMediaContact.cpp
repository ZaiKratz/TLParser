#include "../Public/InputMediaContact.h"


//begin namespace block
namespace COMMON
{

InputMediaContact::InputMediaContact()
{
	this->_ConstructorID = -1494984313;
}

InputMediaContact::InputMediaContact(FString phone_number, FString first_name, FString last_name)
{
	this->_ConstructorID = -1494984313;
	this->phone_number = phone_number;
	this->first_name = first_name;
	this->last_name = last_name;
}
void InputMediaContact::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->phone_number);
	Writer.TGWriteString(this->first_name);
	Writer.TGWriteString(this->last_name);
}


void InputMediaContact::OnResponce(BinaryReader& Reader)
{
	phone_number = Reader.TGReadString();
	first_name = Reader.TGReadString();
	last_name = Reader.TGReadString();
	this->_Responded = true;
}
InputMediaContact::~InputMediaContact()
{
}
}//end namespace block
