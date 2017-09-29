#include "../Public/SentCode.h"


//begin namespace block
namespace AUTH
{

SentCode::SentCode()
{
	this->_ConstructorID = 1577067778;
}

SentCode::SentCode(bool phone_registered, PRIVATE::SentCodeType*  type, FString phone_code_hash, PRIVATE::CodeType*  next_type, int32 timeout)
{
	this->_ConstructorID = 1577067778;
	this->phone_registered = phone_registered;
	this->type = type;
	this->phone_code_hash = phone_code_hash;
	this->next_type = next_type;
	this->timeout = timeout;
}
void SentCode::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(phone_registered)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(next_type)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(timeout)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->type->OnSend(Writer);
	Writer.TGWriteString(this->phone_code_hash);
	if(!this->next_type)
	{
	this->next_type->OnSend(Writer);
	}
	if(!this->timeout)
	{
	Writer.WriteInt(this->timeout);
	}
}


void SentCode::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		phone_registered = true;
	}
	type = reinterpret_cast<PRIVATE::SentCodeType* >(Reader.TGReadObject());
	phone_code_hash = Reader.TGReadString();
	if((Flags & (1 << 1)) != 0) 
	{
	next_type = reinterpret_cast<PRIVATE::CodeType* >(Reader.TGReadObject());
	}
	if((Flags & (1 << 2)) != 0) 
	{
	timeout = Reader.ReadInt();
	}
	this->_Responded = true;
}
SentCode::~SentCode()
{

}
}//end namespace block
