#include "../Public/ResetAuthorization.h"


//begin namespace block
namespace ACCOUNT
{

ResetAuthorization::ResetAuthorization()
{
	this->_ConstructorID = -545786948;
	this->_ContentRelated = true;
}

ResetAuthorization::ResetAuthorization(unsigned long long hash)
{
	this->_ConstructorID = -545786948;
	this->_ContentRelated = true;
	this->hash = hash;
}
void ResetAuthorization::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->hash);
}


void ResetAuthorization::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
ResetAuthorization::~ResetAuthorization()
{

}
}//end namespace block
