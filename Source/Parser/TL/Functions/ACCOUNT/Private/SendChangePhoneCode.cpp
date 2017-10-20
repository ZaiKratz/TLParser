#include "../Public/SendChangePhoneCode.h"


//begin namespace block
namespace ACCOUNT
{

SendChangePhoneCode::SendChangePhoneCode()
{
	this->_ConstructorID = 149257707;
	this->_ContentRelated = true;
}

SendChangePhoneCode::SendChangePhoneCode(bool allow_flashcall, FString phone_number, bool current_number)
{
	this->_ConstructorID = 149257707;
	this->_ContentRelated = true;
	this->allow_flashcall = allow_flashcall;
	this->phone_number = phone_number;
	this->current_number = current_number;
}
void SendChangePhoneCode::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(allow_flashcall)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(current_number)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->phone_number);
	if(this->current_number)
	{
	Writer.WriteBool(this->current_number);
	}
}


void SendChangePhoneCode::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<AUTH::SentCode*>(Reader.TGReadObject());
	this->_Responded = true;
}
SendChangePhoneCode::~SendChangePhoneCode()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
