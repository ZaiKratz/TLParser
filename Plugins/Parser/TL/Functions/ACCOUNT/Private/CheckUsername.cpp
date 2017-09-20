#include "../Public/CheckUsername.h"


//begin namespace block
namespace ACCOUNT
{

CheckUsername::CheckUsername()
{
	this->_ConstructorID = 1826100263;
	this->_ContentRelated = true;
}

CheckUsername::CheckUsername(FString username)
{
	this->_ConstructorID = 1826100263;
	this->_ContentRelated = true;
	this->username = username;
}
void CheckUsername::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->username);
}


void CheckUsername::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
}
CheckUsername::~CheckUsername()
{

}
}//end namespace block
