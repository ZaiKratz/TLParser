#include "../Public/SignIn.h"


//begin namespace block
namespace AUTH
{

SignIn::SignIn()
{
	this->_ConstructorID = -1126886015;
	this->_ContentRelated = true;
}

SignIn::SignIn(FString phone_number, FString phone_code_hash, FString phone_code)
{
	this->_ConstructorID = -1126886015;
	this->_ContentRelated = true;
	this->phone_number = phone_number;
	this->phone_code_hash = phone_code_hash;
	this->phone_code = phone_code;
}
void SignIn::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->phone_number);
	Writer.TGWriteString(this->phone_code_hash);
	Writer.TGWriteString(this->phone_code);
}


void SignIn::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<AUTH::Authorization*>(Reader.TGReadObject());
	this->_Responded = true;
}
SignIn::~SignIn()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
