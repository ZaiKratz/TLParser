#include "../Public/SignUp.h"


//begin namespace block
namespace AUTH
{

SignUp::SignUp()
{
	this->_ConstructorID = 453408308;
	this->_ContentRelated = true;
}

SignUp::SignUp(FString phone_number, FString phone_code_hash, FString phone_code, FString first_name, FString last_name)
{
	this->_ConstructorID = 453408308;
	this->_ContentRelated = true;
	this->phone_number = phone_number;
	this->phone_code_hash = phone_code_hash;
	this->phone_code = phone_code;
	this->first_name = first_name;
	this->last_name = last_name;
}
void SignUp::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->phone_number);
	Writer.TGWriteString(this->phone_code_hash);
	Writer.TGWriteString(this->phone_code);
	Writer.TGWriteString(this->first_name);
	Writer.TGWriteString(this->last_name);
}


void SignUp::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<AUTH::Authorization*>(Reader.TGReadObject());
	this->_Responded = true;
}
SignUp::~SignUp()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
