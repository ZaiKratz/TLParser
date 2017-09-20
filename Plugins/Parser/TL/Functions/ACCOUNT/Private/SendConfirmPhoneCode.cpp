#include "../Public/SendConfirmPhoneCode.h"


//begin namespace block
namespace ACCOUNT
{

SendConfirmPhoneCode::SendConfirmPhoneCode()
{
	this->_ConstructorID = -1109977579;
	this->_ContentRelated = true;
}

SendConfirmPhoneCode::SendConfirmPhoneCode(bool allow_flashcall, FString hash, bool current_number)
{
	this->_ConstructorID = -1109977579;
	this->_ContentRelated = true;
	this->allow_flashcall = allow_flashcall;
	this->hash = hash;
	this->current_number = current_number;
}
void SendConfirmPhoneCode::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!allow_flashcall)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!current_number)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->hash);
	if(!this->current_number)
	{
	Writer.WriteBool(this->current_number);
	}
}


void SendConfirmPhoneCode::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<AUTH::SentCode*>(Reader.TGReadObject());
}
SendConfirmPhoneCode::~SendConfirmPhoneCode()
{

}
}//end namespace block
