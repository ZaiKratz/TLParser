#include "../Public/GetAuthorizations.h"


//begin namespace block
namespace ACCOUNT
{

GetAuthorizations::GetAuthorizations()
{
	this->_ConstructorID = 1489051875;
	this->_ContentRelated = true;
}
void GetAuthorizations::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetAuthorizations::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<ACCOUNT::Authorizations*>(Reader.TGReadObject());
}
GetAuthorizations::~GetAuthorizations()
{

}
}//end namespace block
