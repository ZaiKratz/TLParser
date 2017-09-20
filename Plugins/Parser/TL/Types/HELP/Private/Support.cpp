#include "../Public/Support.h"


//begin namespace block
namespace HELP
{

Support::Support()
{
	this->_ConstructorID = -155859433;
}

Support::Support(FString phone_number, COMMON::User* user)
{
	this->_ConstructorID = -155859433;
	this->phone_number = phone_number;
	this->user = user;
}
void Support::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->phone_number);
	this->user->OnSend(Writer);
}


void Support::OnResponce(BinaryReader& Reader)
{
	phone_number = Reader.TGReadString();
	user = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
}
Support::~Support()
{

}
}//end namespace block
