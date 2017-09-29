#include "../Public/GetAuthorizations.h"


//begin namespace block
namespace ACCOUNT
{

GetAuthorizations::GetAuthorizations()
{
	this->_ConstructorID = -484392616;
	this->_ContentRelated = true;
}
void GetAuthorizations::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetAuthorizations::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<ACCOUNT::Authorizations*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetAuthorizations::~GetAuthorizations()
{

}
}//end namespace block
