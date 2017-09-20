#include "../Public/ResetAuthorizations.h"


//begin namespace block
namespace AUTH
{

ResetAuthorizations::ResetAuthorizations()
{
	this->_ConstructorID = 437103519;
	this->_ContentRelated = true;
}
void ResetAuthorizations::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void ResetAuthorizations::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
}
ResetAuthorizations::~ResetAuthorizations()
{

}
}//end namespace block
