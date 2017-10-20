#include "../Public/RecoverPassword.h"


//begin namespace block
namespace AUTH
{

RecoverPassword::RecoverPassword()
{
	this->_ConstructorID = 1319464594;
	this->_ContentRelated = true;
}

RecoverPassword::RecoverPassword(FString code)
{
	this->_ConstructorID = 1319464594;
	this->_ContentRelated = true;
	this->code = code;
}
void RecoverPassword::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->code);
}


void RecoverPassword::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<AUTH::Authorization*>(Reader.TGReadObject());
	this->_Responded = true;
}
RecoverPassword::~RecoverPassword()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
