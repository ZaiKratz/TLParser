#include "../Public/SendInvites.h"


//begin namespace block
namespace AUTH
{

SendInvites::SendInvites()
{
	this->_ConstructorID = 1998331287;
	this->_ContentRelated = true;
}

SendInvites::SendInvites(TArray<FString>  phone_numbers, FString message)
{
	this->_ConstructorID = 1998331287;
	this->_ContentRelated = true;
	this->phone_numbers = phone_numbers;
	this->message = message;
}
void SendInvites::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->phone_numbers.Num());
	for(auto X : this->phone_numbers)
	{
	Writer.TGWriteString(X);
	}
	Writer.TGWriteString(this->message);
}


void SendInvites::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
SendInvites::~SendInvites()
{
}
}//end namespace block
