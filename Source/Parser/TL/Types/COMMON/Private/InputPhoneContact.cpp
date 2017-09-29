#include "../Public/InputPhoneContact.h"


//begin namespace block
namespace COMMON
{

InputPhoneContact::InputPhoneContact()
{
	this->_ConstructorID = -208488460;
}

InputPhoneContact::InputPhoneContact(unsigned long long client_id, FString phone, FString first_name, FString last_name)
{
	this->_ConstructorID = -208488460;
	this->client_id = client_id;
	this->phone = phone;
	this->first_name = first_name;
	this->last_name = last_name;
}
void InputPhoneContact::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->client_id);
	Writer.TGWriteString(this->phone);
	Writer.TGWriteString(this->first_name);
	Writer.TGWriteString(this->last_name);
}


void InputPhoneContact::OnResponce(BinaryReader& Reader)
{
	client_id = Reader.ReadLong();
	phone = Reader.TGReadString();
	first_name = Reader.TGReadString();
	last_name = Reader.TGReadString();
	this->_Responded = true;
}
InputPhoneContact::~InputPhoneContact()
{

}
}//end namespace block
