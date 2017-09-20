#include "../Public/ResetAuthorization.h"


//begin namespace block
namespace ACCOUNT
{

ResetAuthorization::ResetAuthorization()
{
	this->_ConstructorID = -1124894753;
	this->_ContentRelated = true;
}

ResetAuthorization::ResetAuthorization(unsigned long long hash)
{
	this->_ConstructorID = -1124894753;
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
}
ResetAuthorization::~ResetAuthorization()
{

}
}//end namespace block
